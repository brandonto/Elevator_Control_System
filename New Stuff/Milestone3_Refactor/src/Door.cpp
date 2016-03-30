// {{{RME classifier 'Logical View::Door'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Door.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Door.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"Door_Test"
	  , &Door_Test::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"Door_IN"
	  , &Door_Protocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Door_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Door_Actor( _rts, _ref );
}

const RTActorClass Door =
{
	(const RTActorClass *)0
  , "Door"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_Door_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Door_Closed"
  , "Door_Opening"
  , "Door_Open"
  , "Door_Closing"
};

#define SUPER RTActor

Door_Actor::Door_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Door_Actor::~Door_Actor( void )
{
}

int Door_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// Door_Test
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Door_Test;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// Door_IN
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &Door_IN;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Door_Closed:J5154A1CF02FD:Door_Open_Start'
INLINE_METHODS void Door_Actor::transition2_Door_Open_Start( const bool * rtdata, RTProtocol * rtport )
{
	// {{{USR
	//Create a timeout to go off in 2 seconds.
	RTTimespec Two_Seconds (2, 0);
	Door_Timer.informIn (Two_Seconds);
	Door_IN.Doors_Open(true).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Door_Opening:J5154A1EC0163:Door_Open_Finish'
INLINE_METHODS void Door_Actor::transition3_Door_Open_Finish( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Create a timeout to go off in 5 seconds.
	RTTimespec Five_Seconds (5, 0);
	Door_Timer.informIn (Five_Seconds);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Door_Open:J5154A1F50096:Door_Close_Start'
INLINE_METHODS void Door_Actor::transition4_Door_Close_Start( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	//Create a timeout to go off in 2 seconds.
	RTTimespec Two_Seconds (2, 0);
	DoorTimer_ID = Door_Timer.informIn (Two_Seconds);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Door_Closing:J5154A1FC0141:Door_Close_Finish'
INLINE_METHODS void Door_Actor::transition5_Door_Close_Finish( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	Door_IN.Doors_Closed(true).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Door_Closing:J5154A2340169:Door_Obstructed'
INLINE_METHODS void Door_Actor::transition6_Door_Obstructed( const bool * rtdata, Door_Test::Base * rtport )
{
	// {{{USR
	//Cancel Door Closing Timer, Open doors again
	Door_Timer.cancelTimer( DoorTimer_ID ); 
	RTTimespec Two_Seconds (2, 0);
	Door_Timer.informIn (Two_Seconds);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Door_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Door_Actor::chain2_Door_Open_Start( void )
{
	// transition ':TOP:Door_Closed:J5154A1CF02FD:Door_Open_Start'
	rtgChainBegin( 2, "Door_Open_Start" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_Door_Open_Start( (const bool *)msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void Door_Actor::chain3_Door_Open_Finish( void )
{
	// transition ':TOP:Door_Opening:J5154A1EC0163:Door_Open_Finish'
	rtgChainBegin( 3, "Door_Open_Finish" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_Door_Open_Finish( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Door_Actor::chain4_Door_Close_Start( void )
{
	// transition ':TOP:Door_Open:J5154A1F50096:Door_Close_Start'
	rtgChainBegin( 4, "Door_Close_Start" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_Door_Close_Start( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 5 );
}

INLINE_CHAINS void Door_Actor::chain6_Door_Obstructed( void )
{
	// transition ':TOP:Door_Closing:J5154A2340169:Door_Obstructed'
	rtgChainBegin( 5, "Door_Obstructed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_Door_Obstructed( (const bool *)msg->data, (Door_Test::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void Door_Actor::chain5_Door_Close_Finish( void )
{
	// transition ':TOP:Door_Closing:J5154A1FC0141:Door_Close_Finish'
	rtgChainBegin( 5, "Door_Close_Finish" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_Door_Close_Finish( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Door_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			// {{{RME state ':TOP:Door_Closed'
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
				// {{{RME port 'Door_Test'
				switch( signalIndex )
				{
				case Door_Test::Base::rti_TEST_Command_Door_Open:
					chain2_Door_Open_Start();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'Door_IN'
				switch( signalIndex )
				{
				case Door_Protocol::Base::rti_Command_Door_Open:
					chain2_Door_Open_Start();
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
			// {{{RME state ':TOP:Door_Opening'
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
				// {{{RME port 'Door_Timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain3_Door_Open_Finish();
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
			// {{{RME state ':TOP:Door_Open'
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
				// {{{RME port 'Door_Timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain4_Door_Close_Start();
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
			// {{{RME state ':TOP:Door_Closing'
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
				// {{{RME port 'Door_Test'
				switch( signalIndex )
				{
				case Door_Test::Base::rti_TEST_Door_Obstructed:
					chain6_Door_Obstructed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'Door_Timer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain5_Door_Close_Finish();
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

const RTActor_class * Door_Actor::getActorData( void ) const
{
	return &Door_Actor::rtg_class;
}

const RTActor_class Door_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 5
  , Door_Actor::rtg_parent_state
  , &Door
  , 0
  , (const RTComponentDescriptor *)0
  , 3
  , Door_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId Door_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
  , 1
};

const RTPortDescriptor Door_Actor::rtg_ports[] =
{
	{
		"Door_Test"
	  , (const char *)0
	  , &Door_Test::Base::rt_class
	  , RTOffsetOf( Door_Actor, Door_Actor::Door_Test )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"Door_Timer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( Door_Actor, Door_Actor::Door_Timer )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"Door_IN"
	  , (const char *)0
	  , &Door_Protocol::Base::rt_class
	  , RTOffsetOf( Door_Actor, Door_Actor::Door_IN )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
