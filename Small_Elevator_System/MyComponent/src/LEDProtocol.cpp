// {{{RME classifier 'Logical View::LEDProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "LEDProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEDProtocol.h>

const RTProtocolDescriptor LEDProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEDProtocol::Conjugate::rt_class
  , "LEDProtocol"
  , 0
  , 5
  , LEDProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEDProtocol::Base::rt_signals[] =
{
	{
		"closeDoor"
	  , &RTType_void
	  , LEDProtocol::Base::rti_closeDoor
	}
  , {
		"init"
	  , (const RTObject_class *)0
	  , LEDProtocol::Base::rti_init
	}
  , {
		"openDoor"
	  , &RTType_void
	  , LEDProtocol::Base::rti_openDoor
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEDProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEDProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor LEDProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEDProtocol::Base::rt_class
  , "LEDProtocol"
  , 0
  , 3
  , LEDProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEDProtocol::Conjugate::rt_signals[] =
{
	{
		"doorClosed"
	  , &RTType_void
	  , LEDProtocol::Conjugate::rti_doorClosed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEDProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEDProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
