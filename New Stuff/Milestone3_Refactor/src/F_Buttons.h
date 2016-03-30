// {{{RME classifier 'Logical View::F_Buttons'

#ifndef F_Buttons_H
#define F_Buttons_H

#ifdef PRAGMA
#pragma interface "F_Buttons.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct F_Buttons
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_F_Button_Pressed = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_F_Buttons = rti_F_Button_Pressed };

	public:
		inline RTInSignal F_Button_Pressed( void );
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
		enum { rtiLast_F_Buttons = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal F_Button_Pressed( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline F_Buttons::Base::Base( void )
	: RTRootProtocol()
{
}

inline F_Buttons::Base::~Base( void )
{
}

inline RTInSignal F_Buttons::Base::F_Button_Pressed( void )
{
	return RTInSignal( this, rti_F_Button_Pressed );
}

inline F_Buttons::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline F_Buttons::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal F_Buttons::Conjugate::F_Button_Pressed( const int & data )
{
	return RTOutSignal( this, Base::rti_F_Button_Pressed, &data, &RTType_int );
}

#endif /* F_Buttons_H */

// }}}RME
