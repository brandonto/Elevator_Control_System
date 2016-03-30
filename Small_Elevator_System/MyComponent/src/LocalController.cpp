// {{{RME classifier 'Logical View::LocalController'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "LocalController.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LocalController.h>
#include <ButtonInfo.h>
#include <ElevatorStatus.h>
extern const RTActorClass ElevatorButton;
extern const RTActorClass ElevatorDoor;
extern const RTActorClass ElevatorMotor;
extern const RTActorClass EmergencyBrake;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"LEPort"
	  , &LEProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_LocalController_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new LocalController_Actor( _rts, _ref );
}

const RTActorClass LocalController =
{
	(const RTActorClass *)0
  , "LocalController"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_LocalController_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
};

static const RTInterfaceDescriptor rtg_interfaces_elevatorMotor[] =
{
	{
		"LEMPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_elevatorMotor[] =
{
	{
		0
	  , &LEMProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_elevatorDoor[] =
{
	{
		"LEDPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_elevatorDoor[] =
{
	{
		0
	  , &LEDProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_emergencyBrake[] =
{
	{
		"LEBRPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_emergencyBrake[] =
{
	{
		0
	  , &LEBRProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_elevatorButton[] =
{
	{
		"LEBPort"
	  , 1
	}
  , {
		"UEBPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_elevatorButton[] =
{
	{
		0
	  , &LEBProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

LocalController_Actor::LocalController_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

LocalController_Actor::~LocalController_Actor( void )
{
}

int LocalController_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// LEPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &LEPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int LocalController_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// elevatorMotor
		switch( rtg_portId )
		{
		case 0:
			// LEMPort
			if( rtg_repIndex < 1 )
			{
				// LEMPort
				rtg_end.port = &LEMPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 2:
		// elevatorDoor
		switch( rtg_portId )
		{
		case 0:
			// LEDPort
			if( rtg_repIndex < 1 )
			{
				// LEDPort
				rtg_end.port = &LEDPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 3:
		// emergencyBrake
		switch( rtg_portId )
		{
		case 0:
			// LEBRPort
			if( rtg_repIndex < 1 )
			{
				// LEBRPort
				rtg_end.port = &LEBRPort;
				rtg_end.index = rtg_repIndex;
				return 1;
			}
			break;
		default:
			break;
		}
	case 4:
		// elevatorButton
		switch( rtg_portId )
		{
		case 0:
			// LEBPort
			if( rtg_repIndex < 10 )
			{
				// LEBPort
				rtg_end.port = &LEBPort;
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

// {{{RME transition ':TOP:Ready:J56FC05E3011B:elevatorButtonPressed'
INLINE_METHODS void LocalController_Actor::transition2_elevatorButtonPressed( const int * rtdata, LEBProtocol::Conjugate * rtport )
{
	// {{{USR
	//int destinationFloor = *rtdata;
	ButtonInfo bi;
	bi.floorNum = *rtdata;
	bi.floorId = bi.floorNum - 1;
	bi.floorButton = false;
	LEPort.elevatorButtonPressed(bi).send();
	//LEPort.elevatorButtonPressed(destinationFloor).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56E0AD2E0043:moveElevator'
INLINE_METHODS void LocalController_Actor::transition3_moveElevator( const int * rtdata, LEProtocol::Base * rtport )
{
	// {{{USR
	int direction = *rtdata;
	if (direction == 1)
	{
		LEMPort.moveElevatorUp().send();
	}
	else if (direction == -1)
	{
		LEMPort.moveElevatorDown().send();
	}
	else
	{
		LEMPort.stopElevator().send();
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FAF39101FE:arrivedAtFloor'
INLINE_METHODS void LocalController_Actor::transition4_arrivedAtFloor( const void * rtdata, LEMProtocol::Conjugate * rtport )
{
	// {{{USR
	LEPort.arrivedAtFloor().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB13130365:openDoor'
INLINE_METHODS void LocalController_Actor::transition5_openDoor( const void * rtdata, LEProtocol::Base * rtport )
{
	// {{{USR
	LEDPort.openDoor().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB15530146:doorClosed'
INLINE_METHODS void LocalController_Actor::transition6_doorClosed( const void * rtdata, LEDProtocol::Conjugate * rtport )
{
	// {{{USR
	LEPort.doorClosed().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB2DA700CA:init'
INLINE_METHODS void LocalController_Actor::transition7_init( const void * rtdata, LEProtocol::Base * rtport )
{
	// {{{USR
	ElevatorStatus *es = (ElevatorStatus*)rtdata;
	id = es->id;
	LEMPort.init(es).send();
	LEDPort.init(es).send();
	LEBRPort.init(es).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FC4FA0036C:clearButton'
INLINE_METHODS void LocalController_Actor::transition8_clearButton( const int * rtdata, LEProtocol::Base * rtport )
{
	// {{{USR
	LEBPort.clearButton().sendAt(*rtdata-1);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void LocalController_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain7_init( void )
{
	// transition ':TOP:Ready:J56FB2DA700CA:init'
	rtgChainBegin( 2, "init" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_init( msg->data, (LEProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain3_moveElevator( void )
{
	// transition ':TOP:Ready:J56E0AD2E0043:moveElevator'
	rtgChainBegin( 2, "moveElevator" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_moveElevator( (const int *)msg->data, (LEProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain5_openDoor( void )
{
	// transition ':TOP:Ready:J56FB13130365:openDoor'
	rtgChainBegin( 2, "openDoor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_openDoor( msg->data, (LEProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain8_clearButton( void )
{
	// transition ':TOP:Ready:J56FC4FA0036C:clearButton'
	rtgChainBegin( 2, "clearButton" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_clearButton( (const int *)msg->data, (LEProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain4_arrivedAtFloor( void )
{
	// transition ':TOP:Ready:J56FAF39101FE:arrivedAtFloor'
	rtgChainBegin( 2, "arrivedAtFloor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_arrivedAtFloor( msg->data, (LEMProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain6_doorClosed( void )
{
	// transition ':TOP:Ready:J56FB15530146:doorClosed'
	rtgChainBegin( 2, "doorClosed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_doorClosed( msg->data, (LEDProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void LocalController_Actor::chain2_elevatorButtonPressed( void )
{
	// transition ':TOP:Ready:J56FC05E3011B:elevatorButtonPressed'
	rtgChainBegin( 2, "elevatorButtonPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_elevatorButtonPressed( (const int *)msg->data, (LEBProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void LocalController_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			case 1:
				// {{{RME port 'LEPort'
				switch( signalIndex )
				{
				case LEProtocol::Base::rti_init:
					chain7_init();
					return;
				case LEProtocol::Base::rti_moveElevator:
					chain3_moveElevator();
					return;
				case LEProtocol::Base::rti_openDoor:
					chain5_openDoor();
					return;
				case LEProtocol::Base::rti_clearButton:
					chain8_clearButton();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'LEMPort'
				switch( signalIndex )
				{
				case LEMProtocol::Conjugate::rti_arrivedAtFloor:
					chain4_arrivedAtFloor();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'LEDPort'
				switch( signalIndex )
				{
				case LEDProtocol::Conjugate::rti_doorClosed:
					chain6_doorClosed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 5:
				// {{{RME port 'LEBPort'
				switch( signalIndex )
				{
				case LEBProtocol::Conjugate::rti_elevatorButtonPressed:
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
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * LocalController_Actor::getActorData( void ) const
{
	return &LocalController_Actor::rtg_class;
}

const RTActor_class LocalController_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , LocalController_Actor::rtg_parent_state
  , &LocalController
  , 4
  , LocalController_Actor::rtg_capsule_roles
  , 6
  , LocalController_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , LocalController_Actor::rtg_LocalController_fields
};

const RTStateId LocalController_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor LocalController_Actor::rtg_capsule_roles[] =
{
	{
		"elevatorMotor"
	  , &ElevatorMotor
	  , RTOffsetOf( LocalController_Actor, elevatorMotor )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_elevatorMotor
	  , 1
	  , rtg_bindings_elevatorMotor
	}
  , {
		"elevatorDoor"
	  , &ElevatorDoor
	  , RTOffsetOf( LocalController_Actor, elevatorDoor )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_elevatorDoor
	  , 1
	  , rtg_bindings_elevatorDoor
	}
  , {
		"emergencyBrake"
	  , &EmergencyBrake
	  , RTOffsetOf( LocalController_Actor, emergencyBrake )
	  , 3
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_emergencyBrake
	  , 1
	  , rtg_bindings_emergencyBrake
	}
  , {
		"elevatorButton"
	  , &ElevatorButton
	  , RTOffsetOf( LocalController_Actor, elevatorButton )
	  , 4
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 10 // cardinality
	  , 2
	  , rtg_interfaces_elevatorButton
	  , 1
	  , rtg_bindings_elevatorButton
	}
};

const RTPortDescriptor LocalController_Actor::rtg_ports[] =
{
	{
		"LEPort"
	  , (const char *)0
	  , &LEProtocol::Base::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::LEPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"LEMPort"
	  , (const char *)0
	  , &LEMProtocol::Conjugate::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::LEMPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"LEDPort"
	  , (const char *)0
	  , &LEDProtocol::Conjugate::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::LEDPort )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"LEBRPort"
	  , (const char *)0
	  , &LEBRProtocol::Conjugate::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::LEBRPort )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"LEBPort"
	  , (const char *)0
	  , &LEBProtocol::Conjugate::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::LEBPort )
	  , 10 // cardinality
	  , 5
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( LocalController_Actor, LocalController_Actor::log )
	  , 1 // cardinality
	  , 6
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor LocalController_Actor::rtg_LocalController_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( LocalController_Actor, id )
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