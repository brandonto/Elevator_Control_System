// {{{RME classifier 'Logical View::F_Buttons'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "F_Buttons.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <F_Buttons.h>

const RTProtocolDescriptor F_Buttons::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &F_Buttons::Conjugate::rt_class
  , "F_Buttons"
  , 0
  , 3
  , F_Buttons::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor F_Buttons::Base::rt_signals[] =
{
	{
		"F_Button_Pressed"
	  , &RTType_int
	  , F_Buttons::Base::rti_F_Button_Pressed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , F_Buttons::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , F_Buttons::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor F_Buttons::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &F_Buttons::Base::rt_class
  , "F_Buttons"
  , 0
  , 2
  , F_Buttons::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor F_Buttons::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , F_Buttons::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , F_Buttons::Conjugate::rti_rtUnbound
	}
};

// }}}RME
