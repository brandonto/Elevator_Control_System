// {{{RME classifier 'Logical View::Motor_Protocol'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "Motor_Protocol.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Motor_Protocol.h>

const RTProtocolDescriptor Motor_Protocol::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &Motor_Protocol::Conjugate::rt_class
  , "Motor_Protocol"
  , 0
  , 6
  , Motor_Protocol::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Motor_Protocol::Base::rt_signals[] =
{
	{
		"E_Brake"
	  , &RTType_bool
	  , Motor_Protocol::Base::rti_E_Brake
	}
  , {
		"STOP"
	  , &RTType_bool
	  , Motor_Protocol::Base::rti_STOP
	}
  , {
		"Start_DOWN"
	  , &RTType_bool
	  , Motor_Protocol::Base::rti_Start_DOWN
	}
  , {
		"Start_UP"
	  , &RTType_bool
	  , Motor_Protocol::Base::rti_Start_UP
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , Motor_Protocol::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Motor_Protocol::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor Motor_Protocol::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &Motor_Protocol::Base::rt_class
  , "Motor_Protocol"
  , 0
  , 2
  , Motor_Protocol::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor Motor_Protocol::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , Motor_Protocol::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , Motor_Protocol::Conjugate::rti_rtUnbound
	}
};

// }}}RME
