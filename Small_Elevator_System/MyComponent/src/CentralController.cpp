// {{{RME classifier 'Logical View::CentralController'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "CentralController.h"
#endif

#include <RTSystem/MyComponent.h>
#include <CentralController.h>
#include <ButtonInfo.h>
#include <ElevatorStatus.h>
extern const RTActorClass Floor;

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static const RTRelayDescriptor rtg_relays[] =
{
	{
		"EPPort"
	  , &EPProtocol::Conjugate::rt_class
	  , 3 // cardinality
	}
};

static RTActor * new_CentralController_Actor( RTController * _rts, RTActorRef * _ref )
{
	return new CentralController_Actor( _rts, _ref );
}

const RTActorClass CentralController =
{
	(const RTActorClass *)0
  , "CentralController"
  , (RTVersionId)0
  , 1
  , rtg_relays
  , new_CentralController_Actor
};

static const char * const rtg_state_names[] =
{
	"TOP"
  , "Ready"
};

static const RTInterfaceDescriptor rtg_interfaces_floor[] =
{
	{
		"FCPort"
	  , 1
	}
};

static const RTBindingDescriptor rtg_bindings_floor[] =
{
	{
		0
	  , &FCProtocol::Conjugate::rt_class
	}
};

const RTTypeModifier rtg_tm_CentralController_Actor_esList =
{
	RTNumberConstant
  , (NUM_ELEVATORS)
  , 1
};

#define SUPER RTActor

CentralController_Actor::CentralController_Actor( RTController * rtg_rts, RTActorRef * rtg_ref )
	: RTActor( rtg_rts, rtg_ref )
{
}

CentralController_Actor::~CentralController_Actor( void )
{
}

// {{{RME operation 'schedule(int,bool)'
void CentralController_Actor::schedule( int floorId, bool upDir )
{
	// {{{USR
	int i, j;
	int floorNum = floorId+1;

	//
	// ==============================================================================
	// Algorithm
	// ==============================================================================
	//
	// Compute suitability score for each elevator with the following algorithm:
	//
	// (1) Elevator heading towards floor, same direction of button pressed
	//	 score = ((NUM_FLOORS - 1) + 2) - DIFF
	//
	// (2) Elevator heading towards floor, opposite direction of button pressed
	//	 score = ((NUM_FLOORS - 1) + 2) - DIFF
	//
	// (3) Elevator headind away from floor
	//	 score = 1
	//
	// Assign floor to elevator with the highest suitability score.
	//
	// If suitability score of all elevators is 1, then assign floor to elevator that
	// is closest to it's last destination
	//

	int suitabilityScore[NUM_ELEVATORS];
	for (i=0; i<NUM_ELEVATORS; i++)
	{
		if (esList[i]->emergencyBrakesOn)
		{
			continue;
		}

		// Special Case (1), elevator is not moving
		if (esList[i]->direction == 0)
		{
			suitabilityScore[i] = ((NUM_FLOORS - 1) + 2) - abs(esList[i]->currentFloor - floorNum) + 4;
		}
		// Case (1)
		else if (((esList[i]->currentFloor >= floorNum) && (esList[i]->direction == -1) && (!upDir && (esList[i]->direction == -1))) ||
			((esList[i]->currentFloor < floorNum) && (esList[i]->direction == 1) && (upDir && (esList[i]->direction == 1))))
		{
			suitabilityScore[i] = ((NUM_FLOORS - 1) + 2) - abs(esList[i]->currentFloor - floorNum) + 3;
		}
		// Case (2)
		else if (((esList[i]->currentFloor >= floorNum) && (esList[i]->direction == -1)) ||
			((esList[i]->currentFloor < floorNum) && (esList[i]->direction == 1)))
		{
			suitabilityScore[i] = ((NUM_FLOORS - 1) + 1) - abs(esList[i]->currentFloor - floorNum);
		}
		// Case (3)
		else
		{
			suitabilityScore[i] = 1;
		}
	}

	// Calculate the highest suitability score
	int highestSuitabilityScore = 1;
	int indexOfHighest = -1;
	for (i=0; i<NUM_ELEVATORS; i++)
	{
		if (esList[i]->emergencyBrakesOn)
		{
			continue;
		}

		if (suitabilityScore[i] > highestSuitabilityScore)
		{
			highestSuitabilityScore = suitabilityScore[i];
			indexOfHighest = i;
		}
	}

	// If a highest suitability score was found
	if (indexOfHighest != -1)
	{
		if (!esList[indexOfHighest]->emergencyBrakesOn)
		{
			esList[indexOfHighest]->destinationFloors[floorId] = upDir?RQ_TYPE_FB_U:RQ_TYPE_FB_D;
			log.show("Floor number [");
			log.show(floorNum);
			log.show("] has been added to Elevator [");
			log.show(esList[indexOfHighest]->id);
			log.show("]'s list of destination floors.\n");
			EPPort.update().sendAt(esList[indexOfHighest]->id);
			return;
		}
	}


	// Handle the case where no elevators are suitable by adding it to elevator that is closest
	// to it's last destination
	int distanceToLastDest[NUM_ELEVATORS];
	for (i=0; i<NUM_ELEVATORS; i++)
	{
		if (esList[i]->emergencyBrakesOn)
		{
			continue;
		}

		distanceToLastDest[i] = NUM_FLOORS;	
		if (esList[i]->direction == 1)
		{
			for (int j=NUM_FLOORS-1; j>esList[i]->currentFloor; j--)
			{
				if (esList[i]->destinationFloors[j])
				{
					distanceToLastDest[i] = j - esList[i]->currentFloor;
					break;
				}
			}
		}
		else if (esList[i]->direction == -1)
		{
			for (int j=0; j<esList[i]->currentFloor-1; j--)
			{
				if (esList[i]->destinationFloors[j])
				{
					distanceToLastDest[i] = esList[i]->currentFloor - j;
					break;
				}
			}
		}
	}

	int lowestDistance = NUM_FLOORS;
	int indexOfLowest = -1;
	for (i=0; i<NUM_ELEVATORS; i++)
	{	
		if (esList[i]->emergencyBrakesOn)
		{
			continue;
		}

		if (distanceToLastDest[i] < lowestDistance)
		{
			lowestDistance = distanceToLastDest[i];
			indexOfLowest = i;
		}
	}

	if (indexOfLowest == -1)
	{
		return;
	}

	esList[indexOfLowest]->destinationFloors[floorId] = upDir?RQ_TYPE_FB_U:RQ_TYPE_FB_D;
	log.show("Floor number [");
	log.show(floorNum);
	log.show("] has been added to Elevator id [");
	log.show(esList[indexOfLowest]->id);
	log.show("]'s list of destination floors.\n");
	EPPort.update().sendAt(esList[indexOfLowest]->id);

	// }}}USR
}
// }}}RME

