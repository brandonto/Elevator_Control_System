// {{{RME classifier 'Logical View::UFBPort'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UFBPort.h"
#endif

#include <RTSystem/MyComponent.h>
#include <UFBPort.h>

const RTProtocolDescriptor UFBPort::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &UFBPort::Conjugate::rt_class
  , "UFBPort"
  , 0
  , 3
  , UFBPort::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UFBPort::Base::rt_signals[] =
{
	{
		"pressFloorButton"
	  , &RTType_void
	  , UFBPort::Base::rti_pressFloorButton
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , UFBPort::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UFBPort::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor UFBPort::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &UFBPort::Base::rt_class
  , "UFBPort"
  , 0
  , 2
  , UFBPort::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UFBPort::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , UFBPort::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UFBPort::Conjugate::rti_rtUnbound
	}
};

// }}}RME
