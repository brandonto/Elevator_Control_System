// {{{RME classifier 'Logical View::EBLEBProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "EBLEBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EBLEBProtocol.h>

const RTProtocolDescriptor EBLEBProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &EBLEBProtocol::Conjugate::rt_class
  , "EBLEBProtocol"
  , 0
  , 4
  , EBLEBProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor EBLEBProtocol::Base::rt_signals[] =
{
	{
		"light"
	  , &RTType_void
	  , EBLEBProtocol::Base::rti_light
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , EBLEBProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , EBLEBProtocol::Base::rti_rtUnbound
	}
  , {
		"unlight"
	  , &RTType_void
	  , EBLEBProtocol::Base::rti_unlight
	}
};

const RTProtocolDescriptor EBLEBProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &EBLEBProtocol::Base::rt_class
  , "EBLEBProtocol"
  , 0
  , 2
  , EBLEBProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor EBLEBProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , EBLEBProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , EBLEBProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
