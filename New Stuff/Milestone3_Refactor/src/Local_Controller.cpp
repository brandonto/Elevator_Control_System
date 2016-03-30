// {{{RME classifier 'Logical View::Local_Controller'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Local_Controller.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Local_Controller.h>
#include <Elevator.h>
extern const RTActorClass Elevator_Buttons;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"Central_IN"
	  , &Elevator_Request_Protocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Local_Controller_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Local_Controller_Actor( _rts, _ref );
}

const RTActorClass Local_Controller =
{
	(const RTActorClass *)0
  , "Local_Controller"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_Local_Controller_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
};

static const RTInterfaceDescriptor rtg_interfaces_Elevator_Buttons_Handler[] =
{
	{
		"Elevator_Request_Line_IN"
	  , 1
	}
  , {
		"Buttons_IN"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_Elevator_Buttons_Handler[] =
{
	{
		0
	  , &Elevator_Request_Protocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_elevator_body[] =
{
	{
		"Elevator_Test"
	  , 0
	}
  , {
		"Elevator_Internals_IN"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_elevator_body[] =
{
	{
		1
	  , &Elevator_Internals::Base::rt_class
	}
};

const RTTypeModifier rtg_tm_Local_Controller_Actor_Path_List =
{
	RTNumberConstant
  , (NUM_FLOORS)
  , 0
};

#define SUPER RTActor

Local_Controller_Actor::Local_Controller_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, Current_Floor( 0 )
	, Floors_in_Path( 0 )
	, Direction_of_Travel( 1 )
	, Elevator_Index( 0 )
	, E_Brake( false )
{
}

Local_Controller_Actor::~Local_Controller_Actor( void )
{
}

// {{{RME operation 'Add_Floor_Request(int)'
void Local_Controller_Actor::Add_Floor_Request( int Floor_Number )
{
	// {{{USR
	for (int x = 0; x < NUM_FLOORS; x++){
		if (Path_List[x] == Floor_Number){
			return; //Floor already in Path list
		}
	}
	//Floor not in path list
	//Add it to next open spot in path list
	for (int y = 0; y < NUM_FLOORS; y++){
		if (Path_List[y] == -1){
			Path_List[y] = Floor_Number;
			break;
		}
	}
	Floors_in_Path += 1;

	 
	// }}}USR
}
// }}}RME

// {{{RME operation 'Order_Path()'
void Local_Controller_Actor::Order_Path( void )
{
	// {{{USR

	int correct_direction_floors [NUM_FLOORS];
	int correct_direction_floors_num;
	int wrong_direction_floors [NUM_FLOORS];
	int wrong_direction_floors_num;
	int best_next_floor = -1;

	restart: // if direction of travel needs to be changed, this function will do that and restart

	correct_direction_floors_num = 0;
	wrong_direction_floors_num = 0;

	if (Direction_of_Travel == 1){ //sort for moving up
		for (int x = 0; x < NUM_FLOORS; x++){
			if (Path_List[x] >= 0 && Path_List[x] > Current_Floor){
				correct_direction_floors[correct_direction_floors_num] = Path_List[x];
				correct_direction_floors_num += 1;
			}
			else if(Path_List[x] >= 0 && Path_List[x] < Current_Floor){
				wrong_direction_floors[wrong_direction_floors_num] = Path_List[x];
				wrong_direction_floors_num += 1;
			}
		}
		log.show("Direction of travel up.  Number of relevant floors: ");
		log.show(correct_direction_floors_num);
		log.log("");
		log.show("Direction of travel up.  Number of irelevant floors: ");
		log.show(wrong_direction_floors_num);
		log.log("");
	}
	else if (Direction_of_Travel == 0){ //sort for moving down
		for (int y = 0; y < NUM_FLOORS; y++){
			if (Path_List[y] >=0 && Path_List[y] < Current_Floor){
				correct_direction_floors[correct_direction_floors_num] = Path_List[y];
				correct_direction_floors_num += 1;
			}
			else if(Path_List[y] >= 0 && Path_List[y] > Current_Floor){
				wrong_direction_floors[wrong_direction_floors_num] = Path_List[y];
				wrong_direction_floors_num += 1;
			}
		}
		log.show("Direction of travel down.  Number of relevant floors: ");
		log.show(correct_direction_floors_num);
		log.log("");
		log.show("Direction of travel down.  Number of irelevant floors: ");
		log.show(wrong_direction_floors_num);
		log.log("");
	}
	if (correct_direction_floors_num == 0 && wrong_direction_floors_num != 0){			//no relevant floors in current direction, change direction
		if (Direction_of_Travel == 1){
			Direction_of_Travel = 0;
			//Logging
			log.log("Change direction to Down, restarting path ordering");
			goto restart;
			
		}
		else if (Direction_of_Travel == 0){
			Direction_of_Travel = 1;
			//Logging
			log.log("Change direction to Up, restarting path ordering");
			goto restart;
		}
	}else if (correct_direction_floors_num == 0 && wrong_direction_floors_num == 0){
		 //no floors to visit, no change in direction
		log.log("No change in direction, continuing to sorting");
	}

	// Sort the relevant list
	if (Direction_of_Travel == 0){ //sort for moving down
		if (correct_direction_floors_num == 0){
		}else{
			best_next_floor = correct_direction_floors[0];
			for (int v = 0; v < correct_direction_floors_num; v++){ //iterate over relevant
				if (correct_direction_floors[v] > best_next_floor){
					best_next_floor = correct_direction_floors[v]; //new best found
				}
			}
		}
	}
	else if (Direction_of_Travel == 1){ //sort for moving up
		if (correct_direction_floors_num == 0){
		}else{
			best_next_floor = correct_direction_floors[0];
			for (int w = 0; w < correct_direction_floors_num; w++){ //iterate over relevant
				if (correct_direction_floors[w] < best_next_floor){
					best_next_floor = correct_direction_floors[w]; //new best found
				}
			}
		}
	}
	//clear out path list (all requests are still in relevant and irelevant arrays
	Clear_Path_List();

	//add best next floor (next floor to visit)
	Add_Floor_Request(best_next_floor);

	//add the rest of the floors requested back in

	//add in relevant floors (method takes care of duplicates if any)
	for (int r = 0; r < correct_direction_floors_num; r++){
		Add_Floor_Request(correct_direction_floors[r]);
	}
	//add in irelevant floors (method takes care of duplicates if any)
	for (int i = 0; i < wrong_direction_floors_num; i++){
		Add_Floor_Request(wrong_direction_floors[i]);
	}

	log.show("Elevator ");
	log.show(Elevator_Index);
	log.show(" floor Path:");
	for (int j = 0; j < Floors_in_Path; j++) {
		log.show(Path_List[j]);
		log.show(" ");
	}
		log.log("");
	//Done.  Next floor to visit is at Path_List[0], and all previous are back in









				
	// }}}USR
}
// }}}RME

// {{{RME operation 'Clear_Path_List()'
void Local_Controller_Actor::Clear_Path_List( void )
{
	// {{{USR
	Floors_in_Path = 0;
	for (int i = 0; i < NUM_FLOORS; i++){
	Path_List[i] = -1;
	}
	// }}}USR
}
// }}}RME

// {{{RME operation 'Remove_Current_Floor()'
void Local_Controller_Actor::Remove_Current_Floor( void )
{
	// {{{USR
	Path_List[0] = Path_List[1];
	Path_List[1] = -1;
	// }}}USR
}
// }}}RME

int Local_Controller_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// Central_IN
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Central_IN;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int Local_Controller_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// Elevator_Buttons_Handler
		switch( rtg_portId )
		{
		case 0:
			// Elevator_Request_Line_IN
			if( rtg_repIndex < 1 )
			{
				// Elevator_Request_Line_OUT
				rtg_end.port = &Elevator_Request_Line_OUT;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// elevator_body
		switch( rtg_portId )
		{
		case 1:
			// Elevator_Internals_IN
			if( rtg_repIndex < 1 )
			{
				// Elevator_Internals_OUT
				rtg_end.port = &Elevator_Internals_OUT;
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
INLINE_METHODS void Local_Controller_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	Clear_Path_List();

	Elevator_Index = getIndex();

	RTTimespec Update_Time (0,500000000); //500 milliseconds
	Updater.informEvery (Update_Time);

	log.show("Elevator created with index: ");
	log.show(Elevator_Index);
	log.log("");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J5160971603E1:Handle_Floor_Request_Internal'
INLINE_METHODS void Local_Controller_Actor::transition2_Handle_Floor_Request_Internal( const int * rtdata, Elevator_Request_Protocol::Conjugate * rtport )
{
	// {{{USR
	int new_req = *rtdata;
	if (E_Brake != true){
		Add_Floor_Request(new_req);
		Order_Path();
		Elevator_Internals_OUT.New_Target(Path_List[0]).send();
	}

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51587D6D03E5:Arrive_at_Floor'
INLINE_METHODS void Local_Controller_Actor::transition3_Arrive_at_Floor( const void * rtdata, Elevator_Internals::Base * rtport )
{
	// {{{USR
	log.show("Elevator arrived at target floor: ");
	log.show(Current_Floor);
	log.log("");
	Remove_Current_Floor();
	Order_Path();
	Elevator_Internals_OUT.New_Target(Path_List[0]).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51587F200387:New_Current_Floor'
INLINE_METHODS void Local_Controller_Actor::transition4_New_Current_Floor( const int * rtdata, Elevator_Internals::Base * rtport )
{
	// {{{USR
	int new_cur = *rtdata;
	Current_Floor = new_cur;
	log.show("Elevator ");
	log.show(Elevator_Index);
	log.show(" at floor: ");
	log.show(Current_Floor);
	log.log("");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J51608853014E:Update'
INLINE_METHODS void Local_Controller_Actor::transition5_Update( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	int update_value = 0;

	update_value = Elevator_Index + (Direction_of_Travel * 100) + (Current_Floor * 1000) + (Floors_in_Path * 1000000);

	if(E_Brake == true){
		update_value = -1;
	}

	Central_IN.Update_Information(update_value).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J5160972300D3:Handle_Floor_Request_External'
INLINE_METHODS void Local_Controller_Actor::transition6_Handle_Floor_Request_External( const int * rtdata, Elevator_Request_Protocol::Conjugate * rtport )
{
	// {{{USR
	int new_req = *rtdata;
	int e_index;
	int e_floor;

	if (E_Brake != true){

		e_index = new_req % 100; //first two digits are elevator index (max 100 elevators)
		e_floor = new_req / 100; //any other digits are floor to visit (no max floor number)
								 //e_floor is truncated to an integer, so the index part is removed
		if (e_index == Elevator_Index){
			if (e_floor == Current_Floor && Floors_in_Path == 0){ //request is current floor, not moving
				Elevator_Internals_OUT.Open_Doors().send();
			}
			else{
				Add_Floor_Request(e_floor);
				Order_Path();
				Elevator_Internals_OUT.New_Target(Path_List[0]).send();
			}
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J5160B140001E:E_BRAKE'
INLINE_METHODS void Local_Controller_Actor::transition7_E_BRAKE( const void * rtdata, Elevator_Internals::Base * rtport )
{
	// {{{USR
	E_Brake = true;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J5160B3F103C1:Open_Doors'
INLINE_METHODS void Local_Controller_Actor::transition8_Open_Doors( const void * rtdata, Elevator_Request_Protocol::Conjugate * rtport )
{
	// {{{USR
	Elevator_Internals_OUT.Open_Doors().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Local_Controller_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Local_Controller_Actor::chain5_Update( void )
{
	// transition ':TOP:Ready:J51608853014E:Update'
	rtgChainBegin( 2, "Update" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_Update( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Local_Controller_Actor::chain2_Handle_Floor_Request_Internal( void )
{
	// transition ':TOP:Ready:J5160971603E1:Handle_Floor_Request_Internal'
	rtgChainBegin( 2, "Handle_Floor_Request_Internal" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_Handle_Floor_Request_Internal( (const int *)msg->data, (Elevator_Request_Protocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Local_Controller_Actor::chain8_Open_Doors( void )
{
	// transition ':TOP:Ready:J5160B3F103C1:Open_Doors'
	rtgChainBegin( 2, "Open_Doors" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_Open_Doors( msg->data, (Elevator_Request_Protocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Local_Controller_Actor::chain6_Handle_Floor_Request_External( void )
{
	// transition ':TOP:Ready:J5160972300D3:Handle_Floor_Request_External'
	rtgChainBegin( 2, "Handle_Floor_Request_External" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_Handle_Floor_Request_External( (const int *)msg->data, (Elevator_Request_Protocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Local_Controller_Actor::chain3_Arrive_at_Floor( void )
{
	// transition ':TOP:Ready:J51587D6D03E5:Arrive_at_Floor'
	rtgChainBegin( 2, "Arrive_at_Floor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_Arrive_at_Floor( msg->data, (Elevator_Internals::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Local_Controller_Actor::chain4_New_Current_Floor( void )
{
	// transition ':TOP:Ready:J51587F200387:New_Current_Floor'
	rtgChainBegin( 2, "New_Current_Floor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_New_Current_Floor( (const int *)msg->data, (Elevator_Internals::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Local_Controller_Actor::chain7_E_BRAKE( void )
{
	// transition ':TOP:Ready:J5160B140001E:E_BRAKE'
	rtgChainBegin( 2, "E_BRAKE" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_E_BRAKE( msg->data, (Elevator_Internals::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Local_Controller_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			////unexpectedMessage();
			return;
			// }}}RME
		case 2:
			// {{{RME state ':TOP:Ready'
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
				// {{{RME port 'Updater'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain5_Update();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'Elevator_Request_Line_OUT'
				switch( signalIndex )
				{
				case Elevator_Request_Protocol::Conjugate::rti_Add_Floor_Request:
					chain2_Handle_Floor_Request_Internal();
					return;
				case Elevator_Request_Protocol::Conjugate::rti_Open_Doors:
					chain8_Open_Doors();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'Central_IN'
				switch( signalIndex )
				{
				case Elevator_Request_Protocol::Conjugate::rti_Add_Floor_Request:
					chain6_Handle_Floor_Request_External();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 5:
				// {{{RME port 'Elevator_Internals_OUT'
				switch( signalIndex )
				{
				case Elevator_Internals::Base::rti_Arrived_Target:
					chain3_Arrive_at_Floor();
					return;
				case Elevator_Internals::Base::rti_New_Current_Floor:
					chain4_New_Current_Floor();
					return;
				case Elevator_Internals::Base::rti_E_Brake_Engaged:
					chain7_E_BRAKE();
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

const RTActor_class * Local_Controller_Actor::getActorData( void ) const
{
	return &Local_Controller_Actor::rtg_class;
}

const RTActor_class Local_Controller_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Local_Controller_Actor::rtg_parent_state
  , &Local_Controller
  , 2
  , Local_Controller_Actor::rtg_capsule_roles
  , 5
  , Local_Controller_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 6
  , Local_Controller_Actor::rtg_Local_Controller_fields
};

const RTStateId Local_Controller_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor Local_Controller_Actor::rtg_capsule_roles[] =
{
	{
		"Elevator_Buttons_Handler"
	  , &Elevator_Buttons
	  , RTOffsetOf( Local_Controller_Actor, Elevator_Buttons_Handler )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_Elevator_Buttons_Handler
	  , 1
	  , rtg_bindings_Elevator_Buttons_Handler
	}
  , {
		"elevator_body"
	  , &Elevator
	  , RTOffsetOf( Local_Controller_Actor, elevator_body )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_elevator_body
	  , 1
	  , rtg_bindings_elevator_body
	}
};

const RTPortDescriptor Local_Controller_Actor::rtg_ports[] =
{
	{
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Local_Controller_Actor, Local_Controller_Actor::log )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Updater"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( Local_Controller_Actor, Local_Controller_Actor::Updater )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Elevator_Request_Line_OUT"
	  , (const char *)0
	  , &Elevator_Request_Protocol::Conjugate::rt_class
	  , RTOffsetOf( Local_Controller_Actor, Local_Controller_Actor::Elevator_Request_Line_OUT )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Central_IN"
	  , (const char *)0
	  , &Elevator_Request_Protocol::Conjugate::rt_class
	  , RTOffsetOf( Local_Controller_Actor, Local_Controller_Actor::Central_IN )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"Elevator_Internals_OUT"
	  , (const char *)0
	  , &Elevator_Internals::Base::rt_class
	  , RTOffsetOf( Local_Controller_Actor, Local_Controller_Actor::Elevator_Internals_OUT )
	  , 1 // cardinality
	  , 5
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor Local_Controller_Actor::rtg_Local_Controller_fields[] =
{
	// {{{RME classAttribute 'Path_List'
	{
		"Path_List"
	  , RTOffsetOf( Local_Controller_Actor, Path_List[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_Local_Controller_Actor_Path_List
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Current_Floor'
  , {
		"Current_Floor"
	  , RTOffsetOf( Local_Controller_Actor, Current_Floor )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Floors_in_Path'
  , {
		"Floors_in_Path"
	  , RTOffsetOf( Local_Controller_Actor, Floors_in_Path )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Direction_of_Travel'
  , {
		"Direction_of_Travel"
	  , RTOffsetOf( Local_Controller_Actor, Direction_of_Travel )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Elevator_Index'
  , {
		"Elevator_Index"
	  , RTOffsetOf( Local_Controller_Actor, Elevator_Index )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'E_Brake'
  , {
		"E_Brake"
	  , RTOffsetOf( Local_Controller_Actor, E_Brake )
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
