// {{{RME classifier 'Logical View::FloorButton'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "FloorButton.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FloorButton.h>
#include <Constants.h>
extern const RTActorClass FloorButtonLamp;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"FBFPort"
	  , &FBFProtocol::Base::rt_class
	  , 1 // cardinality
	}
  , {
		"UFBPort"
	  , &UFBPort::Base::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_FloorButton_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new FloorButton_Actor( _rts, _ref );
}

const RTActorClass FloorButton =
{
	(const RTActorClass *)0
  , "FloorButton"
  , (RTVersionId)0
  , 2
  , rtg_relays
  , new_FloorButton_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Unpressed"
  , "Pressed"
  , "inactive"
  , "isActive"
};

static const RTInterfaceDescriptor rtg_interfaces_floorButtonLamp[] =
{
	{
		"FBLFBPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_floorButtonLamp[] =
{
	{
		0
	  , &FBLFBProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

FloorButton_Actor::FloorButton_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

FloorButton_Actor::~FloorButton_Actor( void )
{
}

int FloorButton_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// FBFPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &FBFPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	case 1:
		// UFBPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &UFBPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int FloorButton_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// floorButtonLamp
		switch( rtg_portId )
		{
		case 0:
			// FBLFBPort
			if( rtg_repIndex < 1 )
			{
				// FBLFBPort
				rtg_end.port = &FBLFBPort;
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

// {{{RME transition ':TOP:inactive:J56FC12190333:init'
INLINE_METHODS void FloorButton_Actor::transition1_init( const int * rtdata, FBFProtocol::Base * rtport )
{
	// {{{USR
	int floorNum = *rtdata;

	// All button initially active
	active = true;

	// First floor
	if (floorNum == 1)
	{
		// Bottom button
		if (!upDir)
		{
			active = false;
		}
	}
	// Top floor
	else if (floorNum == NUM_FLOORS)
	{
		if (upDir)
		{
			active = false;
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Unpressed:J56FC10680042:floorButtonPressed'
INLINE_METHODS void FloorButton_Actor::transition2_floorButtonPressed( const void * rtdata, UFBPort::Base * rtport )
{
	// {{{USR
	FBFPort.floorButtonPressed(upDir).send();
	FBLFBPort.light().send();
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Initial:Initial'
INLINE_METHODS void FloorButton_Actor::transition4_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	id = getIndex();
	upDir = id;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Pressed:J56FC1F2E039E:clearButton'
INLINE_METHODS void FloorButton_Actor::transition7_clearButton( const void * rtdata, FBFProtocol::Base * rtport )
{
	// {{{USR
	FBLFBPort.unlight().send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void FloorButton_Actor::chain4_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition4_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void FloorButton_Actor::chain2_floorButtonPressed( void )
{
	// transition ':TOP:Unpressed:J56FC10680042:floorButtonPressed'
	rtgChainBegin( 2, "floorButtonPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_floorButtonPressed( msg->data, (UFBPort::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void FloorButton_Actor::chain7_clearButton( void )
{
	// transition ':TOP:Pressed:J56FC1F2E039E:clearButton'
	rtgChainBegin( 3, "clearButton" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition7_clearButton( msg->data, (FBFProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void FloorButton_Actor::chain3_ignorePress( void )
{
	// transition ':TOP:Pressed:J56FC108503AC:ignorePress'
	rtgChainBegin( 3, "ignorePress" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 3 );
}

INLINE_CHAINS void FloorButton_Actor::chain1_init( void )
{
	// transition ':TOP:inactive:J56FC12190333:init'
	rtgChainBegin( 4, "init" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition1_init( (const int *)msg->data, (FBFProtocol::Base *)msg->sap() );
	rtgTransitionEnd();
	if( choicePoint1_isActive( (const int *)msg->data, (FBFProtocol::Base *)msg->sap() ) )
		chain5_True();
	else
		chain6_False();
}

// {{{RME choicePoint ':TOP:isActive'
INLINE_METHODS int FloorButton_Actor::choicePoint1_isActive( const int * rtdata, FBFProtocol::Base * rtport )
{
	// {{{USR
	return active;
	// }}}USR
}
// }}}RME

INLINE_CHAINS void FloorButton_Actor::chain5_True( void )
{
	// transition ':TOP:isActive:True'
	rtgChainBegin( 5, "True" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void FloorButton_Actor::chain6_False( void )
{
	// transition ':TOP:isActive:False'
	rtgChainBegin( 5, "False" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

INLINE_CHAINS void FloorButton_Actor::chain8_ignorePress( void )
{
	// transition ':TOP:inactive:J56FC3B710098:ignorePress'
	rtgChainBegin( 4, "ignorePress" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 4 );
}

void FloorButton_Actor::rtsBehavior( int signalIndex, int portIndex )
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
					chain4_Initial();
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
			// {{{RME state ':TOP:Unpressed'
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
				// {{{RME port 'UFBPort'
				switch( signalIndex )
				{
				case UFBPort::Base::rti_pressFloorButton:
					chain2_floorButtonPressed();
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
			// {{{RME state ':TOP:Pressed'
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
				// {{{RME port 'FBFPort'
				switch( signalIndex )
				{
				case FBFProtocol::Base::rti_clearButton:
					chain7_clearButton();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'UFBPort'
				switch( signalIndex )
				{
				case UFBPort::Base::rti_pressFloorButton:
					chain3_ignorePress();
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
			// {{{RME state ':TOP:inactive'
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
				// {{{RME port 'FBFPort'
				switch( signalIndex )
				{
				case FBFProtocol::Base::rti_init:
					chain1_init();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'UFBPort'
				switch( signalIndex )
				{
				case UFBPort::Base::rti_pressFloorButton:
					chain8_ignorePress();
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

const RTActor_class * FloorButton_Actor::getActorData( void ) const
{
	return &FloorButton_Actor::rtg_class;
}

const RTActor_class FloorButton_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 4
  , FloorButton_Actor::rtg_parent_state
  , &FloorButton
  , 1
  , FloorButton_Actor::rtg_capsule_roles
  , 4
  , FloorButton_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 3
  , FloorButton_Actor::rtg_FloorButton_fields
};

const RTStateId FloorButton_Actor::rtg_parent_state[] =
{
	0
  , 1
  , 1
  , 1
};

const RTComponentDescriptor FloorButton_Actor::rtg_capsule_roles[] =
{
	{
		"floorButtonLamp"
	  , &FloorButtonLamp
	  , RTOffsetOf( FloorButton_Actor, floorButtonLamp )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_floorButtonLamp
	  , 1
	  , rtg_bindings_floorButtonLamp
	}
};

const RTPortDescriptor FloorButton_Actor::rtg_ports[] =
{
	{
		"FBFPort"
	  , (const char *)0
	  , &FBFProtocol::Base::rt_class
	  , RTOffsetOf( FloorButton_Actor, FloorButton_Actor::FBFPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"UFBPort"
	  , (const char *)0
	  , &UFBPort::Base::rt_class
	  , RTOffsetOf( FloorButton_Actor, FloorButton_Actor::UFBPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( FloorButton_Actor, FloorButton_Actor::log )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"FBLFBPort"
	  , (const char *)0
	  , &FBLFBProtocol::Conjugate::rt_class
	  , RTOffsetOf( FloorButton_Actor, FloorButton_Actor::FBLFBPort )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor FloorButton_Actor::rtg_FloorButton_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( FloorButton_Actor, id )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'active'
  , {
		"active"
	  , RTOffsetOf( FloorButton_Actor, active )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'upDir'
  , {
		"upDir"
	  , RTOffsetOf( FloorButton_Actor, upDir )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
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
