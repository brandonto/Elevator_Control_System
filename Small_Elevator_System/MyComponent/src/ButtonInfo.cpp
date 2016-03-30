// {{{RME classifier 'Logical View::ButtonInfo'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ButtonInfo.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ButtonInfo.h>

// {{{RME tool 'OT::Cpp' property 'ImplementationPreface'
// {{{USR

// }}}USR
// }}}RME

static void rtg_ButtonInfo_init( const RTObject_class * type, ButtonInfo * target )
{
	(void)new( target ) ButtonInfo;
}

static void rtg_ButtonInfo_copy( const RTObject_class * type, ButtonInfo * target, const ButtonInfo * source )
{
	(void)new( target ) ButtonInfo( *source );
}

static void rtg_ButtonInfo_destroy( const RTObject_class * type, ButtonInfo * target )
{
	target->~ButtonInfo();
}

const RTFieldDescriptor rtg_ButtonInfo_fields[] =
{
	// {{{RME classAttribute 'floorId'
	{
		"floorId"
	  , RTOffsetOf( ButtonInfo, floorId )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'floorNum'
  , {
		"floorNum"
	  , RTOffsetOf( ButtonInfo, floorNum )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_int
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'floorButton'
  , {
		"floorButton"
	  , RTOffsetOf( ButtonInfo, floorButton )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
	// {{{RME classAttribute 'upDir'
  , {
		"upDir"
	  , RTOffsetOf( ButtonInfo, upDir )
		// {{{RME tool 'OT::CppTargetRTS' property 'TypeDescriptor'
	  , &RTType_bool
		// }}}RME
		// {{{RME tool 'OT::CppTargetRTS' property 'GenerateTypeModifier'
	  , (const RTTypeModifier *)0
		// }}}RME
	}
	// }}}RME
};

const RTObject_class RTType_ButtonInfo =
{
	(const RTObject_class *)0
  , (RTSuperAccessFunction)0
  , "ButtonInfo"
  , (RTVersionId)0
  , (RTFieldOffset)sizeof( ButtonInfo )
  , (RTInitFunction)rtg_ButtonInfo_init
  , (RTCopyFunction)rtg_ButtonInfo_copy
#if OBJECT_DECODE
  , RTstruct_decode
#endif
#if OBJECT_ENCODE
  , RTstruct_encode
#endif
  , (RTDestroyFunction)rtg_ButtonInfo_destroy
  , 4
  , rtg_ButtonInfo_fields
};

// {{{RME tool 'OT::Cpp' property 'GenerateDefaultConstructor'
ButtonInfo::ButtonInfo( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateDestructor'
ButtonInfo::~ButtonInfo( void )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateCopyConstructor'
ButtonInfo::ButtonInfo( const ButtonInfo & rtg_arg )
	: floorId( rtg_arg.floorId )
	, floorNum( rtg_arg.floorNum )
	, floorButton( rtg_arg.floorButton )
	, upDir( rtg_arg.upDir )
{
}
// }}}RME

// {{{RME tool 'OT::Cpp' property 'GenerateAssignmentOperator'
ButtonInfo & ButtonInfo::operator=( const ButtonInfo & rtg_arg )
{
	if( this != &rtg_arg )
	{
		floorId = rtg_arg.floorId;
		floorNum = rtg_arg.floorNum;
		floorButton = rtg_arg.floorButton;
		upDir = rtg_arg.upDir;
	}
	return *this;
}
// }}}RME

#if OBJECT_DECODE
RTTypeInstaller rtg_ButtonInfo_installer( RTType_ButtonInfo );
#endif

// {{{RME tool 'OT::Cpp' property 'ImplementationEnding'
// {{{USR

// }}}USR
// }}}RME

// }}}RME
