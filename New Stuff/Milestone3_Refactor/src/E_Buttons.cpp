// {{{RME classifier 'Logical View::E_Buttons'

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation "E_Buttons.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <E_Buttons.h>

const RTProtocolDescriptor E_Buttons::Base::rt_class =
{
	&RTRootProtocol::rt_class
  , &E_Buttons::Conjugate::rt_class
  , "E_Buttons"
  , 0
  , 4
  , E_Buttons::Base::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor E_Buttons::Base::rt_signals[] =
{
	{
		"Button_Pressed"
	  , &RTType_int
	  , E_Buttons::Base::rti_Button_Pressed
	}
  , {
		"Door_Open_Pressed"
	  , &RTType_void
	  , E_Buttons::Base::rti_Door_Open_Pressed
	}
  , {
		"rtBound"
	  , (const RTObject_class *)0
	  , E_Buttons::Base::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , E_Buttons::Base::rti_rtUnbound
	}
};

const RTProtocolDescriptor E_Buttons::Conjugate::rt_class =
{
	&RTRootProtocol::rt_class
  , &E_Buttons::Base::rt_class
  , "E_Buttons"
  , 0
  , 2
  , E_Buttons::Conjugate::rt_signals
#if RTRUNTIMEBC
  , &RTProtocolDescriptor::getUnknownGlobalSignal, &RTProtocolDescriptor::getUnknownLocalSignal
#endif
};

const RTSignalDescriptor E_Buttons::Conjugate::rt_signals[] =
{
	{
		"rtBound"
	  , (const RTObject_class *)0
	  , E_Buttons::Conjugate::rti_rtBound
	}
  , {
		"rtUnbound"
	  , (const RTObject_class *)0
	  , E_Buttons::Conjugate::rti_rtUnbound
	}
};

// }}}RME
