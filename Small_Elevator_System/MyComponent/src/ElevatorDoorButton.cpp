// {{{RME classifier 'Logical View::ElevatorDoorButton'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ElevatorDoorButton.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ElevatorDoorButton.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"LEDBPort"
	  , &LEDBProtocol::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"UEDBPort"
	  , &UEDBProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ElevatorDoorButton_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ElevatorDoorButton_Actor( _rts, _ref );
}

const RTActorClass ElevatorDoorButton =
{
	(const RTActorClass *)0
  , "ElevatorDoorButton"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_ElevatorDoorButton_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
};

#define SUPER RTActor

ElevatorDoorButton_Actor::ElevatorDoorButton_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ElevatorDoorButton_Actor::~ElevatorDoorButton_Actor( void )
{
}

int ElevatorDoorButton_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// LEDBPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &LEDBPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// UEDBPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &UEDBPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void ElevatorDoorButton_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	id = getIndex();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FC57C700E6:doorButtonPressed'
INLINE_METHODS void ElevatorDoorButton_Actor::transition2_doorButtonPressed( const void * rtdata, UEDBProtocol::Base * rtport )
{
	// {{{USR
	LEDBPort.doorButtonPressed(id).send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ElevatorDoorButton_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorDoorButton_Actor::chain2_doorButtonPressed( void )
{
	// transition ':TOP:Ready:J56FC57C700E6:doorButtonPressed'
	rtgChainBegin( 2, "doorButtonPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_doorButtonPressed( msg->data, (UEDBProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void ElevatorDoorButton_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			unexpectedMessage();
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
				// {{{RME port 'UEDBPort'
				switch( signalIndex )
				{
				case UEDBProtocol::Base::rti_pressElevatorButton:
					chain2_doorButtonPressed();
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

const RTActor_class * ElevatorDoorButton_Actor::getActorData( void ) const
{
	return &ElevatorDoorButton_Actor::rtg_class;
}

const RTActor_class ElevatorDoorButton_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , ElevatorDoorButton_Actor::rtg_parent_state
  , &ElevatorDoorButton
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , ElevatorDoorButton_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , ElevatorDoorButton_Actor::rtg_ElevatorDoorButton_fields
};

const RTStateId ElevatorDoorButton_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor ElevatorDoorButton_Actor::rtg_ports[] =
{
	{
		"LEDBPort"
	  , (const char *)0
	  , &LEDBProtocol::Base::rt_class
	  , RTOffsetOf( ElevatorDoorButton_Actor, ElevatorDoorButton_Actor::LEDBPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"UEDBPort"
	  , (const char *)0
	  , &UEDBProtocol::Base::rt_class
	  , RTOffsetOf( ElevatorDoorButton_Actor, ElevatorDoorButton_Actor::UEDBPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor ElevatorDoorButton_Actor::rtg_ElevatorDoorButton_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( ElevatorDoorButton_Actor, id )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
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
