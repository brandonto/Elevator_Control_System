// {{{RME classifier 'Logical View::Service_Modes'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Service_Modes.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Service_Modes.h>

const RTProtocolDescriptor Service_Modes::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Service_Modes::Conjugate::rt_class
  , "Service_Modes"
  , 0
  , 3
  , Service_Modes::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Service_Modes::Base::rt_signals[] =
{
	{
		"Swap_Modes"
	  , &RTType_void
	  , Service_Modes::Base::rti_Swap_Modes
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Service_Modes::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Service_Modes::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor Service_Modes::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Service_Modes::Base::rt_class
  , "Service_Modes"
  , 0
  , 2
  , Service_Modes::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Service_Modes::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , Service_Modes::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Service_Modes::Conjugate::rti_rtUnbound
	}
};

// }}}RME
