// {{{RME classifier 'Logical View::System_Constants'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "System_Constants.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <System_Constants.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_System_Constants_init( const RTObject_class * type, System_Constants * target )
{
	(void)new( target ) System_Constants;
}

static void rtg_System_Constants_copy( const RTObject_class * type, System_Constants * target, const System_Constants * source )
{
	(void)new( target ) System_Constants( *source );
}

static void rtg_System_Constants_destroy( const RTObject_class * type, System_Constants * target )
{
	target->~System_Constants();
}

const RTObject_class RTType_System_Constants =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "System_Constants"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( System_Constants )
  , (RTInitFunction)rtg_System_Constants_init
  , (RTCopyFunction)rtg_System_Constants_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_System_Constants_destroy
  , 0
  , (const RTFieldDescriptor *)0
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
System_Constants::System_Constants( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
System_Constants::~System_Constants( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
System_Constants::System_Constants( const System_Constants & rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
System_Constants & System_Constants::operator=( const System_Constants & rtg_arg )
{
	if( this != &rtg_arg )
	{
	}
	return *this;
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_System_Constants_installer( RTType_System_Constants );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
