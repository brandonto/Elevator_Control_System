// {{{RME classifier 'Logical View::LEBProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "LEBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEBProtocol.h>

const RTProtocolDescriptor LEBProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEBProtocol::Conjugate::rt_class
  , "LEBProtocol"
  , 0
  , 3
  , LEBProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEBProtocol::Base::rt_signals[] =
{
	{
		"clearButton"
	  , &RTType_void
	  , LEBProtocol::Base::rti_clearButton
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEBProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEBProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor LEBProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEBProtocol::Base::rt_class
  , "LEBProtocol"
  , 0
  , 3
  , LEBProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEBProtocol::Conjugate::rt_signals[] =
{
	{
		"elevatorButtonPressed"
	  , &RTType_int
	  , LEBProtocol::Conjugate::rti_elevatorButtonPressed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEBProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEBProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
