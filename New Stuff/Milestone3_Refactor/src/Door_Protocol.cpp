// {{{RME classifier 'Logical View::Door_Protocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Door_Protocol.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Door_Protocol.h>

const RTProtocolDescriptor Door_Protocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Door_Protocol::Conjugate::rt_class
  , "Door_Protocol"
  , 0
  , 3
  , Door_Protocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Door_Protocol::Base::rt_signals[] =
{
	{
		"Command_Door_Open"
	  , &RTType_bool
	  , Door_Protocol::Base::rti_Command_Door_Open
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Door_Protocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Door_Protocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor Door_Protocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Door_Protocol::Base::rt_class
  , "Door_Protocol"
  , 0
  , 4
  , Door_Protocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Door_Protocol::Conjugate::rt_signals[] =
{
	{
		"Doors_Closed"
	  , &RTType_bool
	  , Door_Protocol::Conjugate::rti_Doors_Closed
	}
  , {
		"Doors_Open"
	  , &RTType_bool
	  , Door_Protocol::Conjugate::rti_Doors_Open
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Door_Protocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Door_Protocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
