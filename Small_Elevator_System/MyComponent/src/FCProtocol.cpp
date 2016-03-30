// {{{RME classifier 'Logical View::FCProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "FCProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FCProtocol.h>

const RTProtocolDescriptor FCProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &FCProtocol::Conjugate::rt_class
  , "FCProtocol"
  , 0
  , 3
  , FCProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor FCProtocol::Base::rt_signals[] =
{
	{
		"arrivedAtFloor"
	  , &RTType_ButtonInfo
	  , FCProtocol::Base::rti_arrivedAtFloor
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , FCProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , FCProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor FCProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &FCProtocol::Base::rt_class
  , "FCProtocol"
  , 0
  , 3
  , FCProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor FCProtocol::Conjugate::rt_signals[] =
{
	{
		"floorButtonPressed"
	  , &RTType_ButtonInfo
	  , FCProtocol::Conjugate::rti_floorButtonPressed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , FCProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , FCProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
