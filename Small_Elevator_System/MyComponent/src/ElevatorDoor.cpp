// {{{RME classifier 'Logical View::ElevatorDoor'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ElevatorDoor.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ElevatorDoor.h>
#include <ElevatorStatus.h>
extern const RTActorClass DoorSensor;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"LEDPort"
	  , &LEDProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ElevatorDoor_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ElevatorDoor_Actor( _rts, _ref );
}

const RTActorClass ElevatorDoor =
{
	(const RTActorClass *)0
  , "ElevatorDoor"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_ElevatorDoor_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Closed"
  , "Opened"
  , "Closing"
  , "Opening"
};

static const RTInterfaceDescriptor rtg_interfaces_doorSensor[] =
{
	{
		"EDDSPort"
	  , 1
	}
  , {
		"UDSPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_doorSensor[] =
{
	{
		0
	  , &EDDSProtocol::Conjugate::rt_class
	}
};

const RTTypeModifier rtg_tm_ElevatorDoor_Actor_es =
{
	RTNumberConstant
  , 1
  , 1
};

#define SUPER RTActor

ElevatorDoor_Actor::ElevatorDoor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ElevatorDoor_Actor::~ElevatorDoor_Actor( void )
{
}

int ElevatorDoor_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// LEDPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &LEDPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int ElevatorDoor_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// doorSensor
		switch( rtg_portId )
		{
		case 0:
			// EDDSPort
			if( rtg_repIndex < 1 )
			{
				// EDDSPort
				rtg_end.port = &EDDSPort;
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

// {{{RME transition ':TOP:Closed:J56FB14B003AE:openDoor'
INLINE_METHODS void ElevatorDoor_Actor::transition2_openDoor( const void * rtdata, LEDProtocol::Base * rtport )
{
	// {{{USR
	doorTimer.informIn(RTTimespec(2,0));
	log.show("Elevator [");
	log.show(id);
	log.show("] door opening.\n");

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Opened:J56FB14B5027F:closeDoor'
INLINE_METHODS void ElevatorDoor_Actor::transition3_closeDoor( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	closeTimer.informIn(RTTimespec(2,0));
	log.show("Elevator [");
	log.show(id);
	log.show("] door closing.\n");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Closed:J56FB2E660011:init'
INLINE_METHODS void ElevatorDoor_Actor::transition4_init( const void * rtdata, LEDProtocol::Base * rtport )
{
	// {{{USR
	es = (ElevatorStatus*)rtdata;
	id = es->id;

	EDDSPort.init(es).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Opening:J56FBEF9B0125:doorOpened'
INLINE_METHODS void ElevatorDoor_Actor::transition6_doorOpened( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	doorTimer.informIn(RTTimespec(3,0));
	log.show("Elevator [");
	log.show(id);
	log.show("] door opened.\n");
	es->doorOpen = true;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Closing:J56FBF20503B0:doorClosed'
INLINE_METHODS void ElevatorDoor_Actor::transition8_doorClosed( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	LEDPort.doorClosed().send();
	log.show("Elevator [");
	log.show(id);
	log.show("] door closed.\n");
	es->doorOpen = false;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Closing:J56FBF27D0218:impede'
INLINE_METHODS void ElevatorDoor_Actor::transition9_impede( const void * rtdata, EDDSProtocol::Conjugate * rtport )
{
	// {{{USR
	doorTimer.informIn(RTTimespec(3,0));
	log.show("Elevator [");
	log.show(id);
	log.show("] door impeded, opened again.\n");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Closing:J56FC59A200D0:openDoor'
INLINE_METHODS void ElevatorDoor_Actor::transition11_openDoor( const void * rtdata, LEDProtocol::Base * rtport )
{
	// {{{USR
	doorTimer.informIn(RTTimespec(3,0));
	log.show("Elevator [");
	log.show(id);
	log.show("] door opened.\n");
	es->doorOpen = true;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ElevatorDoor_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain4_init( void )
{
	// transition ':TOP:Closed:J56FB2E660011:init'
	rtgChainBegin( 2, "init" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_init( msg->data, (LEDProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain2_openDoor( void )
{
	// transition ':TOP:Closed:J56FB14B003AE:openDoor'
	rtgChainBegin( 2, "openDoor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_openDoor( msg->data, (LEDProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain5_ignore( void )
{
	// transition ':TOP:Closed:J56FBEDAA03E9:ignore'
	rtgChainBegin( 2, "ignore" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain10_ignore( void )
{
	// transition ':TOP:Opened:J56FBF2A10398:ignore'
	rtgChainBegin( 3, "ignore" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain3_closeDoor( void )
{
	// transition ':TOP:Opened:J56FB14B5027F:closeDoor'
	rtgChainBegin( 3, "closeDoor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_closeDoor( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain11_openDoor( void )
{
	// transition ':TOP:Closing:J56FC59A200D0:openDoor'
	rtgChainBegin( 4, "openDoor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition11_openDoor( msg->data, (LEDProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain12_ignoreClose( void )
{
	// transition ':TOP:Closing:J56FC59C80360:ignoreClose'
	rtgChainBegin( 4, "ignoreClose" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain9_impede( void )
{
	// transition ':TOP:Closing:J56FBF27D0218:impede'
	rtgChainBegin( 4, "impede" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition9_impede( msg->data, (EDDSProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain8_doorClosed( void )
{
	// transition ':TOP:Closing:J56FBF20503B0:doorClosed'
	rtgChainBegin( 4, "doorClosed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_doorClosed( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain7_ignore( void )
{
	// transition ':TOP:Opening:J56FBEFD60316:ignore'
	rtgChainBegin( 5, "ignore" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void ElevatorDoor_Actor::chain6_doorOpened( void )
{
	// transition ':TOP:Opening:J56FBEF9B0125:doorOpened'
	rtgChainBegin( 5, "doorOpened" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_doorOpened( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

void ElevatorDoor_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Closed'
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
				// {{{RME port 'LEDPort'
				switch( signalIndex )
				{
				case LEDProtocol::Base::rti_init:
					chain4_init();
					return;
				case LEDProtocol::Base::rti_openDoor:
					chain2_openDoor();
					return;
				case LEDProtocol::Base::rti_closeDoor:
					chain5_ignore();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'EDDSPort'
				switch( signalIndex )
				{
				case EDDSProtocol::Conjugate::rti_impede:
					chain5_ignore();
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
			// {{{RME state ':TOP:Opened'
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
				// {{{RME port 'LEDPort'
				switch( signalIndex )
				{
				case LEDProtocol::Base::rti_openDoor:
					chain10_ignore();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'EDDSPort'
				switch( signalIndex )
				{
				case EDDSProtocol::Conjugate::rti_impede:
					chain10_ignore();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'doorTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain3_closeDoor();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'closeTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain10_ignore();
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
			// {{{RME state ':TOP:Closing'
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
				// {{{RME port 'LEDPort'
				switch( signalIndex )
				{
				case LEDProtocol::Base::rti_openDoor:
					chain11_openDoor();
					return;
				case LEDProtocol::Base::rti_closeDoor:
					chain12_ignoreClose();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'EDDSPort'
				switch( signalIndex )
				{
				case EDDSProtocol::Conjugate::rti_impede:
					chain9_impede();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'closeTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain8_doorClosed();
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
			// {{{RME state ':TOP:Opening'
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
				// {{{RME port 'LEDPort'
				switch( signalIndex )
				{
				case LEDProtocol::Base::rti_openDoor:
					chain7_ignore();
					return;
				case LEDProtocol::Base::rti_closeDoor:
					chain7_ignore();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'EDDSPort'
				switch( signalIndex )
				{
				case EDDSProtocol::Conjugate::rti_impede:
					chain7_ignore();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'doorTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain6_doorOpened();
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

const RTActor_class * ElevatorDoor_Actor::getActorData( void ) const
{
	return &ElevatorDoor_Actor::rtg_class;
}

const RTActor_class ElevatorDoor_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 5
  , ElevatorDoor_Actor::rtg_parent_state
  , &ElevatorDoor
  , 1
  , ElevatorDoor_Actor::rtg_capsule_roles
  , 5
  , ElevatorDoor_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 2
  , ElevatorDoor_Actor::rtg_ElevatorDoor_fields
};

const RTStateId ElevatorDoor_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
};

const RTComponentDescriptor ElevatorDoor_Actor::rtg_capsule_roles[] =
{
	{
		"doorSensor"
	  , &DoorSensor
	  , RTOffsetOf( ElevatorDoor_Actor, doorSensor )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_doorSensor
	  , 1
	  , rtg_bindings_doorSensor
	}
};

const RTPortDescriptor ElevatorDoor_Actor::rtg_ports[] =
{
	{
		"LEDPort"
	  , (const char *)0
	  , &LEDProtocol::Base::rt_class
	  , RTOffsetOf( ElevatorDoor_Actor, ElevatorDoor_Actor::LEDPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"EDDSPort"
	  , (const char *)0
	  , &EDDSProtocol::Conjugate::rt_class
	  , RTOffsetOf( ElevatorDoor_Actor, ElevatorDoor_Actor::EDDSPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"doorTimer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( ElevatorDoor_Actor, ElevatorDoor_Actor::doorTimer )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"closeTimer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( ElevatorDoor_Actor, ElevatorDoor_Actor::closeTimer )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( ElevatorDoor_Actor, ElevatorDoor_Actor::log )
	  , 1 // cardinality
	  , 5
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor ElevatorDoor_Actor::rtg_ElevatorDoor_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( ElevatorDoor_Actor, id )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'es'
  , {
		"es"
	  , RTOffsetOf( ElevatorDoor_Actor, es )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_ElevatorStatus
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_ElevatorDoor_Actor_es
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
