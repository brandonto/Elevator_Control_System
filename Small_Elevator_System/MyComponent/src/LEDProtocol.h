// {{{RME classifier 'Logical View::LEDProtocol'

#ifndef LEDProtocol_H
#define LEDProtocol_H

#ifdef PRAGMA
#pragma interface "LEDProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct LEDProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_init = rtiLast_RTRootProtocol + 1
		  , rti_openDoor
		};

	protected:
		enum { rtiLast_LEDProtocol = rti_openDoor };

	public:
		inline RTInSignal init( void );
		inline RTInSignal openDoor( void );
		inline RTOutSignal doorClosed( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_doorClosed = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_LEDProtocol = rti_doorClosed };

	public:
		inline RTInSignal doorClosed( void );
		inline RTOutSignal init( const RTTypedValue & value );
		inline RTOutSignal init( void );
		inline RTOutSignal openDoor( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline LEDProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline LEDProtocol::Base::~Base( void )
{
}

inline RTInSignal LEDProtocol::Base::init( void )
{
	return RTInSignal( this, rti_init );
}

inline RTInSignal LEDProtocol::Base::openDoor( void )
{
	return RTInSignal( this, rti_openDoor );
}

inline RTOutSignal LEDProtocol::Base::doorClosed( void )
{
	return RTOutSignal( this, Conjugate::rti_doorClosed, (const void *)0, &RTType_void );
}

inline LEDProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline LEDProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal LEDProtocol::Conjugate::doorClosed( void )
{
	return RTInSignal( this, rti_doorClosed );
}

inline RTOutSignal LEDProtocol::Conjugate::init( const RTTypedValue & value )
{
	return RTOutSignal( this, Base::rti_init, value.data, value.type );
}

inline RTOutSignal LEDProtocol::Conjugate::init( void )
{
	return RTOutSignal( this, Base::rti_init, (void *)0, &RTType_void );
}

inline RTOutSignal LEDProtocol::Conjugate::openDoor( void )
{
	return RTOutSignal( this, Base::rti_openDoor, (const void *)0, &RTType_void );
}

#endif /* LEDProtocol_H */

// }}}RME
