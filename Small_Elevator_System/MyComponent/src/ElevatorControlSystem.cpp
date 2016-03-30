// {{{RME classifier 'Logical View::ElevatorControlSystem'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ElevatorControlSystem.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ElevatorControlSystem.h>
#include <EPProtocol.h>
extern const RTActorClass CentralController;
extern const RTActorClass Elevator;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static RTActor * new_ElevatorControlSystem_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new ElevatorControlSystem_Actor( _rts, _ref );
}

const RTActorClass ElevatorControlSystem =
{
	(const RTActorClass *)0
  , "ElevatorControlSystem"
  , (RTVersionId)0
  , 0
  , (const RTRelayDescriptor *)0
  , new_ElevatorControlSystem_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
};

static const RTInterfaceDescriptor rtg_interfaces_centralController[] =
{
	{
		"EPPort"
	  , 2
	}
};

static const RTBindingDescriptor rtg_bindings_centralController[] =
{
	{
		0
	  , &EPProtocol::Conjugate::rt_class
	}
};

static const RTInterfaceDescriptor rtg_interfaces_elevator[] =
{
	{
		"EPPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_elevator[] =
{
	{
		0
	  , &EPProtocol::Conjugate::rt_class
	}
};

#define SUPER RTActor

ElevatorControlSystem_Actor::ElevatorControlSystem_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

ElevatorControlSystem_Actor::~ElevatorControlSystem_Actor( void )
{
}

int ElevatorControlSystem_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// centralController
		switch( rtg_portId )
		{
		case 0:
			// EPPort
			if( rtg_repIndex < 2 )
			{
				// elevator/EPPort
				return elevator._followIn( rtg_end, 0, rtg_repIndex );
			}
			break;
		default:
			break;
		}
	case 2:
		// elevator
		switch( rtg_portId )
		{
		case 0:
			// EPPort
			if( rtg_repIndex < 2 )
			{
				// centralController/EPPort
				return centralController._followIn( rtg_end, 0, rtg_repIndex );
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

void ElevatorControlSystem_Actor::rtsBehavior( int signalIndex, int portIndex )
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
			unexpectedMessage();
			return;
			// }}}RME
		default:
			unexpectedState();
			return;
		}
}

const RTActor_class * ElevatorControlSystem_Actor::getActorData( void ) const
{
	return &ElevatorControlSystem_Actor::rtg_class;
}

const RTActor_class ElevatorControlSystem_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 1
  , ElevatorControlSystem_Actor::rtg_parent_state
  , &ElevatorControlSystem
  , 2
  , ElevatorControlSystem_Actor::rtg_capsule_roles
  , 0
  , (const RTPortDescriptor *)0
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 0
  , (const RTFieldDescriptor *)0
};

const RTStateId ElevatorControlSystem_Actor::rtg_parent_state[] =
{
	0
};

const RTComponentDescriptor ElevatorControlSystem_Actor::rtg_capsule_roles[] =
{
	{
		"centralController"
	  , &CentralController
	  , RTOffsetOf( ElevatorControlSystem_Actor, centralController )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_centralController
	  , 1
	  , rtg_bindings_centralController
	}
  , {
		"elevator"
	  , &Elevator
	  , RTOffsetOf( ElevatorControlSystem_Actor, elevator )
	  , 2
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 2 // cardinality
	  , 1
	  , rtg_interfaces_elevator
	  , 1
	  , rtg_bindings_elevator
	}
};

#undef SUPER

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
