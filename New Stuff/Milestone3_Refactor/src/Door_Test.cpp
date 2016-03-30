// {{{RME classifier 'Logical View::Door_Test'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Door_Test.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Door_Test.h>

const RTProtocolDescriptor Door_Test::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Door_Test::Conjugate::rt_class
  , "Door_Test"
  , 0
  , 4
  , Door_Test::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Door_Test::Base::rt_signals[] =
{
	{
		"TEST_Command_Door_Open"
	  , &RTType_bool
	  , Door_Test::Base::rti_TEST_Command_Door_Open
	}
  , {
		"TEST_Door_Obstructed"
	  , &RTType_bool
	  , Door_Test::Base::rti_TEST_Door_Obstructed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Door_Test::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Door_Test::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor Door_Test::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Door_Test::Base::rt_class
  , "Door_Test"
  , 0
  , 2
  , Door_Test::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Door_Test::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , Door_Test::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Door_Test::Conjugate::rti_rtUnbound
	}
};

// }}}RME
