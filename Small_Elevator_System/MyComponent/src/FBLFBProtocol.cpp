// {{{RME classifier 'Logical View::FBLFBProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "FBLFBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FBLFBProtocol.h>

const RTProtocolDescriptor FBLFBProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &FBLFBProtocol::Conjugate::rt_class
  , "FBLFBProtocol"
  , 0
  , 4
  , FBLFBProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor FBLFBProtocol::Base::rt_signals[] =
{
	{
		"light"
	  , &RTType_void
	  , FBLFBProtocol::Base::rti_light
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , FBLFBProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , FBLFBProtocol::Base::rti_rtUnbound
	}
  , {
		"unlight"
	  , &RTType_void
	  , FBLFBProtocol::Base::rti_unlight
	}
};

const RTProtocolDescriptor FBLFBProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &FBLFBProtocol::Base::rt_class
  , "FBLFBProtocol"
  , 0
  , 2
  , FBLFBProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor FBLFBProtocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , FBLFBProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , FBLFBProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
