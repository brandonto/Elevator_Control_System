// {{{RME classifier 'Logical View::LEBRProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "LEBRProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEBRProtocol.h>

const RTProtocolDescriptor LEBRProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEBRProtocol::Conjugate::rt_class
  , "LEBRProtocol"
  , 0
  , 4
  , LEBRProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEBRProtocol::Base::rt_signals[] =
{
	{
		"activateEmergencyBrakes"
	  , &RTType_void
	  , LEBRProtocol::Base::rti_activateEmergencyBrakes
	}
  , {
		"init"
	  , (const RTObject_class *)0
	  , LEBRProtocol::Base::rti_init
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEBRProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEBRProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor LEBRProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEBRProtocol::Base::rt_class
  , "LEBRProtocol"
  , 0
  , 2
  , LEBRProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEBRProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , LEBRProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEBRProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