// {{{RME operation 'abs(int)'
int CentralController_Actor::abs( int n )
{
	// {{{USR
	return (n * ((n>0) - (n<0)));
	// }}}USR
}
// }}}RME

int CentralController_Actor::_followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_portId )
	{
	case 0:
		// EPPort
		if( rtg_repIndex < 3 )
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

int CentralController_Actor::_followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex )
{
	switch( rtg_compId )
	{
	case 1:
		// floor
		switch( rtg_portId )
		{
		case 0:
			// FCPort
			if( rtg_repIndex < 25 )
			{
				// FCPort
				rtg_end.port = &FCPort;
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

// {{{RME transition ':TOP:Ready:J56E0A85700B7:elevatorButtonPressed'
INLINE_METHODS void CentralController_Actor::transition2_elevatorButtonPressed( const ButtonInfo * rtdata, EPProtocol::Conjugate * rtport )
{
	// {{{USR
	EPPort.update().send();

	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB26CA0023:elevatorInit'
INLINE_METHODS void CentralController_Actor::transition3_elevatorInit( const void * rtdata, EPProtocol::Conjugate * rtport )
{
	// {{{USR
	ElevatorStatus *es = (ElevatorStatus*)rtdata;
	esList[es->id] = es;
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FB3A78010C:floorButtonPressed'
INLINE_METHODS void CentralController_Actor::transition4_floorButtonPressed( const ButtonInfo * rtdata, FCProtocol::Conjugate * rtport )
{
	// {{{USR
	const ButtonInfo *bi = (const ButtonInfo*)rtdata;
	schedule(bi->floorId, bi->upDir);
	// }}}USR
}
// }}}RME

// {{{RME transition ':TOP:Ready:J56FC1D970385:clearButton'
INLINE_METHODS void CentralController_Actor::transition5_clearButton( const ButtonInfo * rtdata, EPProtocol::Conjugate * rtport )
{
	// {{{USR
	const ButtonInfo *bi = (ButtonInfo *)rtdata;
	FCPort.clearButton(*bi).sendAt(bi->floorId);
	// }}}USR
}
// }}}RME

INLINE_CHAINS void CentralController_Actor::chain1_Initial( void )
{
	// transition ':TOP:Initial:Initial'
	rtgChainBegin( 1, "Initial" );
	rtgTransitionBegin();
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CentralController_Actor::chain3_elevatorInit( void )
{
	// transition ':TOP:Ready:J56FB26CA0023:elevatorInit'
	rtgChainBegin( 2, "elevatorInit" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition3_elevatorInit( msg->data, (EPProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CentralController_Actor::chain2_elevatorButtonPressed( void )
{
	// transition ':TOP:Ready:J56E0A85700B7:elevatorButtonPressed'
	rtgChainBegin( 2, "elevatorButtonPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition2_elevatorButtonPressed( (const ButtonInfo *)msg->data, (EPProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CentralController_Actor::chain5_clearButton( void )
{
	// transition ':TOP:Ready:J56FC1D970385:clearButton'
	rtgChainBegin( 2, "clearButton" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition5_clearButton( (const ButtonInfo *)msg->data, (EPProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

INLINE_CHAINS void CentralController_Actor::chain4_floorButtonPressed( void )
{
	// transition ':TOP:Ready:J56FB3A78010C:floorButtonPressed'
	rtgChainBegin( 2, "floorButtonPressed" );
	exitState( rtg_parent_state );
	rtgTransitionBegin();
	transition4_floorButtonPressed( (const ButtonInfo *)msg->data, (FCProtocol::Conjugate *)msg->sap() );
	rtgTransitionEnd();
	enterState( 2 );
}

void CentralController_Actor::rtsBehavior( int signalIndex, int portIndex )
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
				// {{{RME port 'EPPort'
				switch( signalIndex )
				{
				case EPProtocol::Conjugate::rti_init:
					chain3_elevatorInit();
					return;
				case EPProtocol::Conjugate::rti_elevatorButtonPressed:
					chain2_elevatorButtonPressed();
					return;
				case EPProtocol::Conjugate::rti_clearButton:
					chain5_clearButton();
					return;
				default:
					break;
				}
				break;
				// }}}RME
			case 3:
				// {{{RME port 'FCPort'
				switch( signalIndex )
				{
				case FCProtocol::Conjugate::rti_floorButtonPressed:
					chain4_floorButtonPressed();
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

const RTActor_class * CentralController_Actor::getActorData( void ) const
{
	return &CentralController_Actor::rtg_class;
}

const RTActor_class CentralController_Actor::rtg_class =
{
	(const RTActor_class *)0
  , rtg_state_names
  , 2
  , CentralController_Actor::rtg_parent_state
  , &CentralController
  , 1
  , CentralController_Actor::rtg_capsule_roles
  , 3
  , CentralController_Actor::rtg_ports
  , 0
  , (const RTLocalBindingDescriptor *)0
  , 1
  , CentralController_Actor::rtg_CentralController_fields
};

const RTStateId CentralController_Actor::rtg_parent_state[] =
{
	0
  , 1
};

const RTComponentDescriptor CentralController_Actor::rtg_capsule_roles[] =
{
	{
		"floor"
	  , &Floor
	  , RTOffsetOf( CentralController_Actor, floor )
	  , 1
	  , RTComponentDescriptor::Fixed
	  , 1
	  , 25 // cardinality
	  , 1
	  , rtg_interfaces_floor
	  , 1
	  , rtg_bindings_floor
	}
};

const RTPortDescriptor CentralController_Actor::rtg_ports[] =
{
	{
		"EPPort"
	  , (const char *)0
	  , &EPProtocol::Conjugate::rt_class
	  , RTOffsetOf( CentralController_Actor, CentralController_Actor::EPPort )
	  , 3 // cardinality
	  , 1
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityPublic
	}
  , {
		"log"
	  , (const char *)0
	  , &Log::Base::rt_class
	  , RTOffsetOf( CentralController_Actor, CentralController_Actor::log )
	  , 1 // cardinality
	  , 2
	  , RTPortDescriptor::KindSpecial + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
  , {
		"FCPort"
	  , (const char *)0
	  , &FCProtocol::Conjugate::rt_class
	  , RTOffsetOf( CentralController_Actor, CentralController_Actor::FCPort )
	  , 25 // cardinality
	  , 3
	  , RTPortDescriptor::KindWired + RTPortDescriptor::NotificationDisabled + RTPortDescriptor::RegisterNotPermitted + RTPortDescriptor::VisibilityProtected
	}
};

const RTFieldDescriptor CentralController_Actor::rtg_CentralController_fields[] =
{
	// {{{RME classAttribute 'esList'
	{
		"esList"
	  , RTOffsetOf( CentralController_Actor, esList[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_ElevatorStatus
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_CentralController_Actor_esList
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
