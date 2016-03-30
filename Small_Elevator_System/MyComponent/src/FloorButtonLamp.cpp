// {{{RME classifier 'Logical View::FloorButtonLamp'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "FloorButtonLamp.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FloorButtonLamp.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"FBLFBPort"
	  , &FBLFBProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_FloorButtonLamp_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new FloorButtonLamp_Actor( _rts, _ref );
}

const RTActorClass FloorButtonLamp =
{
	(const RTActorClass *)0
  , "FloorButtonLamp"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_FloorButtonLamp_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Unlit"
  , "Lit"
};

#define SUPER RTActor

FloorButtonLamp_Actor::FloorButtonLamp_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

FloorButtonLamp_Actor::~FloorButtonLamp_Actor( void )
{
}

int FloorButtonLamp_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// FBLFBPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &FBLFBPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

INLINE_CHAINS void FloorButtonLamp_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void FloorButtonLamp_Actor::chain2_light( void )
{
	// transition ':TOP:Unlit:J56FC21E3035E:light'
	rtgChainBegin( 2, "light" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void FloorButtonLamp_Actor::chain4_ignoreUnlight( void )
{
	// transition ':TOP:Unlit:J56FC220B0116:ignoreUnlight'
	rtgChainBegin( 2, "ignoreUnlight" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void FloorButtonLamp_Actor::chain5_ignoreLight( void )
{
	// transition ':TOP:Lit:J56FC222003C1:ignoreLight'
	rtgChainBegin( 3, "ignoreLight" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void FloorButtonLamp_Actor::chain3_unlight( void )
{
	// transition ':TOP:Lit:J56FC21F30194:unlight'
	rtgChainBegin( 3, "unlight" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

void FloorButtonLamp_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'FBLFBPort'
				switch( signalIndex )
				{
				case FBLFBProtocol::Base::rti_light:
					chain2_light();
					return;
				case FBLFBProtocol::Base::rti_unlight:
					chain4_ignoreUnlight();
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
				// {{{RME port 'FBLFBPort'
				switch( signalIndex )
				{
				case FBLFBProtocol::Base::rti_light:
					chain5_ignoreLight();
					return;
				case FBLFBProtocol::Base::rti_unlight:
					chain3_unlight();
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

const RTActor_class * FloorButtonLamp_Actor::getActorData( void ) const
{
	return &FloorButtonLamp_Actor::rtg_class;
}

const RTActor_class FloorButtonLamp_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 3
  , FloorButtonLamp_Actor::rtg_parent_state
  , &FloorButtonLamp
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , FloorButtonLamp_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId FloorButtonLamp_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
};

const RTPortDescriptor FloorButtonLamp_Actor::rtg_ports[] =
{
	{
		"FBLFBPort"
	  , (const char *)0
	  , &FBLFBProtocol::Base::rt_class
	  , RTOffsetOf( FloorButtonLamp_Actor, FloorButtonLamp_Actor::FBLFBPort )
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
