// {{{RME classifier 'Logical View::Elevator'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Elevator.h"
#endif

#include <RTSystem/MyComponent.h>
#include <Elevator.h>
#include <ButtonInfo.h>
#include <Constants.h>
extern const RTActorClass LocalController;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"EPPort"
	  , &EPProtocol::Conjugate::rt_class
	  , 1 // cardinality
	}
};

static RTActor * new_Elevator_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new Elevator_Actor( _rts, _ref );
}

const RTActorClass Elevator =
{
	(const RTActorClass *)0
  , "Elevator"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_Elevator_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
};

static const RTInterfaceDescriptor rtg_interfaces_localController[] =
{
	{
		"LEPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_localController[] =
{
	{
		0
	  , &LEProtocol::Conjugate::rt_class
	}
};

const RTTypeModifier rtg_tm_Elevator_Actor_es =
{
	RTNumberConstant
  , 1
  , 1
};

#define SUPER RTActor

Elevator_Actor::Elevator_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

Elevator_Actor::~Elevator_Actor( void )
{
}

// {{{RME operation 'update()'
void Elevator_Actor::update( void )
{
	// {{{USR
	//  1   2   3   4   5
	// [0] [0] [0] [1] [0]
	//      |
	//

	int i;
	es->nextDestFloor = -1;

	// Elevator moving up, set next destination floor to the nearest requested
	// floor in that direction
	if (es->direction == 1)
	{
		for (i=es->currentFloor; i<NUM_FLOORS; i++)
		{
			if (es->destinationFloors[i])
			{
				es->nextDestFloor = i+1;
				return;
			}
		}
	}
	// Elevator moving down, set next destination floor to the nearest requested
	// floor in that direction
	else if (es->direction == -1)
	{
		for (i=es->currentFloor-2; i>=0; i--)
		{
			if (es->destinationFloors[i])
			{
				es->nextDestFloor = i+1;
				return;
			}
		}
	}
	// Elevator not moving
	else
	{
		// Elevator is on the floor of a request
		if (es->destinationFloors[es->currentFloor-1])
		{
			es->nextDestFloor = es->currentFloor;
		}

		// Find the closest destination floor above the current floow
		int closestFloorAbove = -1;
		for (i=es->currentFloor; i<NUM_FLOORS; i++)
		{
			if (es->destinationFloors[i])
			{
				closestFloorAbove = i+1;
			}
		}

		// Find the closest destination floor below the current floor
		int closestFloorBelow = -1;
		for (i=es->currentFloor-2; i>=0; i--)
		{
			if (es->destinationFloors[i])
			{
				closestFloorBelow = i+1;
			}
		}

		// No destination floors found
		if (closestFloorAbove == -1 && closestFloorBelow == -1)
		{
			// No floor found below or above
			return;
		}
		// No floor found above, so move towards destination floor below
		else if (closestFloorAbove == -1)
		{
			es->nextDestFloor = closestFloorBelow;
			es->direction = -1;
			return;
		}
		// No floor found below, so move towards destination floor above
		else if (closestFloorBelow == -1)
		{
			es->nextDestFloor = closestFloorAbove;
			es->direction = 1;
			return;
		}
		// Floors above and below both found. So move to closer floor
		else
		{
			int aboveDiff = (closestFloorAbove - es->currentFloor);
			int belowDiff = (es->currentFloor - closestFloorBelow);
			
			if (aboveDiff < belowDiff)
			{
				es->nextDestFloor = closestFloorAbove;
				es->direction = 1;
				return;
			}
			else
			{
				es->nextDestFloor = closestFloorBelow;
				es->direction = -1;
				return;
			}
		}
	}
	// }}}USR
}
// }}}RME

int Elevator_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// EPPort
		if( rtg_repIndex < 1 )
		{
			rtg_end.port = &EPPort;
			rtg_end.index = rtg_repIndex;
			return 1;
		}
		break;
	default:
		break;
	}
	return RTActor::_followInV( rtg_end, rtg_portId, rtg_repIndex );
}

