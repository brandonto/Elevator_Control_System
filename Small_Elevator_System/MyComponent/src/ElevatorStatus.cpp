// {{{RME classifier 'Logical View::ElevatorStatus'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ElevatorStatus.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ElevatorStatus.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_ElevatorStatus_init( const RTObject_class * type, ElevatorStatus * target )
{
	(void)new( target ) ElevatorStatus;
}

static void rtg_ElevatorStatus_copy( const RTObject_class * type, ElevatorStatus * target, const ElevatorStatus * source )
{
	(void)new( target ) ElevatorStatus( *source );
}

static void rtg_ElevatorStatus_destroy( const RTObject_class * type, ElevatorStatus * target )
{
	target->~ElevatorStatus();
}

const RTTypeModifier rtg_tm_ElevatorStatus_destinationFloors =
{
	RTNumberConstant
  , (NUM_FLOORS)
  , 0
};

const RTFieldDescriptor rtg_ElevatorStatus_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( ElevatorStatus, id )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'direction'
  , {
		"direction"
	  , RTOffsetOf( ElevatorStatus, direction )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'currentFloor'
  , {
		"currentFloor"
	  , RTOffsetOf( ElevatorStatus, currentFloor )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'destinationFloors'
  , {
		"destinationFloors"
	  , RTOffsetOf( ElevatorStatus, destinationFloors[ 0 ] )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , &rtg_tm_ElevatorStatus_destinationFloors
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'nextDestFloor'
  , {
		"nextDestFloor"
	  , RTOffsetOf( ElevatorStatus, nextDestFloor )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'mostRecentButton'
  , {
		"mostRecentButton"
	  , RTOffsetOf( ElevatorStatus, mostRecentButton )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'doorOpen'
  , {
		"doorOpen"
	  , RTOffsetOf( ElevatorStatus, doorOpen )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'emergencyBrakesOn'
  , {
		"emergencyBrakesOn"
	  , RTOffsetOf( ElevatorStatus, emergencyBrakesOn )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

const RTObject_class RTType_ElevatorStatus =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "ElevatorStatus"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( ElevatorStatus )
  , (RTInitFunction)rtg_ElevatorStatus_init
  , (RTCopyFunction)rtg_ElevatorStatus_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_ElevatorStatus_destroy
  , 8
  , rtg_ElevatorStatus_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
ElevatorStatus::ElevatorStatus( void )
	: direction( 0 )
	, currentFloor( 1 )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
ElevatorStatus::~ElevatorStatus( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
ElevatorStatus::ElevatorStatus( const ElevatorStatus & rtg_arg )
	: id( rtg_arg.id )
	, direction( rtg_arg.direction )
	, currentFloor( rtg_arg.currentFloor )
	, nextDestFloor( rtg_arg.nextDestFloor )
	, mostRecentButton( rtg_arg.mostRecentButton )
	, doorOpen( rtg_arg.doorOpen )
	, emergencyBrakesOn( rtg_arg.emergencyBrakesOn )
{
	for( int rtg_destinationFloors_index = (NUM_FLOORS); --rtg_destinationFloors_index >= 0; )
		destinationFloors[ rtg_destinationFloors_index ] = rtg_arg.destinationFloors[ rtg_destinationFloors_index ];
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
ElevatorStatus & ElevatorStatus::operator=( const ElevatorStatus & rtg_arg )
{
	if( this != &rtg_arg )
	{
		id = rtg_arg.id;
		direction = rtg_arg.direction;
		currentFloor = rtg_arg.currentFloor;
		for( int rtg_destinationFloors_index = (NUM_FLOORS); --rtg_destinationFloors_index >= 0; )
			destinationFloors[ rtg_destinationFloors_index ] = rtg_arg.destinationFloors[ rtg_destinationFloors_index ];
		nextDestFloor = rtg_arg.nextDestFloor;
		mostRecentButton = rtg_arg.mostRecentButton;
		doorOpen = rtg_arg.doorOpen;
		emergencyBrakesOn = rtg_arg.emergencyBrakesOn;
	}
	return *this;
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_ElevatorStatus_installer( RTType_ElevatorStatus );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
