// {{{RME classifier 'Logical View::Elevator_Request_Protocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Elevator_Request_Protocol.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Elevator_Request_Protocol.h>

const RTProtocolDescriptor Elevator_Request_Protocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Elevator_Request_Protocol::Conjugate::rt_class
  , "Elevator_Request_Protocol"
  , 0
  , 3
  , Elevator_Request_Protocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Elevator_Request_Protocol::Base::rt_signals[] =
{
	{
		"Update_Information"
	  , &RTType_int
	  , Elevator_Request_Protocol::Base::rti_Update_Information
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Elevator_Request_Protocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Elevator_Request_Protocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor Elevator_Request_Protocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Elevator_Request_Protocol::Base::rt_class
  , "Elevator_Request_Protocol"
  , 0
  , 4
  , Elevator_Request_Protocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Elevator_Request_Protocol::Conjugate::rt_signals[] =
{
	{
		"Add_Floor_Request"
	  , &RTType_int
	  , Elevator_Request_Protocol::Conjugate::rti_Add_Floor_Request
	}
  , {
		"Open_Doors"
	  , &RTType_void
	  , Elevator_Request_Protocol::Conjugate::rti_Open_Doors
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Elevator_Request_Protocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Elevator_Request_Protocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
