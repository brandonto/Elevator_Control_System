// {{{RME classifier 'Logical View::ElevatorMotor'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ElevatorMotor.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ElevatorMotor.h>
#include <ElevatorStatus.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"LEMPort"
	  , &LEMProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_ElevatorMotor_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ElevatorMotor_Actor( _rts, _ref );
}

const RTActorClass ElevatorMotor =
{
	(const RTActorClass *)0
  , "ElevatorMotor"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_ElevatorMotor_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Stopped"
  , "MoveUp"
  , "MoveDown"
};

#define SUPER RTActor

ElevatorMotor_Actor::ElevatorMotor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ElevatorMotor_Actor::~ElevatorMotor_Actor( void )
{
}

int ElevatorMotor_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// LEMPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &LEMPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

// {{{RME transition ':TOP:Stopped:J56E0B1DF037B:moveUp'
INLINE_METHODS void ElevatorMotor_Actor::transition2_moveUp( const void * rtdata, LEMProtocol::Base * rtport )
{
	// {{{USR
	moveTimer.informIn(RTTimespec(2,0));
	log.show("Elevator [");
	log.show(id);
	log.show("] motor moving up.\n");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J56E0B1F40232:moveDown'
INLINE_METHODS void ElevatorMotor_Actor::transition3_moveDown( const void * rtdata, LEMProtocol::Base * rtport )
{
	// {{{USR
	moveTimer.informIn(RTTimespec(2,0));
	log.show("Elevator [");
	log.show(id);
	log.show("] motor moving down.\n");
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:MoveUp:J56E0B201039D:stop'
INLINE_METHODS void ElevatorMotor_Actor::transition4_stop( const void * rtdata, LEMProtocol::Base * rtport )
{
	// {{{USR
	log.show("Elevator [");
	log.show(id);
	log.show("] motor stopped.\n");;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:MoveDown:J56E0B22202DD:stop'
INLINE_METHODS void ElevatorMotor_Actor::transition5_stop( const void * rtdata, LEMProtocol::Base * rtport )
{
	// {{{USR
	log.show("Elevator [");
	log.show(id);
	log.show("] motor stopped.\n");;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:MoveUp:J56FAF2DD00C8:arrivedAtFloor'
INLINE_METHODS void ElevatorMotor_Actor::transition6_arrivedAtFloor( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	LEMPort.arrivedAtFloor().send();
	moveTimer.informIn(RTTimespec(2,0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:MoveDown:J56FAF5B702A9:arriveAtFloor'
INLINE_METHODS void ElevatorMotor_Actor::transition7_arriveAtFloor( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	LEMPort.arrivedAtFloor().send();
	moveTimer.informIn(RTTimespec(2,0));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J56FAF85402D3:ignoreTimeout'
INLINE_METHODS void ElevatorMotor_Actor::transition8_ignoreTimeout( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	// Do nothing
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Stopped:J56FB2E0F03E1:init'
INLINE_METHODS void ElevatorMotor_Actor::transition12_init( const void * rtdata, LEMProtocol::Base * rtport )
{
	// {{{USR
	ElevatorStatus *es = (ElevatorStatus*)rtdata;
	id = es->id;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void ElevatorMotor_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain12_init( void )
{
	// transition ':TOP:Stopped:J56FB2E0F03E1:init'
	rtgChainBegin( 2, "init" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition12_init( msg->data, (LEMProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain2_moveUp( void )
{
	// transition ':TOP:Stopped:J56E0B1DF037B:moveUp'
	rtgChainBegin( 2, "moveUp" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_moveUp( msg->data, (LEMProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain3_moveDown( void )
{
	// transition ':TOP:Stopped:J56E0B1F40232:moveDown'
	rtgChainBegin( 2, "moveDown" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_moveDown( msg->data, (LEMProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain9_ignoreStop( void )
{
	// transition ':TOP:Stopped:J56FAF8D802F9:ignoreStop'
	rtgChainBegin( 2, "ignoreStop" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain8_ignoreTimeout( void )
{
	// transition ':TOP:Stopped:J56FAF85402D3:ignoreTimeout'
	rtgChainBegin( 2, "ignoreTimeout" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition8_ignoreTimeout( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain10_ignoreMoveUp( void )
{
	// transition ':TOP:MoveUp:J56FAF8F60049:ignoreMoveUp'
	rtgChainBegin( 3, "ignoreMoveUp" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain4_stop( void )
{
	// transition ':TOP:MoveUp:J56E0B201039D:stop'
	rtgChainBegin( 3, "stop" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_stop( msg->data, (LEMProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain6_arrivedAtFloor( void )
{
	// transition ':TOP:MoveUp:J56FAF2DD00C8:arrivedAtFloor'
	rtgChainBegin( 3, "arrivedAtFloor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_arrivedAtFloor( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain11_ignoreMoveDown( void )
{
	// transition ':TOP:MoveDown:J56FAF91001A7:ignoreMoveDown'
	rtgChainBegin( 4, "ignoreMoveDown" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain5_stop( void )
{
	// transition ':TOP:MoveDown:J56E0B22202DD:stop'
	rtgChainBegin( 4, "stop" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_stop( msg->data, (LEMProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void ElevatorMotor_Actor::chain7_arriveAtFloor( void )
{
	// transition ':TOP:MoveDown:J56FAF5B702A9:arriveAtFloor'
	rtgChainBegin( 4, "arriveAtFloor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_arriveAtFloor( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

void ElevatorMotor_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'LEMPort'
				switch( signalIndex )
				{
				case LEMProtocol::Base::rti_init:
					chain12_init();
					return;
				case LEMProtocol::Base::rti_moveElevatorUp:
					chain2_moveUp();
					return;
				case LEMProtocol::Base::rti_moveElevatorDown:
					chain3_moveDown();
					return;
				case LEMProtocol::Base::rti_stopElevator:
					chain9_ignoreStop();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'moveTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain8_ignoreTimeout();
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
			// {{{RME state ':TOP:MoveUp'
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
				// {{{RME port 'LEMPort'
				switch( signalIndex )
				{
				case LEMProtocol::Base::rti_moveElevatorUp:
					chain10_ignoreMoveUp();
					return;
				case LEMProtocol::Base::rti_stopElevator:
					chain4_stop();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'moveTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain6_arrivedAtFloor();
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
			// {{{RME state ':TOP:MoveDown'
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
				// {{{RME port 'LEMPort'
				switch( signalIndex )
				{
				case LEMProtocol::Base::rti_moveElevatorDown:
					chain11_ignoreMoveDown();
					return;
				case LEMProtocol::Base::rti_stopElevator:
					chain5_stop();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'moveTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain7_arriveAtFloor();
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

const RTActor_class * ElevatorMotor_Actor::getActorData( void ) const
{
	return &ElevatorMotor_Actor::rtg_class;
}

const RTActor_class ElevatorMotor_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 4
  , ElevatorMotor_Actor::rtg_parent_state
  , &ElevatorMotor
  , 0
  , (const RTComponentDescriptor *)0
  , 3
  , ElevatorMotor_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , ElevatorMotor_Actor::rtg_ElevatorMotor_fields
};

const RTStateId ElevatorMotor_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
};

const RTPortDescriptor ElevatorMotor_Actor::rtg_ports[] =
{
	{
		"LEMPort"
	  , (const char *)0
	  , &LEMProtocol::Base::rt_class
	  , RTOffsetOf( ElevatorMotor_Actor, ElevatorMotor_Actor::LEMPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"moveTimer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( ElevatorMotor_Actor, ElevatorMotor_Actor::moveTimer )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( ElevatorMotor_Actor, ElevatorMotor_Actor::log )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor ElevatorMotor_Actor::rtg_ElevatorMotor_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( ElevatorMotor_Actor, id )
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
