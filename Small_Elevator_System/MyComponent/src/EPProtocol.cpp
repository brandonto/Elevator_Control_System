// {{{RME classifier 'Logical View::EPProtocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "EPProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EPProtocol.h>

const RTProtocolDescriptor EPProtocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &EPProtocol::Conjugate::rt_class
  , "EPProtocol"
  , 0
  , 7
  , EPProtocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor EPProtocol::Base::rt_signals[] =
{
	{
		"arrivedAtFloor"
	  , &RTType_ButtonInfo
	  , EPProtocol::Base::rti_arrivedAtFloor
	}
  , {
		"elevatorButtonPressed"
	  , &RTType_ButtonInfo
	  , EPProtocol::Base::rti_elevatorButtonPressed
	}
  , {
		"init"
	  , (const RTObject_class *)0
	  , EPProtocol::Base::rti_init
	}
  , {
		"moveElevator"
	  , &RTType_int
	  , EPProtocol::Base::rti_moveElevator
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , EPProtocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , EPProtocol::Base::rti_rtUnbound
	}
  , {
		"update"
	  , &RTType_void
	  , EPProtocol::Base::rti_update
	}
};

const RTProtocolDescriptor EPProtocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &EPProtocol::Base::rt_class
  , "EPProtocol"
  , 0
  , 7
  , EPProtocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor EPProtocol::Conjugate::rt_signals[] =
{
	{
		"arrivedAtFloor"
	  , &RTType_ButtonInfo
	  , EPProtocol::Conjugate::rti_arrivedAtFloor
	}
  , {
		"elevatorButtonPressed"
	  , &RTType_ButtonInfo
	  , EPProtocol::Conjugate::rti_elevatorButtonPressed
	}
  , {
		"init"
	  , (const RTObject_class *)0
	  , EPProtocol::Conjugate::rti_init
	}
  , {
		"moveElevator"
	  , &RTType_int
	  , EPProtocol::Conjugate::rti_moveElevator
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , EPProtocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , EPProtocol::Conjugate::rti_rtUnbound
	}
  , {
		"update"
	  , &RTType_void
	  , EPProtocol::Conjugate::rti_update
	}
};

// }}}RME
