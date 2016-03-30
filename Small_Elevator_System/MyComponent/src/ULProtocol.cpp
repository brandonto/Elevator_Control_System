// {{{RME classifier 'Logical View::ULProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "ULProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ULProtocol.h>

const RTProtocolDescriptor ULProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &ULProtocol::Conjugate::rt_class
  , "ULProtocol"
  , 0
  , 3
  , ULProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor ULProtocol::Base::rt_signals[] =
{
	{
		"pressElevatorButton"
	  , &RTType_int
	  , ULProtocol::Base::rti_pressElevatorButton
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , ULProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , ULProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor ULProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &ULProtocol::Base::rt_class
  , "ULProtocol"
  , 0
  , 2
  , ULProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor ULProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , ULProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , ULProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
