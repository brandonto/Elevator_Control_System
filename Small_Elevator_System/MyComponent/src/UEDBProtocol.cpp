// {{{RME classifier 'Logical View::UEDBProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UEDBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <UEDBProtocol.h>

const RTProtocolDescriptor UEDBProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &UEDBProtocol::Conjugate::rt_class
  , "UEDBProtocol"
  , 0
  , 3
  , UEDBProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UEDBProtocol::Base::rt_signals[] =
{
	{
		"pressElevatorButton"
	  , &RTType_void
	  , UEDBProtocol::Base::rti_pressElevatorButton
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , UEDBProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UEDBProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor UEDBProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &UEDBProtocol::Base::rt_class
  , "UEDBProtocol"
  , 0
  , 2
  , UEDBProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UEDBProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , UEDBProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UEDBProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
