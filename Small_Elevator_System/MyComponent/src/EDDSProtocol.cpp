// {{{RME classifier 'Logical View::EDDSProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "EDDSProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EDDSProtocol.h>

const RTProtocolDescriptor EDDSProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &EDDSProtocol::Conjugate::rt_class
  , "EDDSProtocol"
  , 0
  , 3
  , EDDSProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor EDDSProtocol::Base::rt_signals[] =
{
	{
		"init"
	  , (const RTObject_class *)0
	  , EDDSProtocol::Base::rti_init
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , EDDSProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , EDDSProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor EDDSProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &EDDSProtocol::Base::rt_class
  , "EDDSProtocol"
  , 0
  , 3
  , EDDSProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor EDDSProtocol::Conjugate::rt_signals[] =
{
	{
		"impede"
	  , &RTType_void
	  , EDDSProtocol::Conjugate::rti_impede
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , EDDSProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , EDDSProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
