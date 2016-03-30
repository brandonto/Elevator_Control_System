// {{{RME classifier 'Logical View::ElevatorStatus'

#ifndef ElevatorStatus_H
#define ElevatorStatus_H

#ifdef PRAGMA
#pragma interface "ElevatorStatus.h"
#endif

#include <RTSystem/MyComponent.h>
#include <Constants.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'RQ_TYPE_NONE'
#define RQ_TYPE_NONE 0
// }}}RME

// {{{RME classAttribute 'RQ_TYPE_EB'
#define RQ_TYPE_EB 1
// }}}RME

// {{{RME classAttribute 'RQ_TYPE_FB_U'
#define RQ_TYPE_FB_U 2
// }}}RME

// {{{RME classAttribute 'RQ_TYPE_FB_D'
#define RQ_TYPE_FB_D 3
// }}}RME

extern const RTObject_class RTType_ElevatorStatus;

class ElevatorStatus
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

public:
	// {{{RME classAttribute 'id'
	int id;
	// }}}RME
	// {{{RME classAttribute 'direction'
	int direction;
	// }}}RME
	// {{{RME classAttribute 'currentFloor'
	int currentFloor;
	// }}}RME
	// {{{RME classAttribute 'destinationFloors'
	int destinationFloors[ NUM_FLOORS ];
	// }}}RME
	// {{{RME classAttribute 'nextDestFloor'
	int nextDestFloor;
	// }}}RME
	// {{{RME classAttribute 'mostRecentButton'
	int mostRecentButton;
	// }}}RME
	// {{{RME classAttribute 'doorOpen'
	bool doorOpen;
	// }}}RME
	// {{{RME classAttribute 'emergencyBrakesOn'
	bool emergencyBrakesOn;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	ElevatorStatus( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~ElevatorStatus( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	ElevatorStatus( const ElevatorStatus & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	ElevatorStatus & operator=( const ElevatorStatus & rtg_arg );
	// }}}RME
};

struct RTTypedValue_ElevatorStatus
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_ElevatorStatus( const ElevatorStatus & rtg_value )
		: data( &rtg_value ), type( &RTType_ElevatorStatus )
	{
	}
	inline RTTypedValue_ElevatorStatus( const ElevatorStatus & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_ElevatorStatus( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ElevatorStatus_H */

// }}}RME
