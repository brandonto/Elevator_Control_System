// {{{RME classifier 'Logical View::UFProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "UFProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <UFProtocol.h>

const RTProtocolDescriptor UFProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &UFProtocol::Conjugate::rt_class
  , "UFProtocol"
  , 0
  , 3
  , UFProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UFProtocol::Base::rt_signals[] =
{
	{
		"pressFloorButton"
	  , &RTType_bool
	  , UFProtocol::Base::rti_pressFloorButton
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , UFProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UFProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor UFProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &UFProtocol::Base::rt_class
  , "UFProtocol"
  , 0
  , 2
  , UFProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor UFProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , UFProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , UFProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
