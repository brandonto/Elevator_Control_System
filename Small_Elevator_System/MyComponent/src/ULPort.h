// {{{RME classifier 'Logical View::ULPort'

#ifndef ULPort_H
#define ULPort_H

#ifdef PRAGMA
#pragma interface "ULPort.h"
#endif

#include <RTSystem/MyComponent.h>

struct ULPort
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_forceDoorOpen = rtiLast_RTRootProtocol + 1
		  , rti_forceMotorUp
		  , rti_forceMotorDown
		};

	protected:
		enum { rtiLast_ULPort = rti_forceMotorDown };

	public:
		inline RTInSignal forceDoorOpen( void );
		inline RTInSignal forceMotorUp( void );
		inline RTInSignal forceMotorDown( void );
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
		enum { rtiLast_ULPort = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal forceDoorOpen( void );
		inline RTOutSignal forceMotorUp( void );
		inline RTOutSignal forceMotorDown( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline ULPort::Base::Base( void )
	: RTRootProtocol()
{
}

inline ULPort::Base::~Base( void )
{
}

inline RTInSignal ULPort::Base::forceDoorOpen( void )
{
	return RTInSignal( this, rti_forceDoorOpen );
}

inline RTInSignal ULPort::Base::forceMotorUp( void )
{
	return RTInSignal( this, rti_forceMotorUp );
}

inline RTInSignal ULPort::Base::forceMotorDown( void )
{
	return RTInSignal( this, rti_forceMotorDown );
}

inline ULPort::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline ULPort::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal ULPort::Conjugate::forceDoorOpen( void )
{
	return RTOutSignal( this, Base::rti_forceDoorOpen, (const void *)0, &RTType_void );
}

inline RTOutSignal ULPort::Conjugate::forceMotorUp( void )
{
	return RTOutSignal( this, Base::rti_forceMotorUp, (const void *)0, &RTType_void );
}

inline RTOutSignal ULPort::Conjugate::forceMotorDown( void )
{
	return RTOutSignal( this, Base::rti_forceMotorDown, (const void *)0, &RTType_void );
}

#endif /* ULPort_H */

// }}}RME
