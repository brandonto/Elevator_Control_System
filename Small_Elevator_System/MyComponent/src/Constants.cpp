// {{{RME classifier 'Logical View::Constants'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Constants.h"
#endif

#include <RTSystem/MyComponent.h>
#include <Constants.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_Constants_init( const RTObject_class * type, Constants * target )
{
	(void)new( target ) Constants;
}

static void rtg_Constants_copy( const RTObject_class * type, Constants * target, const Constants * source )
{
	(void)new( target ) Constants( *source );
}

static void rtg_Constants_destroy( const RTObject_class * type, Constants * target )
{
	target->~Constants();
}

const RTObject_class RTType_Constants =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "Constants"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( Constants )
  , (RTInitFunction)rtg_Constants_init
  , (RTCopyFunction)rtg_Constants_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_Constants_destroy
  , 0
  , (const RTFieldDescriptor *)0
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
Constants::Constants( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
Constants::~Constants( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
Constants::Constants( const Constants & rtg_arg )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
Constants & Constants::operator=( const Constants & rtg_arg )
{
	if( this != &rtg_arg )
	{
	}
	return *this;
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_Constants_installer( RTType_Constants );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
