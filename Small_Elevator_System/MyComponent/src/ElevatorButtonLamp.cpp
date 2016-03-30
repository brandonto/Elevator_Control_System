// {{{RME classifier 'Logical View::ElevatorButtonLamp'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ElevatorButtonLamp.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ElevatorButtonLamp.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"EBLEBPort"
	  , &EBLEBProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ElevatorButtonLamp_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ElevatorButtonLamp_Actor( _rts, _ref );
}

const RTActorClass ElevatorButtonLamp =
{
	(const RTActorClass *)0
  , "ElevatorButtonLamp"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_ElevatorButtonLamp_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Unlit"
  , "Lit"
};

#define SUPER RTActor

ElevatorButtonLamp_Actor::ElevatorButtonLamp_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ElevatorButtonLamp_Actor::~ElevatorButtonLamp_Actor( void )
{
}

int ElevatorButtonLamp_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// EBLEBPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &EBLEBPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

INLINE_CHAINS void ElevatorButtonLamp_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorButtonLamp_Actor::chain3_light( void )
{
	// transition ':TOP:Unlit:J56FC51810182:light'
	rtgChainBegin( 2, "light" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorButtonLamp_Actor::chain2_ignoreUnlight( void )
{
	// transition ':TOP:Unlit:J56FC5167026C:ignoreUnlight'
	rtgChainBegin( 2, "ignoreUnlight" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorButtonLamp_Actor::chain5_ignoreLight( void )
{
	// transition ':TOP:Lit:J56FC518E0308:ignoreLight'
	rtgChainBegin( 3, "ignoreLight" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorButtonLamp_Actor::chain4_unlight( void )
{
	// transition ':TOP:Lit:J56FC51870361:unlight'
	rtgChainBegin( 3, "unlight" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

void ElevatorButtonLamp_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Unlit'
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
				// {{{RME port 'EBLEBPort'
				switch( signalIndex )
				{
				case EBLEBProtocol::Base::rti_light:
					chain3_light();
					return;
				case EBLEBProtocol::Base::rti_unlight:
					chain2_ignoreUnlight();
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
			// {{{RME state ':TOP:Lit'
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
				// {{{RME port 'EBLEBPort'
				switch( signalIndex )
				{
				case EBLEBProtocol::Base::rti_light:
					chain5_ignoreLight();
					return;
				case EBLEBProtocol::Base::rti_unlight:
					chain4_unlight();
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

const RTActor_class * ElevatorButtonLamp_Actor::getActorData( void ) const
{
	return &ElevatorButtonLamp_Actor::rtg_class;
}

const RTActor_class ElevatorButtonLamp_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , ElevatorButtonLamp_Actor::rtg_parent_state
  , &ElevatorButtonLamp
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , ElevatorButtonLamp_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId ElevatorButtonLamp_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTPortDescriptor ElevatorButtonLamp_Actor::rtg_ports[] =
{
	{
		"EBLEBPort"
	  , (const char *)0
	  , &EBLEBProtocol::Base::rt_class
	  , RTOffsetOf( ElevatorButtonLamp_Actor, ElevatorButtonLamp_Actor::EBLEBPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
