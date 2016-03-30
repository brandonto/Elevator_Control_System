// {{{RME classifier 'Logical View::DoorSensor'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "DoorSensor.h"
#endif

#include <RTSystem/MyComponent.h>
#include <DoorSensor.h>
#include <ElevatorStatus.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"EDDSPort"
	  , &EDDSProtocol::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"UDSPort"
	  , &UDSProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_DoorSensor_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new DoorSensor_Actor( _rts, _ref );
}

const RTActorClass DoorSensor =
{
	(const RTActorClass *)0
  , "DoorSensor"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_DoorSensor_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
};

#define SUPER RTActor

DoorSensor_Actor::DoorSensor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

DoorSensor_Actor::~DoorSensor_Actor( void )
{
}

int DoorSensor_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// EDDSPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &EDDSPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// UDSPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &UDSPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Ready:J56FBEC8602DA:init'
INLINE_METHODS void DoorSensor_Actor::transition2_init( const void * rtdata, EDDSProtocol::Base * rtport )
{
	// {{{USR
	ElevatorStatus *es =(ElevatorStatus*)rtdata;
	id = es->id;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FBED4F0370:impede'
INLINE_METHODS void DoorSensor_Actor::transition3_impede( const void * rtdata, UDSProtocol::Base * rtport )
{
	// {{{USR
	EDDSPort.impede().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void DoorSensor_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void DoorSensor_Actor::chain2_init( void )
{
	// transition ':TOP:Ready:J56FBEC8602DA:init'
	rtgChainBegin( 2, "init" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_init( msg->data, (EDDSProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void DoorSensor_Actor::chain3_impede( void )
{
	// transition ':TOP:Ready:J56FBED4F0370:impede'
	rtgChainBegin( 2, "impede" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_impede( msg->data, (UDSProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void DoorSensor_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'EDDSPort'
				switch( signalIndex )
				{
				case EDDSProtocol::Base::rti_init:
					chain2_init();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'UDSPort'
				switch( signalIndex )
				{
				case UDSProtocol::Base::rti_impede:
					chain3_impede();
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

const RTActor_class * DoorSensor_Actor::getActorData( void ) const
{
	return &DoorSensor_Actor::rtg_class;
}

const RTActor_class DoorSensor_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , DoorSensor_Actor::rtg_parent_state
  , &DoorSensor
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , DoorSensor_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , DoorSensor_Actor::rtg_DoorSensor_fields
};

const RTStateId DoorSensor_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTPortDescriptor DoorSensor_Actor::rtg_ports[] =
{
	{
		"EDDSPort"
	  , (const char *)0
	  , &EDDSProtocol::Base::rt_class
	  , RTOffsetOf( DoorSensor_Actor, DoorSensor_Actor::EDDSPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"UDSPort"
	  , (const char *)0
	  , &UDSProtocol::Base::rt_class
	  , RTOffsetOf( DoorSensor_Actor, DoorSensor_Actor::UDSPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

const RTFieldDescriptor DoorSensor_Actor::rtg_DoorSensor_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( DoorSensor_Actor, id )
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
