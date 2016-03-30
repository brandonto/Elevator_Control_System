// {{{RME classifier 'Logical View::FloorStatus'

#ifndef FloorStatus_H
#define FloorStatus_H

#ifdef PRAGMA
#pragma interface "FloorStatus.h"
#endif

#include <RTSystem/MyComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_FloorStatus;

class FloorStatus
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
	// {{{RME classAttribute 'upPressed'
	bool upPressed;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	FloorStatus( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~FloorStatus( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	FloorStatus( const FloorStatus & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	FloorStatus & operator=( const FloorStatus & rtg_arg );
	// }}}RME
};

struct RTTypedValue_FloorStatus
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_FloorStatus( const FloorStatus & rtg_value )
		: data( &rtg_value ), type( &RTType_FloorStatus )
	{
	}
	inline RTTypedValue_FloorStatus( const FloorStatus & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_FloorStatus( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* FloorStatus_H */

// }}}RME
