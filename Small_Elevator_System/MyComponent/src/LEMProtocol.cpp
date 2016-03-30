// {{{RME classifier 'Logical View::LEMProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "LEMProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEMProtocol.h>

const RTProtocolDescriptor LEMProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEMProtocol::Conjugate::rt_class
  , "LEMProtocol"
  , 0
  , 6
  , LEMProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEMProtocol::Base::rt_signals[] =
{
	{
		"init"
	  , (const RTObject_class *)0
	  , LEMProtocol::Base::rti_init
	}
  , {
		"moveElevatorDown"
	  , &RTType_void
	  , LEMProtocol::Base::rti_moveElevatorDown
	}
  , {
		"moveElevatorUp"
	  , &RTType_void
	  , LEMProtocol::Base::rti_moveElevatorUp
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEMProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEMProtocol::Base::rti_rtUnbound
	}
  , {
		"stopElevator"
	  , &RTType_void
	  , LEMProtocol::Base::rti_stopElevator
	}
};

const RTProtocolDescriptor LEMProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEMProtocol::Base::rt_class
  , "LEMProtocol"
  , 0
  , 3
  , LEMProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEMProtocol::Conjugate::rt_signals[] =
{
	{
		"arrivedAtFloor"
	  , &RTType_void
	  , LEMProtocol::Conjugate::rti_arrivedAtFloor
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEMProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEMProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
