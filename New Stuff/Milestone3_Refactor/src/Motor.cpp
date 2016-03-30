// {{{RME classifier 'Logical View::Motor'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Motor.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Motor.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"Motor_IN"
	  , &Motor_Protocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Motor_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Motor_Actor( _rts, _ref );
}

const RTActorClass Motor =
{
	(const RTActorClass *)0
  , "Motor"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_Motor_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Stopped"
  , "Running_Down"
  , "Running_Up"
  , "EMERGENCY"
};

#define SUPER RTActor

Motor_Actor::Motor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Motor_Actor::~Motor_Actor( void )
{
}

int Motor_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// Motor_IN
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Motor_IN;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

INLINE_CHAINS void Motor_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Motor_Actor::chain2_Start_Up( void )
{
	// transition ':TOP:Stopped:J5155FF8B01B4:Start_Up'
	rtgChainBegin( 2, "Start_Up" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Motor_Actor::chain4_Start_Down( void )
{
	// transition ':TOP:Stopped:J5155FFA40368:Start_Down'
	rtgChainBegin( 2, "Start_Down" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Motor_Actor::chain8_E_Brake( void )
{
	// transition ':TOP:Stopped:J515603CB01FE:E_Brake'
	rtgChainBegin( 2, "E_Brake" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void Motor_Actor::chain5_Stop( void )
{
	// transition ':TOP:Running_Down:J5155FFB001B2:Stop'
	rtgChainBegin( 3, "Stop" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Motor_Actor::chain6_E_Brake( void )
{
	// transition ':TOP:Running_Down:J515603BE03E3:E_Brake'
	rtgChainBegin( 3, "E_Brake" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void Motor_Actor::chain3_Stop( void )
{
	// transition ':TOP:Running_Up:J5155FF9603E6:Stop'
	rtgChainBegin( 4, "Stop" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Motor_Actor::chain7_E_Brake( void )
{
	// transition ':TOP:Running_Up:J515603C402CA:E_Brake'
	rtgChainBegin( 4, "E_Brake" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 5 );
}

void Motor_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			case 1:
				// {{{RME port 'Motor_IN'
				switch( signalIndex )
				{
				case Motor_Protocol::Base::rti_Start_UP:
					chain2_Start_Up();
					return;
				case Motor_Protocol::Base::rti_Start_DOWN:
					chain4_Start_Down();
					return;
				case Motor_Protocol::Base::rti_E_Brake:
					chain8_E_Brake();
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
			// {{{RME state ':TOP:Running_Down'
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
				// {{{RME port 'Motor_IN'
				switch( signalIndex )
				{
				case Motor_Protocol::Base::rti_STOP:
					chain5_Stop();
					return;
				case Motor_Protocol::Base::rti_E_Brake:
					chain6_E_Brake();
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
			// {{{RME state ':TOP:Running_Up'
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
				// {{{RME port 'Motor_IN'
				switch( signalIndex )
				{
				case Motor_Protocol::Base::rti_STOP:
					chain3_Stop();
					return;
				case Motor_Protocol::Base::rti_E_Brake:
					chain7_E_Brake();
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
			// {{{RME state ':TOP:EMERGENCY'
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

const RTActor_class * Motor_Actor::getActorData( void ) const
{
	return &Motor_Actor::rtg_class;
}

const RTActor_class Motor_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 5
  , Motor_Actor::rtg_parent_state
  , &Motor
  , 0
  , (const RTComponentDescriptor *)0
  , 1
  , Motor_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId Motor_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
};

const RTPortDescriptor Motor_Actor::rtg_ports[] =
{
	{
		"Motor_IN"
	  , (const char *)0
	  , &Motor_Protocol::Base::rt_class
	  , RTOffsetOf( Motor_Actor, Motor_Actor::Motor_IN )
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
