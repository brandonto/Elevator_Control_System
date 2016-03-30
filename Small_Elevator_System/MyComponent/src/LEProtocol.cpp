// {{{RME classifier 'Logical View::LEProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "LEProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEProtocol.h>

const RTProtocolDescriptor LEProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEProtocol::Conjugate::rt_class
  , "LEProtocol"
  , 0
  , 5
  , LEProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEProtocol::Base::rt_signals[] =
{
	{
		"init"
	  , (const RTObject_class *)0
	  , LEProtocol::Base::rti_init
	}
  , {
		"moveElevator"
	  , &RTType_int
	  , LEProtocol::Base::rti_moveElevator
	}
  , {
		"openDoor"
	  , &RTType_void
	  , LEProtocol::Base::rti_openDoor
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEProtocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor LEProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &LEProtocol::Base::rt_class
  , "LEProtocol"
  , 0
  , 5
  , LEProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor LEProtocol::Conjugate::rt_signals[] =
{
	{
		"arrivedAtFloor"
	  , &RTType_void
	  , LEProtocol::Conjugate::rti_arrivedAtFloor
	}
  , {
		"doorClosed"
	  , &RTType_void
	  , LEProtocol::Conjugate::rti_doorClosed
	}
  , {
		"elevatorButtonPressed"
	  , &RTType_ButtonInfo
	  , LEProtocol::Conjugate::rti_elevatorButtonPressed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , LEProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , LEProtocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
