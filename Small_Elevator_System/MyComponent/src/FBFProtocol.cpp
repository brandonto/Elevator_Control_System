// {{{RME classifier 'Logical View::FBFProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "FBFProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FBFProtocol.h>

const RTProtocolDescriptor FBFProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &FBFProtocol::Conjugate::rt_class
  , "FBFProtocol"
  , 0
  , 4
  , FBFProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor FBFProtocol::Base::rt_signals[] =
{
	{
		"clearButton"
	  , &RTType_void
	  , FBFProtocol::Base::rti_clearButton
	}
  , {
		"init"
	  , &RTType_int
	  , FBFProtocol::Base::rti_init
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , FBFProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , FBFProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor FBFProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &FBFProtocol::Base::rt_class
  , "FBFProtocol"
  , 0
  , 3
  , FBFProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor FBFProtocol::Conjugate::rt_signals[] =
{
	{
		"floorButtonPressed"
	  , &RTType_bool
	  , FBFProtocol::Conjugate::rti_floorButtonPressed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , FBFProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , FBFProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
