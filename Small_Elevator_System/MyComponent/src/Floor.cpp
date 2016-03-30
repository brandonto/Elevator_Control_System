// {{{RME classifier 'Logical View::Floor'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Floor.h"
#endif

#include <RTSystem/MyComponent.h>
#include <Floor.h>
#include <ButtonInfo.h>
extern const RTActorClass FloorButton;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"FCPort"
	  , &FCProtocol::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Floor_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Floor_Actor( _rts, _ref );
}

const RTActorClass Floor =
{
	(const RTActorClass *)0
  , "Floor"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_Floor_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
};

static const RTInterfaceDescriptor rtg_interfaces_floorButton[] =
{
	{
		"FBFPort"
	  , 1
	}
  , {
		"UFBPort"
	  , 0
	}
};

static const RTBindingDescriptor rtg_bindings_floorButton[] =
{
	{
		0
	  , &FBFProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

Floor_Actor::Floor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Floor_Actor::~Floor_Actor( void )
{
}

int Floor_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// FCPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &FCPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int Floor_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// floorButton
		switch( rtg_portId )
		{
		case 0:
			// FBFPort
			if( rtg_repIndex < 2 )
			{
				// FBFPort
				rtg_end.port = &FBFPort;
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
INLINE_METHODS void Floor_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	id = getIndex();

	initTimer.informIn(RTTimespec(0,100000));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB39B1032F:pressFloorButton'
INLINE_METHODS void Floor_Actor::transition2_pressFloorButton( const bool * rtdata, FBFProtocol::Conjugate * rtport )
{
	// {{{USR
	ButtonInfo bi;
	bi.floorId = id;
	bi.floorNum = id+1;
	bi.floorButton = true;
	bi.upDir = *rtdata;
	FCPort.floorButtonPressed(bi).send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FC0E900351:init'
INLINE_METHODS void Floor_Actor::transition3_init( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	int floorNum = id+1;
	for (int i=0; i<2; i++)
	{
		FBFPort.init(floorNum).sendAt(i);
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FC1E960292:clearButton'
INLINE_METHODS void Floor_Actor::transition4_clearButton( const ButtonInfo * rtdata, FCProtocol::Base * rtport )
{
	// {{{USR
	const ButtonInfo *bi = (ButtonInfo*)rtdata;
	FBFPort.clearButton().sendAt(bi->upDir);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Floor_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Floor_Actor::chain4_clearButton( void )
{
	// transition ':TOP:Ready:J56FC1E960292:clearButton'
	rtgChainBegin( 2, "clearButton" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_clearButton( (const ButtonInfo *)msg->data, (FCProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Floor_Actor::chain2_pressFloorButton( void )
{
	// transition ':TOP:Ready:J56FB39B1032F:pressFloorButton'
	rtgChainBegin( 2, "pressFloorButton" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_pressFloorButton( (const bool *)msg->data, (FBFProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Floor_Actor::chain3_init( void )
{
	// transition ':TOP:Ready:J56FC0E900351:init'
	rtgChainBegin( 2, "init" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_init( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Floor_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'FCPort'
				switch( signalIndex )
				{
				case FCProtocol::Base::rti_clearButton:
					chain4_clearButton();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'FBFPort'
				switch( signalIndex )
				{
				case FBFProtocol::Conjugate::rti_floorButtonPressed:
					chain2_pressFloorButton();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'initTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain3_init();
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

const RTActor_class * Floor_Actor::getActorData( void ) const
{
	return &Floor_Actor::rtg_class;
}

const RTActor_class Floor_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Floor_Actor::rtg_parent_state
  , &Floor
  , 1
  , Floor_Actor::rtg_capsule_roles
  , 4
  , Floor_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , Floor_Actor::rtg_Floor_fields
};

const RTStateId Floor_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor Floor_Actor::rtg_capsule_roles[] =
{
	{
		"floorButton"
	  , &FloorButton
	  , RTOffsetOf( Floor_Actor, floorButton )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 2 // cardinality
	  , 2
	  , rtg_interfaces_floorButton
	  , 1
	  , rtg_bindings_floorButton
	}
};

const RTPortDescriptor Floor_Actor::rtg_ports[] =
{
	{
		"FCPort"
	  , (const char *)0
	  , &FCProtocol::Base::rt_class
	  , RTOffsetOf( Floor_Actor, Floor_Actor::FCPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"FBFPort"
	  , (const char *)0
	  , &FBFProtocol::Conjugate::rt_class
	  , RTOffsetOf( Floor_Actor, Floor_Actor::FBFPort )
	  , 2 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"initTimer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( Floor_Actor, Floor_Actor::initTimer )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Floor_Actor, Floor_Actor::log )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor Floor_Actor::rtg_Floor_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( Floor_Actor, id )
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
