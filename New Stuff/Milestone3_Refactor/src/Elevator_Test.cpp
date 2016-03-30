// {{{RME classifier 'Logical View::Elevator_Test'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Elevator_Test.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Elevator_Test.h>

const RTProtocolDescriptor Elevator_Test::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Elevator_Test::Conjugate::rt_class
  , "Elevator_Test"
  , 0
  , 3
  , Elevator_Test::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Elevator_Test::Base::rt_signals[] =
{
	{
		"TEST_Doors_Open"
	  , &RTType_bool
	  , Elevator_Test::Base::rti_TEST_Doors_Open
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Elevator_Test::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Elevator_Test::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor Elevator_Test::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Elevator_Test::Base::rt_class
  , "Elevator_Test"
  , 0
  , 2
  , Elevator_Test::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Elevator_Test::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , Elevator_Test::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Elevator_Test::Conjugate::rti_rtUnbound
	}
};

// }}}RME
