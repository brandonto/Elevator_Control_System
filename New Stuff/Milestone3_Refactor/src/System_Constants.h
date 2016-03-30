// {{{RME classifier 'Logical View::System_Constants'

#ifndef System_Constants_H
#define System_Constants_H

#ifdef PRAGMA
#pragma interface "System_Constants.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

// {{{RME classAttribute 'NUM_FLOORS'
#define NUM_FLOORS 10
// }}}RME

// {{{RME classAttribute 'NUM_ELEVATORS'
#define NUM_ELEVATORS 2
// }}}RME

extern const RTObject_class RTType_System_Constants;

class System_Constants
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
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	System_Constants( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~System_Constants( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	System_Constants( const System_Constants & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	System_Constants & operator=( const System_Constants & rtg_arg );
	// }}}RME
};

struct RTTypedValue_System_Constants
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_System_Constants( const System_Constants & rtg_value )
		: data( &rtg_value ), type( &RTType_System_Constants )
	{
	}
	inline RTTypedValue_System_Constants( const System_Constants & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_System_Constants( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* System_Constants_H */

// }}}RME
