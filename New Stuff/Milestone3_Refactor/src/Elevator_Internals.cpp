// {{{RME classifier 'Logical View::Elevator_Internals'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Elevator_Internals.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Elevator_Internals.h>

const RTProtocolDescriptor Elevator_Internals::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Elevator_Internals::Conjugate::rt_class
  , "Elevator_Internals"
  , 0
  , 5
  , Elevator_Internals::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Elevator_Internals::Base::rt_signals[] =
{
	{
		"Arrived_Target"
	  , &RTType_void
	  , Elevator_Internals::Base::rti_Arrived_Target
	}
  , {
		"E_Brake_Engaged"
	  , &RTType_void
	  , Elevator_Internals::Base::rti_E_Brake_Engaged
	}
  , {
		"New_Current_Floor"
	  , &RTType_int
	  , Elevator_Internals::Base::rti_New_Current_Floor
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Elevator_Internals::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Elevator_Internals::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor Elevator_Internals::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Elevator_Internals::Base::rt_class
  , "Elevator_Internals"
  , 0
  , 4
  , Elevator_Internals::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Elevator_Internals::Conjugate::rt_signals[] =
{
	{
		"New_Target"
	  , &RTType_int
	  , Elevator_Internals::Conjugate::rti_New_Target
	}
  , {
		"Open_Doors"
	  , &RTType_void
	  , Elevator_Internals::Conjugate::rti_Open_Doors
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Elevator_Internals::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Elevator_Internals::Conjugate::rti_rtUnbound
	}
};

// }}}RME
