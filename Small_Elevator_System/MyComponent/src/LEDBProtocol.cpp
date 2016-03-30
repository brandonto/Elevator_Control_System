// {{{RME classifier 'Logical View::LEDBProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "LEDBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEDBProtocol.h>

const RTProtocolDescriptor LEDBProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEDBProtocol::Conjugate::rt_class
  , "LEDBProtocol"
  , 0
  , 2
  , LEDBProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEDBProtocol::Base::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , LEDBProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEDBProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor LEDBProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEDBProtocol::Base::rt_class
  , "LEDBProtocol"
  , 0
  , 3
  , LEDBProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEDBProtocol::Conjugate::rt_signals[] =
{
	{
		"doorButtonPressed"
	  , &RTType_int
	  , LEDBProtocol::Conjugate::rti_doorButtonPressed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEDBProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEDBProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
