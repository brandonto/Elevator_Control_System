// {{{RME classifier 'Logical View::Elevator_Buttons'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Elevator_Buttons.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Elevator_Buttons.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"Elevator_Request_Line_IN"
	  , &Elevator_Request_Protocol::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"Buttons_IN"
	  , &E_Buttons::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Elevator_Buttons_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Elevator_Buttons_Actor( _rts, _ref );
}

const RTActorClass Elevator_Buttons =
{
	(const RTActorClass *)0
  , "Elevator_Buttons"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_Elevator_Buttons_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Idle"
};

#define SUPER RTActor

Elevator_Buttons_Actor::Elevator_Buttons_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Elevator_Buttons_Actor::~Elevator_Buttons_Actor( void )
{
}

int Elevator_Buttons_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// Elevator_Request_Line_IN
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Elevator_Request_Line_IN;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// Buttons_IN
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Buttons_IN;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Idle:J51575363012B:Handle_Button_Press'
INLINE_METHODS void Elevator_Buttons_Actor::transition2_Handle_Button_Press( const int * rtdata, E_Buttons::Base * rtport )
{
	// {{{USR
	// Send Data to Elevator if it's valid

	int data = *rtdata;

	if (data >= 0 && data < NUM_FLOORS){ //throw out invalid buttons
		Elevator_Request_Line_IN.Add_Floor_Request(data).send();
	}
		
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Idle:J5160B37C01A0:Open_Doors_Button'
INLINE_METHODS void Elevator_Buttons_Actor::transition3_Open_Doors_Button( const void * rtdata, E_Buttons::Base * rtport )
{
	// {{{USR
	Elevator_Request_Line_IN.Open_Doors().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Elevator_Buttons_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Buttons_Actor::chain2_Handle_Button_Press( void )
{
	// transition ':TOP:Idle:J51575363012B:Handle_Button_Press'
	rtgChainBegin( 2, "Handle_Button_Press" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_Handle_Button_Press( (const int *)msg->data, (E_Buttons::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Buttons_Actor::chain3_Open_Doors_Button( void )
{
	// transition ':TOP:Idle:J5160B37C01A0:Open_Doors_Button'
	rtgChainBegin( 2, "Open_Doors_Button" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_Open_Doors_Button( msg->data, (E_Buttons::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Elevator_Buttons_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'Buttons_IN'
				switch( signalIndex )
				{
				case E_Buttons::Base::rti_Button_Pressed:
					chain2_Handle_Button_Press();
					return;
				case E_Buttons::Base::rti_Door_Open_Pressed:
					chain3_Open_Doors_Button();
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

const RTActor_class * Elevator_Buttons_Actor::getActorData( void ) const
{
	return &Elevator_Buttons_Actor::rtg_class;
}

const RTActor_class Elevator_Buttons_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Elevator_Buttons_Actor::rtg_parent_state
  , &Elevator_Buttons
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , Elevator_Buttons_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId Elevator_Buttons_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor Elevator_Buttons_Actor::rtg_ports[] =
{
	{
		"Elevator_Request_Line_IN"
	  , (const char *)0
	  , &Elevator_Request_Protocol::Base::rt_class
	  , RTOffsetOf( Elevator_Buttons_Actor, Elevator_Buttons_Actor::Elevator_Request_Line_IN )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"Buttons_IN"
	  , (const char *)0
	  , &E_Buttons::Base::rt_class
	  , RTOffsetOf( Elevator_Buttons_Actor, Elevator_Buttons_Actor::Buttons_IN )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