int Elevator_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// localController
		switch( rtg_portId )
		{
		case 0:
			// LEPort
			if( rtg_repIndex < 1 )
			{
				// LEPort
				rtg_end.port = &LEPort;
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
INLINE_METHODS void Elevator_Actor::transition1_Initial( const void * rtdata, RTProtocol * rtport )
{
	// {{{USR
	es = new ElevatorStatus();
	es->id = getIndex();
	es->direction = 0;
	es->currentFloor = 1;
	es->doorOpen = false;
	for (int i=0; i<NUM_FLOORS; i++)
	{
		es->destinationFloors[i] = 0;
	}
	es->emergencyBrakesOn = false;

	log.show("Elevator [");
	log.show(es->id);
	log.show("] created.\n");

	initTimer.informIn(RTTimespec(0,100000));
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FC070100AE:elevatorButtonPressed'
INLINE_METHODS void Elevator_Actor::transition2_elevatorButtonPressed( const ButtonInfo * rtdata, LEProtocol::Conjugate * rtport )
{
	// {{{USR
	const ButtonInfo *bi = (ButtonInfo *)rtdata;
	int mostRecentButton = bi->floorNum;
	log.show("Elevator [");
	log.show(es->id);
	log.show("] Button pressed for floor [");
	log.show(mostRecentButton);
	log.show("]\n");
	if (!es->destinationFloors[mostRecentButton-1])
	{
		es->mostRecentButton = mostRecentButton;
		es->destinationFloors[mostRecentButton-1] = 1;
		EPPort.elevatorButtonPressed(*bi).send();
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FC4E3D0305:arrivedAtFloor'
INLINE_METHODS void Elevator_Actor::transition3_arrivedAtFloor( const void * rtdata, LEProtocol::Conjugate * rtport )
{
	// {{{USR
	es->currentFloor += es->direction;
	if (es->nextDestFloor == es->currentFloor)
	{
		// Stop motor
		es->direction = 0;
		LEPort.moveElevator(0).send();

		// Update central controller
		if (es->destinationFloors[es->currentFloor-1]>RQ_TYPE_EB)
		{
			ButtonInfo bi;
			bi.floorNum = es->currentFloor;
			bi.floorId = bi.floorNum - 1;
			bi.floorButton = true;
			if (es->destinationFloors[es->currentFloor-1] == RQ_TYPE_FB_U)
			{
				bi.upDir = true;
			}
			else
			{
				bi.upDir = false;
			}
			EPPort.clearButton(bi).send();
		}

		// Clear destination floor
		es->destinationFloors[es->currentFloor-1] = 0;
		es->nextDestFloor = -1;

		// Open door
		LEPort.openDoor().send();
		LEPort.clearButton(es->currentFloor).send();

		log.show("Elevator [");
		log.show(es->id);
		log.show("] reached destination floor [");
		log.show(es->currentFloor);
		log.show("]\n");
	}
	else
	{
		log.show("Elevator [");
		log.show(es->id);
		log.show("] at floor [");
		log.show(es->currentFloor);
		log.show("]\n");
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB04610211:update'
INLINE_METHODS void Elevator_Actor::transition4_update( const void * rtdata, EPProtocol::Conjugate * rtport )
{
	// {{{USR
	update();
	if (es->nextDestFloor == es->currentFloor)
	{
		// Stop motor
		es->direction = 0;
		LEPort.moveElevator(0).send();

		// Update central controller
		if (es->destinationFloors[es->currentFloor-1]>RQ_TYPE_EB)
		{
			ButtonInfo bi;
			bi.floorNum = es->currentFloor;
			bi.floorId = bi.floorNum - 1;
			bi.floorButton = true;
			if (es->destinationFloors[es->currentFloor-1] == RQ_TYPE_FB_U)
			{
				bi.upDir = true;
			}
			else
			{
				bi.upDir = false;
			}
			EPPort.clearButton(bi).send();
		}

		// Clear destination floor
		es->destinationFloors[es->currentFloor-1] = 0;
		es->nextDestFloor = -1;

		// Open door
		LEPort.openDoor().send();
		LEPort.clearButton(es->currentFloor).send();

		log.show("Elevator [");
		log.show(es->id);
		log.show("] reached destination floor [");
		log.show(es->currentFloor);
		log.show("]\n");
	}
	else
	{
		if (!es->doorOpen)
		{
			LEPort.moveElevator(es->direction).send();
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB15A60330:doorClosed'
INLINE_METHODS void Elevator_Actor::transition5_doorClosed( const void * rtdata, LEProtocol::Conjugate * rtport )
{
	// {{{USR
	update();
	if (es->nextDestFloor == es->currentFloor)
	{
		// Stop motor
		es->direction = 0;
		LEPort.moveElevator(0).send();

		// Clear destination floor
		es->destinationFloors[es->currentFloor-1] = 0;
		es->nextDestFloor = -1;

		// Open door
		LEPort.openDoor().send();
		LEPort.clearButton(es->currentFloor).send();

		log.show("Elevator [");
		log.show(es->id);
		log.show("] reached destination floor [");
		log.show(es->currentFloor);
		log.show("]\n");
	}
	else
	{
		if (!es->doorOpen)
		{
			LEPort.moveElevator(es->direction).send();
		}
	}
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB25B10282:init'
INLINE_METHODS void Elevator_Actor::transition6_init( const void * rtdata, Timing::Base * rtport )
{
	// {{{USR
	EPPort.init(es).send();
	LEPort.init(es).send();
	// }}}USR
}
// }}}RME

INLINE_CHAINS void Elevator_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	transition1_Initial( msg->data, msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain2_elevatorButtonPressed( void )
{
	// transition ':TOP:Ready:J56FC070100AE:elevatorButtonPressed'
	rtgChainBegin( 2, "elevatorButtonPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_elevatorButtonPressed( (const ButtonInfo *)msg->data, (LEProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain3_arrivedAtFloor( void )
{
	// transition ':TOP:Ready:J56FC4E3D0305:arrivedAtFloor'
	rtgChainBegin( 2, "arrivedAtFloor" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_arrivedAtFloor( msg->data, (LEProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain5_doorClosed( void )
{
	// transition ':TOP:Ready:J56FB15A60330:doorClosed'
	rtgChainBegin( 2, "doorClosed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_doorClosed( msg->data, (LEProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain4_update( void )
{
	// transition ':TOP:Ready:J56FB04610211:update'
	rtgChainBegin( 2, "update" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_update( msg->data, (EPProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void Elevator_Actor::chain6_init( void )
{
	// transition ':TOP:Ready:J56FB25B10282:init'
	rtgChainBegin( 2, "init" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition6_init( msg->data, (Timing::Base *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void Elevator_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'LEPort'
				switch( signalIndex )
				{
				case LEProtocol::Conjugate::rti_elevatorButtonPressed:
					chain2_elevatorButtonPressed();
					return;
				case LEProtocol::Conjugate::rti_arrivedAtFloor:
					chain3_arrivedAtFloor();
					return;
				case LEProtocol::Conjugate::rti_doorClosed:
					chain5_doorClosed();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 2:
				// {{{RME port 'EPPort'
				switch( signalIndex )
				{
				case EPProtocol::Conjugate::rti_update:
					chain4_update();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 4:
				// {{{RME port 'initTimer'
				switch( signalIndex )
				{
				case Timing::Base::rti_timeout:
					chain6_init();
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

const RTActor_class * Elevator_Actor::getActorData( void ) const
{
	return &Elevator_Actor::rtg_class;
}

const RTActor_class Elevator_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , Elevator_Actor::rtg_parent_state
  , &Elevator
  , 1
  , Elevator_Actor::rtg_capsule_roles
  , 4
  , Elevator_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , Elevator_Actor::rtg_Elevator_fields
};

const RTStateId Elevator_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor Elevator_Actor::rtg_capsule_roles[] =
{
	{
		"localController"
	  , &LocalController
	  , RTOffsetOf( Elevator_Actor, localController )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 1 // cardinality
	  , 1
	  , rtg_interfaces_localController
	  , 1
	  , rtg_bindings_localController
	}
};

const RTPortDescriptor Elevator_Actor::rtg_ports[] =
{
	{
		"LEPort"
	  , (const char *)0
	  , &LEProtocol::Conjugate::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::LEPort )
	  , 1 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"EPPort"
	  , (const char *)0
	  , &EPProtocol::Conjugate::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::EPPort )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::log )
	  , 1 // cardinality
	  , 3
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"initTimer"
	  , (const char *)0
	  , &Timing::Base::rt_class
	  , RTOffsetOf( Elevator_Actor, Elevator_Actor::initTimer )
	  , 1 // cardinality
	  , 4
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor Elevator_Actor::rtg_Elevator_fields[] =
{
	// {{{RME classAttribute 'es'
	{
		"es"
	  , RTOffsetOf( Elevator_Actor, es )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_ElevatorStatus
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_Elevator_Actor_es
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
