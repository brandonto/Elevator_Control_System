// {{{RME classifier 'Logical View::Central_Coordinator'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Central_Coordinator.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Central_Coordinator.h>
extern const RTActorClass Local_Controller;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"F_Buttons_IN"
	  , &F_Buttons::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"Service_Modes_IN"
	  , &Service_Modes::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Central_Coordinator_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Central_Coordinator_Actor( _rts, _ref );
}

const RTActorClass Central_Coordinator =
{
	(const RTActorClass *)0
  , "Central_Coordinator"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_Central_Coordinator_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Idle"
};

static const RTInterfaceDescriptor rtg_interfaces_System_Elevators[] =
{
	{
		"Central_IN"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_System_Elevators[] =
{
	{
		0
	  , &Elevator_Request_Protocol::Base::rt_class
	}
};

const RTTypeModifier rtg_tm_Central_Coordinator_Actor_Elevator_List =
{
	RTNumberConstant
  , (NUM_ELEVATORS)
  , 0
};

#define SUPER RTActor

Central_Coordinator_Actor::Central_Coordinator_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, Motor_Saver_Mode( false )
{
}

Central_Coordinator_Actor::~Central_Coordinator_Actor( void )
{
}

// {{{RME operation 'Assign_Floor_Request(int)'
void Central_Coordinator_Actor::Assign_Floor_Request( int floor_req )
{
	// {{{USR
	int req_dir = floor_req % 10; //request direction (up = 1, down = 0)
	int req_floor = floor_req / 10; //request floor

	int req_out = 0; 
	int pri_index = -1;
	int pri_dif = NUM_FLOORS;
	int sec_index = -1;
	int sec_dif = NUM_FLOORS;
	int x;
	int y;
	int z;

	// update information format:
	// index = value % 100;
	// direction = (value % 1000) / 100;
	// current floor = (value % 1000000) / 1000;
	// number in path list = value / 1000000;

	// Emergency Stopped Elevators will have update values of -1. Do not assign to these.

	// Default:
	// Elevator Choice Policy: 	1. empty path list -> pick closest elevator
	//							2. same direction as request -> pick closest elevator
	//							3. different direction as request -> pick shortest path list
	//							4. not servicable

	// Motor Saver Mode:
	// Goal: 	Reduce number of elevators in use by prioritizing elevators that are already moving in the desired direction
	// Effect: 	Reduces the instances where an elevator that isn't moving is made to begin moving
	//
	// Policy:					1. same direction as request -> pick closest elevator
	//							2. empty path list -> pick closest elevator
	//							3. different direction as request -> pick shortest path list
	//							4. not servicable

	if (Motor_Saver_Mode == true){
		goto SameDir;
	}

	// Empty Path Lists
	//
	EmptyPath:

	for (x = 0; x < NUM_ELEVATORS; x++){ 
		if((Elevator_List[x] / 1000000) == 0){
			sec_index = pri_index;
			pri_index = x;
			if (sec_index != -1) { //need two valid elevators to compare
				if ( req_floor < ((Elevator_List[pri_index] % 1000000) / 1000)){
					pri_dif = ((Elevator_List[pri_index] % 1000000) / 1000) - req_floor;
				}else{
					pri_dif = req_floor - ((Elevator_List[pri_index] % 1000000) / 1000);
				}
				if ( req_floor < ((Elevator_List[sec_index] % 1000000) / 1000)){
					sec_dif = ((Elevator_List[sec_index] % 1000000) / 1000) - req_floor;
				}else{
					sec_dif = req_floor - ((Elevator_List[sec_index] % 1000000) / 1000);
				}
				if (pri_dif > sec_dif){    //if sec_index was a better choice, swap it back to primary
					pri_index = sec_index;
					sec_index = x;
				}
			}
		}
	}
	if(pri_index > -1){ //elevator was found to service request
		req_out = req_floor*100 + pri_index; 
		Central_OUT.Add_Floor_Request(req_out).send();
		log.show("Sending Elevator: ");
		log.show(pri_index);
		log.show(" to Floor Requested: ");
		log.show(req_floor);
		log.log("");
		log.show("Request Direction: ");
		log.show(req_dir);
		log.log("");
		return;
	}

	pri_index = -1; // Reset indexes just for the sake of preventing weird behaviour
	sec_index = -1;

	if (Motor_Saver_Mode == true){
		goto OtherDir;
	}

	// Non-Empty Path, Same direction as request (but before the request), smallest path list
	//
	SameDir:

	for (y = 0; y < NUM_ELEVATORS; y++){
		if((Elevator_List[y] / 1000000) != 0){ //not empty path list
			if ( ((Elevator_List[y] % 1000) / 100) == req_dir ){ //same direction
				if ( req_dir == 1 && ((Elevator_List[y] % 1000000) / 1000) < req_floor ){ //going up, elevator underneath request going up
					sec_index = pri_index;
					pri_index = y;
					if (sec_index != -1) { //need two valid elevators to compare
						pri_dif = req_floor - ((Elevator_List[pri_index] % 1000000) / 1000); //diff between request floor and current floor of pri
						sec_dif = req_floor - ((Elevator_List[sec_index] % 1000000) / 1000); //diff between request floor and current floor of sec

						if (pri_dif > sec_dif){    //if sec_index was a better choice, swap it back to primary
							pri_index = sec_index;
							sec_index = y;
						}
					}
				}
				else if( req_dir == 0 && ((Elevator_List[y] % 1000000) / 1000) > req_floor ){ //going down, elevator above request going down
					sec_index = pri_index;
					pri_index = y;
					if (sec_index != -1) { //need two valid elevators to compare
						pri_dif = ((Elevator_List[pri_index] % 1000000) / 1000) - req_floor; //diff between request floor and current floor of pri
						sec_dif = ((Elevator_List[sec_index] % 1000000) / 1000) - req_floor; //diff between request floor and current floor of sec

						if (pri_dif > sec_dif){    //if sec_index was a better choice, swap it back to primary
							pri_index = sec_index;
							sec_index = y;
						}
					}
				}
			}
		}
	}
	if (pri_index > -1){ //elevator was found to service request
		req_out = req_floor*100 + pri_index;
		Central_OUT.Add_Floor_Request(req_out).send();
		log.show("Sending Elevator: ");
		log.show(pri_index);
		log.show(" to Floor Requested: ");
		log.show(req_floor);
		log.log("");
		log.show("Request Direction: ");
		log.show(req_dir);
		log.log("");
		return;
	}

	pri_index = -1; // Reset indexes just for the sake of preventing weird behaviour
	sec_index = -1;

	if (Motor_Saver_Mode == true){
		goto EmptyPath;
	}

	// Non-Empty Path, Different direction as request, > smallest path list <
	//
	OtherDir:

	for (z = 0; z < NUM_ELEVATORS; z++){
		if((Elevator_List[z] / 1000000) != 0){
			if (Elevator_List[z] != -1){ //don't assign to emergency stopped elevators
				sec_index = pri_index;
				pri_index = z;
				if (sec_index != -1){ //need two valid elevators to compare path list length
					if ( (Elevator_List[sec_index] / 1000000) < (Elevator_List[pri_index] / 1000000) ){ //secondary was a better choice, swap
						pri_index = sec_index;
						sec_index = z;
					}
				}
			}
		}
	}			
	if (pri_index > -1){ //elevator was found to service request
		req_out = req_floor*100 + pri_index;
		Central_OUT.Add_Floor_Request(req_out).send();
		log.show("Sending Elevator: ");
		log.show(pri_index);
		log.show(" to Floor Requested: ");
		log.show(req_floor);
		log.log("");
		log.show("Request Direction: ");
		log.show(req_dir);
		log.log("");
		return;
	}

	log.show("Could not find an elevator to service request to floor: ");
	log.show(req_floor);
	log.log("");
	log.log("This is because no elevators matched the assignment rules, probably because none exist, or they are all in EMERGENCY BRAKE state.");

	// }}}USR
}
// }}}RME

int Central_Coordinator_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// F_Buttons_IN
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &F_Buttons_IN;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// Service_Modes_IN
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Service_Modes_IN;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int Central_Coordinator_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// System_Elevators
		switch( rtg_portId )
		{
		case 0:
			// Central_IN
			if( rtg_repIndex < 2 )
			{
				// Central_OUT
				rtg_end.port = &Central_OUT;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
	return RTActor::_followOutV( rtg_end, rtg_compId, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void Central_Coordinator_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	for (int x = 0; x < NUM_ELEVATORS; x++){
		Elevator_List[x] = 0;
	}
	log.show("Elevator Service Mode: ");
	if (Motor_Saver_Mode == true){
		log.show(" MOTOR SAVER MODE");
	}else{
	log.show(" DEFAULT MODE");
	}
	log.log("");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J51599FFE01E8:Handle_Request'
INLINE_METHODS void Central_Coordinator_Actor::transition2_Handle_Request( const int * rtdata, F_Buttons::Base * rtport )
{
	// {{{USR
	int floor_req = *rtdata;

	int req_dir = floor_req % 10; //request direction (up = 1, down = 0)
	int req_floor = floor_req / 10; //request floor

	if ((req_floor >= 0 && req_floor < NUM_FLOORS) && (req_dir == 0 || req_dir == 1)){ //valid request
		if (req_floor == 0 && req_dir == 0){
			log.log("Invalid Floor Request: Request down at bottom floor");
			goto invalid;
		}
		if (req_floor == (NUM_FLOORS-1) && req_dir == 1){
			log.log("Invalid Floor Request: Request up at top floor");
			goto invalid;
		}
		Assign_Floor_Request(floor_req);
	}

	invalid: 
	//invalid request (because of trying to go down at bottom floor or up at top floor)
	floor_req = 0;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J51608D720180:Update_Elevator_Info'
INLINE_METHODS void Central_Coordinator_Actor::transition3_Update_Elevator_Info( const int * rtdata, Elevator_Request_Protocol::Base * rtport )
{
	// {{{USR
	int update_value = *rtdata;
	int u_index;

	if(update_value == -1){
		log.show("EMERGENCY BRAKE: Elevator is in emergency brake state!");
		log.log("");
	}else if(update_value > -1){
		u_index = update_value % 100; //get index of updating elevator
		Elevator_List[u_index] = update_value; //assign list at index to update value
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J5160C6CC023C:Change_Service_Mode'
INLINE_METHODS void Central_Coordinator_Actor::transition4_Change_Service_Mode( const void * rtdata, Service_Modes::Base * rtport )
{
	// {{{USR
	if (Motor_Saver_Mode == true){
		log.log("Elevator Service Mode:  DEFAULT MODE");
		Motor_Saver_Mode = false;
	}else if (Motor_Saver_Mode == false){
		log.log("Elevator Service Mode:  MOTOR SAVER MODE");
		Motor_Saver_Mode = true;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Central_Coordinator_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Central_Coordinator_Actor::chain3_Update_Elevator_Info( void )
{
	// transition ':TOP:Idle:J51608D720180:Update_Elevator_Info'
	rtgChainBegin( 2, "Update_Elevator_Info" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_Update_Elevator_Info( (const int *)msg->data, (Elevator_Request_Protocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Central_Coordinator_Actor::chain2_Handle_Request( void )
{
	// transition ':TOP:Idle:J51599FFE01E8:Handle_Request'
	rtgChainBegin( 2, "Handle_Request" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_Handle_Request( (const int *)msg->data, (F_Buttons::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Central_Coordinator_Actor::chain4_Change_Service_Mode( void )
{
	// transition ':TOP:Idle:J5160C6CC023C:Change_Service_Mode'
	rtgChainBegin( 2, "Change_Service_Mode" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_Change_Service_Mode( msg->data, (Service_Modes::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Central_Coordinator_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; stateIndex = rtg_parent_state[ stateIndex - 1 ] )
		switch( stateIndex )
		{
		case 1:
			// {{{RME state ':TOP'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					chain1_Initial();
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			//unexpectedMessage();
			return;
			// }}}RME
		case 2:
			// {{{RME state ':TOP:Idle'
			switch( portIndex )
			{
			case 0:
				switch( signalIndex )
				{
				case 1:
					return;
				default:
					break;
				}
				break;
			case 2:
				// {{{RME port 'Central_OUT'
				switch( signalIndex )
				{
				case Elevator_Request_Protocol::Base::rti_Update_Information:
					chain3_Update_Elevator_Info();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'F_Buttons_IN'
				switch( signalIndex )
				{
				case F_Buttons::Base::rti_F_Button_Pressed:
					chain2_Handle_Request();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'Service_Modes_IN'
				switch( signalIndex )
				{
				case Service_Modes::Base::rti_Swap_Modes:
					chain4_Change_Service_Mode();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			default:
				break;
			}
			break;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * Central_Coordinator_Actor::getActorData( void ) const
{
	return &Central_Coordinator_Actor::rtg_class;
}

const RTActor_class Central_Coordinator_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Central_Coordinator_Actor::rtg_parent_state
  , &Central_Coordinator
  , 1
  , Central_Coordinator_Actor::rtg_capsule_roles
  , 4
  , Central_Coordinator_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 2
  , Central_Coordinator_Actor::rtg_Central_Coordinator_fields
};

const RTStateId Central_Coordinator_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor Central_Coordinator_Actor::rtg_capsule_roles[] =
{
	{
		"System_Elevators"
	  , &Local_Controller
	  , RTOffsetOf( Central_Coordinator_Actor, System_Elevators )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 2 // cardinality
	  , 1
	  , rtg_interfaces_System_Elevators
	  , 1
	  , rtg_bindings_System_Elevators
	}
};

const RTPortDescriptor Central_Coordinator_Actor::rtg_ports[] =
{
	{
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Central_Coordinator_Actor, Central_Coordinator_Actor::log )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Central_OUT"
	  , (const char *)0
	  , &Elevator_Request_Protocol::Base::rt_class
	  , RTOffsetOf( Central_Coordinator_Actor, Central_Coordinator_Actor::Central_OUT )
	  , 2 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"F_Buttons_IN"
	  , (const char *)0
	  , &F_Buttons::Base::rt_class
	  , RTOffsetOf( Central_Coordinator_Actor, Central_Coordinator_Actor::F_Buttons_IN )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"Service_Modes_IN"
	  , (const char *)0
	  , &Service_Modes::Base::rt_class
	  , RTOffsetOf( Central_Coordinator_Actor, Central_Coordinator_Actor::Service_Modes_IN )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor Central_Coordinator_Actor::rtg_Central_Coordinator_fields[] =
{
	// {{{RME classAttribute 'Elevator_List'
	{
		"Elevator_List"
	  , RTOffsetOf( Central_Coordinator_Actor, Elevator_List[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_Central_Coordinator_Actor_Elevator_List
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Motor_Saver_Mode'
  , {
		"Motor_Saver_Mode"
	  , RTOffsetOf( Central_Coordinator_Actor, Motor_Saver_Mode )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
