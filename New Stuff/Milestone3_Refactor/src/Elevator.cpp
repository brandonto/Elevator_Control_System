// {{{RME classifier 'Logical View::Elevator'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Elevator.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Elevator.h>
extern const RTActorClass Door;
extern const RTActorClass Motor;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"Elevator_Test"
	  , &Elevator_Test::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"Elevator_Internals_IN"
	  , &Elevator_Internals::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Elevator_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Elevator_Actor( _rts, _ref );
}

const RTActorClass Elevator =
{
	(const RTActorClass *)0
  , "Elevator"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_Elevator_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Stopped"
  , "Moving_Up"
  , "Moving_Down"
  , "Emergency_Stopped"
  , "Doors_Open"
};

static const RTInterfaceDescriptor rtg_interfaces_Elevator_Door[] =
{
	{
		"Door_Test"
	  , 0
	}
  , {
		"Door_IN"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_Elevator_Door[] =
{
	{
		1
	  , &Door_Protocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_Elevator_Motor[] =
{
	{
		"Motor_IN"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_Elevator_Motor[] =
{
	{
		0
	  , &Motor_Protocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

Elevator_Actor::Elevator_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
	, Door_Ack_Wait( false )
	, Target_Floor( 0 )
	, Current_Floor( 0 )
	, Target_Update( false )
{
}

Elevator_Actor::~Elevator_Actor( void )
{
}

int Elevator_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// Elevator_Test
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Elevator_Test;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// Elevator_Internals_IN
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Elevator_Internals_IN;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int Elevator_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// Elevator_Door
		switch( rtg_portId )
		{
		case 1:
			// Door_IN
			if( rtg_repIndex < 1 )
			{
				// Door_OUT
				rtg_end.port = &Door_OUT;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// Elevator_Motor
		switch( rtg_portId )
		{
		case 0:
			// Motor_IN
			if( rtg_repIndex < 1 )
			{
				// Motor_OUT
				rtg_end.port = &Motor_OUT;
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

// {{{RME enter ':TOP:Stopped'
INLINE_METHODS void Elevator_Actor::enter2_Stopped( void )
{
	// {{{USR
	if(Target_Update == false){

		if(Door_Ack_Wait == false)
		{
			Door_OUT.Command_Door_Open(true).send();
			Door_Ack_Wait = true;
			RTTimespec Three_Tenth (1,0);
			WatchDogTimer_ID = WatchDog_Timer.informIn (Three_Tenth);
		}
		else
		{
			Door_Ack_Wait = false;
		}
	}else{
		Target_Update = false;
	}
	// }}}USR
}
// }}}RME

void Elevator_Actor::enterStateV( void )
{
	switch( getCurrentState() )
	{
	case 2:
		enter2_Stopped();
		break;
	case 3:
		enter3_Moving_Up();
		break;
	case 4:
		enter4_Moving_Down();
		break;
	case 5:
		enter5_Emergency_Stopped();
		break;
	default:
		RTActor::enterStateV();
		break;
	}
}

// {{{RME enter ':TOP:Moving_Up'
INLINE_METHODS void Elevator_Actor::enter3_Moving_Up( void )
{
	// {{{USR
	Current_Floor = Current_Floor + 1;
	Elevator_Internals_IN.New_Current_Floor(Current_Floor).send();
	// }}}USR
}
// }}}RME

// {{{RME enter ':TOP:Moving_Down'
INLINE_METHODS void Elevator_Actor::enter4_Moving_Down( void )
{
	// {{{USR
	Current_Floor = Current_Floor - 1;
	Elevator_Internals_IN.New_Current_Floor(Current_Floor).send();
	// }}}USR
}
// }}}RME

// {{{RME enter ':TOP:Emergency_Stopped'
INLINE_METHODS void Elevator_Actor::enter5_Emergency_Stopped( void )
{
	// {{{USR
	Motor_OUT.E_Brake(true).send();
	Elevator_Internals_IN.E_Brake_Engaged().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J51560A4201AB:Door_Open_Ack' guard '1'
INLINE_METHODS int Elevator_Actor::guard1_Door_Open_Ack_event1( const bool * rtdata, Door_Protocol::Conjugate * rtport )
{
	// {{{USR
	if(Door_Ack_Wait == true){
		return true;
	}else{
		return false;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J51560A4201AB:Door_Open_Ack'
INLINE_METHODS void Elevator_Actor::transition1_Door_Open_Ack( const bool * rtdata, Door_Protocol::Conjugate * rtport )
{
	// {{{USR
	WatchDog_Timer.cancelTimer( WatchDogTimer_ID ); 
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J5154C269036D:Moving_Up_A_Floor' guard '1'
INLINE_METHODS int Elevator_Actor::guard2_Moving_Up_A_Floor_event1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	if (Target_Floor > Current_Floor)
	{ return true;
	}
	else
	{ return false;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J5154C269036D:Moving_Up_A_Floor'
INLINE_METHODS void Elevator_Actor::transition2_Moving_Up_A_Floor( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Create a timeout to go off in 2 seconds. (traveling a floor takes 2 seconds)
	RTTimespec Two_Seconds (2, 0);
	TravelTimer_ID = Travel_Timer.informEvery (Two_Seconds);
	Motor_OUT.Start_UP(true).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Up:J5154C2C900FF:Arriving_Up' guard '1'
INLINE_METHODS int Elevator_Actor::guard3_Arriving_Up_event1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	if (Current_Floor == Target_Floor)
	{ return true;
	}
	else
	{ return false;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Up:J5154C2C900FF:Arriving_Up'
INLINE_METHODS void Elevator_Actor::transition3_Arriving_Up( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	Travel_Timer.cancelTimer( TravelTimer_ID ); 
	Motor_OUT.STOP(true).send();
	Elevator_Internals_IN.Arrived_Target().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Up:J5154C5130034:Move_Another_Floor_Up' guard '1'
INLINE_METHODS int Elevator_Actor::guard4_Move_Another_Floor_Up_event1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	if (Current_Floor == Target_Floor)
	{ return false;
	}
	else{
	return true;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J5154C2B00299:Moving_Down_A_Floor' guard '1'
INLINE_METHODS int Elevator_Actor::guard5_Moving_Down_A_Floor_event1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	if (Target_Floor < Current_Floor)
	{ return true;
	}
	else
	{ return false;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J5154C2B00299:Moving_Down_A_Floor'
INLINE_METHODS void Elevator_Actor::transition5_Moving_Down_A_Floor( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Create a timeout to go off in 2 seconds. (traveling a floor takes 2 seconds)
	RTTimespec Two_Seconds (2, 0);
	TravelTimer_ID = Travel_Timer.informEvery (Two_Seconds);
	Motor_OUT.Start_DOWN(true).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Down:J5154C2CB0256:Arriving_Down' guard '1'
INLINE_METHODS int Elevator_Actor::guard6_Arriving_Down_event1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	if (Current_Floor == Target_Floor)
	{ return true;
	}
	else
	{ return false;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Down:J5154C2CB0256:Arriving_Down'
INLINE_METHODS void Elevator_Actor::transition6_Arriving_Down( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	Travel_Timer.cancelTimer( TravelTimer_ID ); 
	Motor_OUT.STOP(true).send();
	Elevator_Internals_IN.Arrived_Target().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Down:J5154C52D0010:Move_Another_Floor_Down' guard '1'
INLINE_METHODS int Elevator_Actor::guard7_Move_Another_Floor_Down_event1( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	if (Current_Floor == Target_Floor)
	{ return false;
	}
	else{
	return true;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J5154C30002FB:E_Brake'
INLINE_METHODS void Elevator_Actor::transition8_E_Brake( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	Departure_Timer.cancelTimer( DepartureTimer_ID ); 
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Up:J5154C36F0145:E_Brake'
INLINE_METHODS void Elevator_Actor::transition9_E_Brake( const bool * rtdata, RTProtocol * rtport )
{
	// {{{USR
	Travel_Timer.cancelTimer( TravelTimer_ID ); 
	Departure_Timer.cancelTimer( DepartureTimer_ID ); 
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Down:J5154C30F01E0:E_Brake'
INLINE_METHODS void Elevator_Actor::transition10_E_Brake( const bool * rtdata, RTProtocol * rtport )
{
	// {{{USR
	Travel_Timer.cancelTimer( TravelTimer_ID ); 
	Departure_Timer.cancelTimer( DepartureTimer_ID ); 
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void Elevator_Actor::transition11_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	RTTimespec Depart_In (1,0);
	DepartureTimer_ID = Departure_Timer.informEvery (Depart_In);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J51587BFB0397:New_Target'
INLINE_METHODS void Elevator_Actor::transition12_New_Target( const int * rtdata, Elevator_Internals::Conjugate * rtport )
{
	// {{{USR
	int new_tar = *rtdata;

	if (new_tar >= 0 && new_tar < NUM_FLOORS){
	Target_Floor = new_tar;
	}

	// fix to keep emergency brake race conditions from happening
	Target_Update = true;

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Up:J51587C4000B8:New_Target'
INLINE_METHODS void Elevator_Actor::transition13_New_Target( const int * rtdata, Elevator_Internals::Conjugate * rtport )
{
	// {{{USR
	int new_tar = *rtdata;

	if (new_tar >= 0 && new_tar < NUM_FLOORS){
	Target_Floor = new_tar;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Moving_Down:J51587C5703D5:New_Target'
INLINE_METHODS void Elevator_Actor::transition14_New_Target( const int * rtdata, Elevator_Internals::Conjugate * rtport )
{
	// {{{USR
	int new_tar = *rtdata;

	if (new_tar >= 0 && new_tar < NUM_FLOORS){
	Target_Floor = new_tar;
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Doors_Open:J515887D70327:New_Target'
INLINE_METHODS void Elevator_Actor::transition16_New_Target( const int * rtdata, Elevator_Internals::Conjugate * rtport )
{
	// {{{USR
	int new_tar = *rtdata;

	if (new_tar >= 0 && new_tar < NUM_FLOORS){
	Target_Floor = new_tar;
	}
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Elevator_Actor::chain11_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition11_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain8_E_Brake( void )
{
	// transition ':TOP:Stopped:J5154C30002FB:E_Brake'
	rtgChainBegin( 2, "E_Brake" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_E_Brake( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void Elevator_Actor::chain2_Moving_Up_A_Floor( void )
{
	// transition ':TOP:Stopped:J5154C269036D:Moving_Up_A_Floor'
	rtgChainBegin( 2, "Moving_Up_A_Floor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_Moving_Up_A_Floor( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Elevator_Actor::chain5_Moving_Down_A_Floor( void )
{
	// transition ':TOP:Stopped:J5154C2B00299:Moving_Down_A_Floor'
	rtgChainBegin( 2, "Moving_Down_A_Floor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_Moving_Down_A_Floor( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Elevator_Actor::chain1_Door_Open_Ack( void )
{
	// transition ':TOP:Stopped:J51560A4201AB:Door_Open_Ack'
	rtgChainBegin( 2, "Door_Open_Ack" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition1_Door_Open_Ack( (const bool *)msg->data, (Door_Protocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

INLINE_CHAINS void Elevator_Actor::chain12_New_Target( void )
{
	// transition ':TOP:Stopped:J51587BFB0397:New_Target'
	rtgChainBegin( 2, "New_Target" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition12_New_Target( (const int *)msg->data, (Elevator_Internals::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain17_Open_Doors( void )
{
	// transition ':TOP:Stopped:J5160B0870013:Open_Doors'
	rtgChainBegin( 2, "Open_Doors" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain3_Arriving_Up( void )
{
	// transition ':TOP:Moving_Up:J5154C2C900FF:Arriving_Up'
	rtgChainBegin( 3, "Arriving_Up" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_Arriving_Up( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain4_Move_Another_Floor_Up( void )
{
	// transition ':TOP:Moving_Up:J5154C5130034:Move_Another_Floor_Up'
	rtgChainBegin( 3, "Move_Another_Floor_Up" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Elevator_Actor::chain9_E_Brake( void )
{
	// transition ':TOP:Moving_Up:J5154C36F0145:E_Brake'
	rtgChainBegin( 3, "E_Brake" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition9_E_Brake( (const bool *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void Elevator_Actor::chain13_New_Target( void )
{
	// transition ':TOP:Moving_Up:J51587C4000B8:New_Target'
	rtgChainBegin( 3, "New_Target" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition13_New_Target( (const int *)msg->data, (Elevator_Internals::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Elevator_Actor::chain6_Arriving_Down( void )
{
	// transition ':TOP:Moving_Down:J5154C2CB0256:Arriving_Down'
	rtgChainBegin( 4, "Arriving_Down" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_Arriving_Down( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain7_Move_Another_Floor_Down( void )
{
	// transition ':TOP:Moving_Down:J5154C52D0010:Move_Another_Floor_Down'
	rtgChainBegin( 4, "Move_Another_Floor_Down" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Elevator_Actor::chain10_E_Brake( void )
{
	// transition ':TOP:Moving_Down:J5154C30F01E0:E_Brake'
	rtgChainBegin( 4, "E_Brake" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition10_E_Brake( (const bool *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void Elevator_Actor::chain14_New_Target( void )
{
	// transition ':TOP:Moving_Down:J51587C5703D5:New_Target'
	rtgChainBegin( 4, "New_Target" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition14_New_Target( (const int *)msg->data, (Elevator_Internals::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Elevator_Actor::chain15_Doors_Closed( void )
{
	// transition ':TOP:Doors_Open:J51588757022D:Doors_Closed'
	rtgChainBegin( 6, "Doors_Closed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain16_New_Target( void )
{
	// transition ':TOP:Doors_Open:J515887D70327:New_Target'
	rtgChainBegin( 6, "New_Target" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition16_New_Target( (const int *)msg->data, (Elevator_Internals::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 6 );
}

void Elevator_Actor::rtsBehavior( int signalIndex, int portIndex )
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
					chain11_Initial();
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
			// {{{RME state ':TOP:Stopped'
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
				// {{{RME port 'WatchDog_Timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain8_E_Brake();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'Departure_Timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					if( guard2_Moving_Up_A_Floor_event1( msg->data, (Timing::Base *)msg->sap() ) )
					{
						chain2_Moving_Up_A_Floor();
						return;
					}
					if( guard5_Moving_Down_A_Floor_event1( msg->data, (Timing::Base *)msg->sap() ) )
					{
						chain5_Moving_Down_A_Floor();
						return;
					}
					break;
				default:
					break;
				}
				break;
				// }}}RME
			case 6:
				// {{{RME port 'Door_OUT'
				switch( signalIndex )
				{
				case Door_Protocol::Conjugate::rti_Doors_Open:
					if( guard1_Door_Open_Ack_event1( (const bool *)msg->data, (Door_Protocol::Conjugate *)msg->sap() ) )
					{
						chain1_Door_Open_Ack();
						return;
					}
					break;
				default:
					break;
				}
				break;
				// }}}RME
			case 8:
				// {{{RME port 'Elevator_Internals_IN'
				switch( signalIndex )
				{
				case Elevator_Internals::Conjugate::rti_New_Target:
					chain12_New_Target();
					return;
				case Elevator_Internals::Conjugate::rti_Open_Doors:
					chain17_Open_Doors();
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
		case 3:
			// {{{RME state ':TOP:Moving_Up'
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
			case 1:
				// {{{RME port 'Travel_Timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					if( guard3_Arriving_Up_event1( msg->data, (Timing::Base *)msg->sap() ) )
					{
						chain3_Arriving_Up();
						return;
					}
					if( guard4_Move_Another_Floor_Up_event1( msg->data, (Timing::Base *)msg->sap() ) )
					{
						chain4_Move_Another_Floor_Up();
						return;
					}
					break;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'Elevator_Test'
				switch( signalIndex )
				{
				case Elevator_Test::Base::rti_TEST_Doors_Open:
					chain9_E_Brake();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 6:
				// {{{RME port 'Door_OUT'
				switch( signalIndex )
				{
				case Door_Protocol::Conjugate::rti_Doors_Open:
					chain9_E_Brake();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 8:
				// {{{RME port 'Elevator_Internals_IN'
				switch( signalIndex )
				{
				case Elevator_Internals::Conjugate::rti_New_Target:
					chain13_New_Target();
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
		case 4:
			// {{{RME state ':TOP:Moving_Down'
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
			case 1:
				// {{{RME port 'Travel_Timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					if( guard6_Arriving_Down_event1( msg->data, (Timing::Base *)msg->sap() ) )
					{
						chain6_Arriving_Down();
						return;
					}
					if( guard7_Move_Another_Floor_Down_event1( msg->data, (Timing::Base *)msg->sap() ) )
					{
						chain7_Move_Another_Floor_Down();
						return;
					}
					break;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'Elevator_Test'
				switch( signalIndex )
				{
				case Elevator_Test::Base::rti_TEST_Doors_Open:
					chain10_E_Brake();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 6:
				// {{{RME port 'Door_OUT'
				switch( signalIndex )
				{
				case Door_Protocol::Conjugate::rti_Doors_Open:
					chain10_E_Brake();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 8:
				// {{{RME port 'Elevator_Internals_IN'
				switch( signalIndex )
				{
				case Elevator_Internals::Conjugate::rti_New_Target:
					chain14_New_Target();
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
		case 5:
			// {{{RME state ':TOP:Emergency_Stopped'
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
			default:
				break;
			}
			break;
			// }}}RME
		case 6:
			// {{{RME state ':TOP:Doors_Open'
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
			case 6:
				// {{{RME port 'Door_OUT'
				switch( signalIndex )
				{
				case Door_Protocol::Conjugate::rti_Doors_Closed:
					chain15_Doors_Closed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 8:
				// {{{RME port 'Elevator_Internals_IN'
				switch( signalIndex )
				{
				case Elevator_Internals::Conjugate::rti_New_Target:
					chain16_New_Target();
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

const RTActor_class * Elevator_Actor::getActorData( void ) const
{
	return &Elevator_Actor::rtg_class;
}

const RTActor_class Elevator_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 6
  , Elevator_Actor::rtg_parent_state
  , &Elevator
  , 2
  , Elevator_Actor::rtg_capsule_roles
  , 8
  , Elevator_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 4
  , Elevator_Actor::rtg_Elevator_fields
};

const RTStateId Elevator_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
  , 1
};

const RTComponentDescriptor Elevator_Actor::rtg_capsule_roles[] =
{
	{
		"Elevator_Door"
	  , &Door
	  , RTOffsetOf( Elevator_Actor, Elevator_Door )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_Elevator_Door
	  , 1
	  , rtg_bindings_Elevator_Door
	}
  , {
		"Elevator_Motor"
	  , &Motor
	  , RTOffsetOf( Elevator_Actor, Elevator_Motor )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_Elevator_Motor
	  , 1
	  , rtg_bindings_Elevator_Motor
	}
};

const RTPortDescriptor Elevator_Actor::rtg_ports[] =
{
	{
		"Travel_Timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::Travel_Timer )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"WatchDog_Timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::WatchDog_Timer )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Elevator_Test"
	  , (const char *)0
	  , &Elevator_Test::Base::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::Elevator_Test )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"Departure_Timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::Departure_Timer )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::log )
	  , 1 // cardinality
	  , 5
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Door_OUT"
	  , (const char *)0
	  , &Door_Protocol::Conjugate::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::Door_OUT )
	  , 1 // cardinality
	  , 6
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Motor_OUT"
	  , (const char *)0
	  , &Motor_Protocol::Conjugate::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::Motor_OUT )
	  , 1 // cardinality
	  , 7
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Elevator_Internals_IN"
	  , (const char *)0
	  , &Elevator_Internals::Conjugate::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::Elevator_Internals_IN )
	  , 1 // cardinality
	  , 8
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor Elevator_Actor::rtg_Elevator_fields[] =
{
	// {{{RME classAttribute 'Door_Ack_Wait'
	{
		"Door_Ack_Wait"
	  , RTOffsetOf( Elevator_Actor, Door_Ack_Wait )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Target_Floor'
  , {
		"Target_Floor"
	  , RTOffsetOf( Elevator_Actor, Target_Floor )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Current_Floor'
  , {
		"Current_Floor"
	  , RTOffsetOf( Elevator_Actor, Current_Floor )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'Target_Update'
  , {
		"Target_Update"
	  , RTOffsetOf( Elevator_Actor, Target_Update )
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
