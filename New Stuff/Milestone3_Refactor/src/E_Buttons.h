// {{{RME classifier 'Logical View::E_Buttons'

#ifndef E_Buttons_H
#define E_Buttons_H

#ifdef PRAGMA
#pragma interface "E_Buttons.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct E_Buttons
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_Button_Pressed = rtiLast_RTRootProtocol + 1
		  , rti_Door_Open_Pressed
		};

	protected:
		enum { rtiLast_E_Buttons = rti_Door_Open_Pressed };

	public:
		inline RTInSignal Button_Pressed( void );
		inline RTInSignal Door_Open_Pressed( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );

	protected:
		enum { rtiLast_E_Buttons = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal Button_Pressed( const int & data );
		inline RTOutSignal Door_Open_Pressed( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline E_Buttons::Base::Base( void )
	: RTRootProtocol()
{
}

inline E_Buttons::Base::~Base( void )
{
}

inline RTInSignal E_Buttons::Base::Button_Pressed( void )
{
	return RTInSignal( this, rti_Button_Pressed );
}

inline RTInSignal E_Buttons::Base::Door_Open_Pressed( void )
{
	return RTInSignal( this, rti_Door_Open_Pressed );
}

inline E_Buttons::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline E_Buttons::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal E_Buttons::Conjugate::Button_Pressed( const int & data )
{
	return RTOutSignal( this, Base::rti_Button_Pressed, &data, &RTType_int );
}

inline RTOutSignal E_Buttons::Conjugate::Door_Open_Pressed( void )
{
	return RTOutSignal( this, Base::rti_Door_Open_Pressed, (const void *)0, &RTType_void );
}

#endif /* E_Buttons_H */

// }}}RME
