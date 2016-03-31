// {{{RME classifier 'Logical View::ULPort'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ULPort.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ULPort.h>

const RTProtocolDescriptor ULPort::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &ULPort::Conjugate::rt_class
  , "ULPort"
  , 0
  , 3
  , ULPort::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor ULPort::Base::rt_signals[] =
{
	{
		"forceDoorOpen"
	  , &RTType_void
	  , ULPort::Base::rti_forceDoorOpen
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , ULPort::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , ULPort::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor ULPort::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &ULPort::Base::rt_class
  , "ULPort"
  , 0
  , 2
  , ULPort::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor ULPort::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , ULPort::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , ULPort::Conjugate::rti_rtUnbound
	}
};

// }}}RME
