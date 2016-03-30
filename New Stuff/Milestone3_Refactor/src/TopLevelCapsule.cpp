// {{{RME classifier 'Logical View::TopLevelCapsule'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "TopLevelCapsule.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <TopLevelCapsule.h>
extern const RTActorClass Central_Coordinator;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_TopLevelCapsule_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new TopLevelCapsule_Actor( _rts, _ref );
}

const RTActorClass TopLevelCapsule =
{
	(const RTActorClass *)0
  , "TopLevelCapsule"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_TopLevelCapsule_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
};

static const RTInterfaceDescriptor rtg_interfaces_central_ControllerR1[] =
{
	{
		"F_Buttons_IN"
	  , 0
	}
  , {
		"Service_Modes_IN"
	  , 0
	}
};

#define SUPER RTActor

TopLevelCapsule_Actor::TopLevelCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

TopLevelCapsule_Actor::~TopLevelCapsule_Actor( void )
{
}

void TopLevelCapsule_Actor::rtsBehavior( int signalIndex, int portIndex )
{
	for( int stateIndex = getCurrentState(); ; )
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
					return;
				default:
					break;
				}
				break;
			default:
				break;
			}
			//unexpectedMessage();
			return;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * TopLevelCapsule_Actor::getActorData( void ) const
{
	return &TopLevelCapsule_Actor::rtg_class;
}

const RTActor_class TopLevelCapsule_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 1
  , TopLevelCapsule_Actor::rtg_parent_state
  , &TopLevelCapsule
  , 1
  , TopLevelCapsule_Actor::rtg_capsule_roles
  , 0
  , (const RTPortDescriptor *)0
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId TopLevelCapsule_Actor::rtg_parent_state[] =
{
	0
};

const RTComponentDescriptor TopLevelCapsule_Actor::rtg_capsule_roles[] =
{
	{
		"central_ControllerR1"
	  , &Central_Coordinator
	  , RTOffsetOf( TopLevelCapsule_Actor, central_ControllerR1 )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 2
	  , rtg_interfaces_central_ControllerR1
	  , 0
	  , (const RTBindingDescriptor *)0
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
