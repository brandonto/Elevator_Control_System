// {{{RME classifier 'Logical View::ElevatorButton'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ElevatorButton.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ElevatorButton.h>
extern const RTActorClass ElevatorButtonLamp;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"LEBPort"
	  , &LEBProtocol::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"UEBPort"
	  , &UEBProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ElevatorButton_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ElevatorButton_Actor( _rts, _ref );
}

const RTActorClass ElevatorButton =
{
	(const RTActorClass *)0
  , "ElevatorButton"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_ElevatorButton_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Unpressed"
  , "Pressed"
};

static const RTInterfaceDescriptor rtg_interfaces_elevatorButtonLamp[] =
{
	{
		"EBLEBPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_elevatorButtonLamp[] =
{
	{
		0
	  , &EBLEBProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

ElevatorButton_Actor::ElevatorButton_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ElevatorButton_Actor::~ElevatorButton_Actor( void )
{
}

int ElevatorButton_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// LEBPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &LEBPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// UEBPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &UEBPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int ElevatorButton_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// elevatorButtonLamp
		switch( rtg_portId )
		{
		case 0:
			// EBLEBPort
			if( rtg_repIndex < 1 )
			{
				// EBLEBPort
				rtg_end.port = &EBLEBPort;
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
INLINE_METHODS void ElevatorButton_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	id = getIndex();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Unpressed:J56FC3EC6014A:elevatorButtonPressed'
INLINE_METHODS void ElevatorButton_Actor::transition2_elevatorButtonPressed( const void * rtdata, UEBProtocol::Base * rtport )
{
	// {{{USR
	LEBPort.elevatorButtonPressed(id+1).send();
	EBLEBPort.light().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Pressed:J56FC3EED0164:clearButton'
INLINE_METHODS void ElevatorButton_Actor::transition3_clearButton( const void * rtdata, LEBProtocol::Base * rtport )
{
	// {{{USR
	EBLEBPort.unlight().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ElevatorButton_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorButton_Actor::chain5_ignoreClearButton( void )
{
	// transition ':TOP:Unpressed:J56FC4D420199:ignoreClearButton'
	rtgChainBegin( 2, "ignoreClearButton" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorButton_Actor::chain2_elevatorButtonPressed( void )
{
	// transition ':TOP:Unpressed:J56FC3EC6014A:elevatorButtonPressed'
	rtgChainBegin( 2, "elevatorButtonPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_elevatorButtonPressed( msg->data, (UEBProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorButton_Actor::chain3_clearButton( void )
{
	// transition ':TOP:Pressed:J56FC3EED0164:clearButton'
	rtgChainBegin( 3, "clearButton" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_clearButton( msg->data, (LEBProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorButton_Actor::chain4_ignorePress( void )
{
	// transition ':TOP:Pressed:J56FC3F2401F0:ignorePress'
	rtgChainBegin( 3, "ignorePress" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

void ElevatorButton_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Unpressed'
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
				// {{{RME port 'LEBPort'
				switch( signalIndex )
				{
				case LEBProtocol::Base::rti_clearButton:
					chain5_ignoreClearButton();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'UEBPort'
				switch( signalIndex )
				{
				case UEBProtocol::Base::rti_pressElevatorButton:
					chain2_elevatorButtonPressed();
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
			// {{{RME state ':TOP:Pressed'
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
				// {{{RME port 'LEBPort'
				switch( signalIndex )
				{
				case LEBProtocol::Base::rti_clearButton:
					chain3_clearButton();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'UEBPort'
				switch( signalIndex )
				{
				case UEBProtocol::Base::rti_pressElevatorButton:
					chain4_ignorePress();
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

const RTActor_class * ElevatorButton_Actor::getActorData( void ) const
{
	return &ElevatorButton_Actor::rtg_class;
}

const RTActor_class ElevatorButton_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , ElevatorButton_Actor::rtg_parent_state
  , &ElevatorButton
  , 1
  , ElevatorButton_Actor::rtg_capsule_roles
  , 3
  , ElevatorButton_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , ElevatorButton_Actor::rtg_ElevatorButton_fields
};

const RTStateId ElevatorButton_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTComponentDescriptor ElevatorButton_Actor::rtg_capsule_roles[] =
{
	{
		"elevatorButtonLamp"
	  , &ElevatorButtonLamp
	  , RTOffsetOf( ElevatorButton_Actor, elevatorButtonLamp )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_elevatorButtonLamp
	  , 1
	  , rtg_bindings_elevatorButtonLamp
	}
};

const RTPortDescriptor ElevatorButton_Actor::rtg_ports[] =
{
	{
		"LEBPort"
	  , (const char *)0
	  , &LEBProtocol::Base::rt_class
	  , RTOffsetOf( ElevatorButton_Actor, ElevatorButton_Actor::LEBPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"UEBPort"
	  , (const char *)0
	  , &UEBProtocol::Base::rt_class
	  , RTOffsetOf( ElevatorButton_Actor, ElevatorButton_Actor::UEBPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"EBLEBPort"
	  , (const char *)0
	  , &EBLEBProtocol::Conjugate::rt_class
	  , RTOffsetOf( ElevatorButton_Actor, ElevatorButton_Actor::EBLEBPort )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor ElevatorButton_Actor::rtg_ElevatorButton_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( ElevatorButton_Actor, id )
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
