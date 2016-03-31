// {{{RME classifier 'Logical View::EmergencyBrake'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "EmergencyBrake.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EmergencyBrake.h>
#include <ElevatorStatus.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"LEBRPort"
	  , &LEBRProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_EmergencyBrake_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new EmergencyBrake_Actor( _rts, _ref );
}

const RTActorClass EmergencyBrake =
{
	(const RTActorClass *)0
  , "EmergencyBrake"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_EmergencyBrake_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Unactivated"
  , "Activated"
};

const RTTypeModifier rtg_tm_EmergencyBrake_Actor_es =
{
	RTNumberConstant
  , 1
  , 1
};

#define SUPER RTActor

EmergencyBrake_Actor::EmergencyBrake_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

EmergencyBrake_Actor::~EmergencyBrake_Actor( void )
{
}

int EmergencyBrake_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// LEBRPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &LEBRPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Unactivated:J56FC35CD02BB:init'
INLINE_METHODS void EmergencyBrake_Actor::transition2_init( const void * rtdata, LEBRProtocol::Base * rtport )
{
	// {{{USR
	es = (ElevatorStatus*)rtdata;
	id = es->id;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Unactivated:J56FC35E90300:activateEmergencyBrakes'
INLINE_METHODS void EmergencyBrake_Actor::transition3_activateEmergencyBrakes( const void * rtdata, LEBRProtocol::Base * rtport )
{
	// {{{USR
	es->emergencyBrakesOn = true;
	log.show("ELEVATOR [");
	log.show(es->id);
	log.show("]'S EMERGENCY BRAKES ACTIVATED.\n");
	// }}}USR
}
// }}}RME

INLINE_CHAINS void EmergencyBrake_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void EmergencyBrake_Actor::chain2_init( void )
{
	// transition ':TOP:Unactivated:J56FC35CD02BB:init'
	rtgChainBegin( 2, "init" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_init( msg->data, (LEBRProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void EmergencyBrake_Actor::chain3_activateEmergencyBrakes( void )
{
	// transition ':TOP:Unactivated:J56FC35E90300:activateEmergencyBrakes'
	rtgChainBegin( 2, "activateEmergencyBrakes" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_activateEmergencyBrakes( msg->data, (LEBRProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

void EmergencyBrake_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Unactivated'
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
				// {{{RME port 'LEBRPort'
				switch( signalIndex )
				{
				case LEBRProtocol::Base::rti_init:
					chain2_init();
					return;
				case LEBRProtocol::Base::rti_activateEmergencyBrakes:
					chain3_activateEmergencyBrakes();
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
			// {{{RME state ':TOP:Activated'
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
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * EmergencyBrake_Actor::getActorData( void ) const
{
	return &EmergencyBrake_Actor::rtg_class;
}

const RTActor_class EmergencyBrake_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , EmergencyBrake_Actor::rtg_parent_state
  , &EmergencyBrake
  , 0
  , (const RTComponentDescriptor *)0
  , 2
  , EmergencyBrake_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 2
  , EmergencyBrake_Actor::rtg_EmergencyBrake_fields
};

const RTStateId EmergencyBrake_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTPortDescriptor EmergencyBrake_Actor::rtg_ports[] =
{
	{
		"LEBRPort"
	  , (const char *)0
	  , &LEBRProtocol::Base::rt_class
	  , RTOffsetOf( EmergencyBrake_Actor, EmergencyBrake_Actor::LEBRPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( EmergencyBrake_Actor, EmergencyBrake_Actor::log )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor EmergencyBrake_Actor::rtg_EmergencyBrake_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( EmergencyBrake_Actor, id )
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
	  , RTOffsetOf( EmergencyBrake_Actor, es )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_ElevatorStatus
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_EmergencyBrake_Actor_es
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
