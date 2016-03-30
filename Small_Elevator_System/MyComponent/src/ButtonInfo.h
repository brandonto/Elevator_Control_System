// {{{RME classifier 'Logical View::ButtonInfo'

#ifndef ButtonInfo_H
#define ButtonInfo_H

#ifdef PRAGMA
#pragma interface "ButtonInfo.h"
#endif

#include <RTSystem/MyComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTObject_class RTType_ButtonInfo;

class ButtonInfo
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
	// {{{RME classAttribute 'floorId'
	int floorId;
	// }}}RME
	// {{{RME classAttribute 'floorNum'
	int floorNum;
	// }}}RME
	// {{{RME classAttribute 'floorButton'
	bool floorButton;
	// }}}RME
	// {{{RME classAttribute 'upDir'
	bool upDir;
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
	ButtonInfo( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
	virtual ~ButtonInfo( void );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
	ButtonInfo( const ButtonInfo & rtg_arg );
	// }}}RME
	// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
	ButtonInfo & operator=( const ButtonInfo & rtg_arg );
	// }}}RME
};

struct RTTypedValue_ButtonInfo
{
	const void * data;
	const RTObject_class * type;
	inline RTTypedValue_ButtonInfo( const ButtonInfo & rtg_value )
		: data( &rtg_value ), type( &RTType_ButtonInfo )
	{
	}
	inline RTTypedValue_ButtonInfo( const ButtonInfo & rtg_value, const RTObject_class * rtg_type )
		: data( &rtg_value ), type( rtg_type )
	{
	}
	inline ~RTTypedValue_ButtonInfo( void )
	{
	}
};

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ButtonInfo_H */

// }}}RME
