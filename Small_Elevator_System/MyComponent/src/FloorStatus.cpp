// {{{RME classifier 'Logical View::FloorStatus'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "FloorStatus.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FloorStatus.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_FloorStatus_init( const RTObject_class * type, FloorStatus * target )
{
	(void)new( target ) FloorStatus;
}

static void rtg_FloorStatus_copy( const RTObject_class * type, FloorStatus * target, const FloorStatus * source )
{
	(void)new( target ) FloorStatus( *source );
}

static void rtg_FloorStatus_destroy( const RTObject_class * type, FloorStatus * target )
{
	target->~FloorStatus();
}

const RTFieldDescriptor rtg_FloorStatus_fields[] =
{
	// {{{RME classAttribute 'id'
	{
		"id"
	  , RTOffsetOf( FloorStatus, id )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'upPressed'
  , {
		"upPressed"
	  , RTOffsetOf( FloorStatus, upPressed )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

const RTObject_class RTType_FloorStatus =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "FloorStatus"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( FloorStatus )
  , (RTInitFunction)rtg_FloorStatus_init
  , (RTCopyFunction)rtg_FloorStatus_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_FloorStatus_destroy
  , 2
  , rtg_FloorStatus_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
FloorStatus::FloorStatus( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
FloorStatus::~FloorStatus( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
FloorStatus::FloorStatus( const FloorStatus & rtg_arg )
	: id( rtg_arg.id )
	, upPressed( rtg_arg.upPressed )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
FloorStatus & FloorStatus::operator=( const FloorStatus & rtg_arg )
{
	if( this != &rtg_arg )
	{
		id = rtg_arg.id;
		upPressed = rtg_arg.upPressed;
	}
	return *this;
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_FloorStatus_installer( RTType_FloorStatus );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
