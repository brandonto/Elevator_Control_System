// {{{RME classifier 'Logical View::UDSProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UDSProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <UDSProtocol.h>

const RTProtocolDescriptor UDSProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &UDSProtocol::Conjugate::rt_class
  , "UDSProtocol"
  , 0
  , 3
  , UDSProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UDSProtocol::Base::rt_signals[] =
{
	{
		"impede"
	  , &RTType_void
	  , UDSProtocol::Base::rti_impede
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , UDSProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UDSProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor UDSProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &UDSProtocol::Base::rt_class
  , "UDSProtocol"
  , 0
  , 2
  , UDSProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UDSProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , UDSProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UDSProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
