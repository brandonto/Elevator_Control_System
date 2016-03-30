// {{{RME classifier 'Logical View::Constants'

#ifndef Constants_H
#define Constants_H

#ifdef PRAGMA
#pragma interface "Constants.h"
#endif

#include <RTSystem/MyComponent.h>

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

extern const RTObject_class RTType_Constants;

class Constants
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
	Constants( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~Constants( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	Constants( const Constants & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	Constants & operator=( const Constants & rtg_arg );
	// }}}RME
};

struct RTTypedValue_Constants
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_Constants( const Constants & rtg_value )
		: data( &rtg_value ), type( &RTType_Constants )
	{
	}
	inline RTTypedValue_Constants( const Constants & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_Constants( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Constants_H */

// }}}RME
