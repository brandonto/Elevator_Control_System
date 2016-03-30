// {{{RME classifier 'Logical View::UEBProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UEBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <UEBProtocol.h>

const RTProtocolDescriptor UEBProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &UEBProtocol::Conjugate::rt_class
  , "UEBProtocol"
  , 0
  , 3
  , UEBProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UEBProtocol::Base::rt_signals[] =
{
	{
		"pressElevatorButton"
	  , &RTType_void
	  , UEBProtocol::Base::rti_pressElevatorButton
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , UEBProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UEBProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor UEBProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &UEBProtocol::Base::rt_class
  , "UEBProtocol"
  , 0
  , 2
  , UEBProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UEBProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , UEBProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UEBProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
