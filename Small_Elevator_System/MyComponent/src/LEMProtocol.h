// {{{RME classifier 'Logical View::LEMProtocol'

#ifndef LEMProtocol_H
#define LEMProtocol_H

#ifdef PRAGMA
#pragma interface "LEMProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct LEMProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_init = rtiLast_RTRootProtocol + 1
		  , rti_moveElevatorUp
		  , rti_moveElevatorDown
		  , rti_stopElevator
		};

	protected:
		enum { rtiLast_LEMProtocol = rti_stopElevator };

	public:
		inline RTInSignal init( void );
		inline RTInSignal moveElevatorUp( void );
		inline RTInSignal moveElevatorDown( void );
		inline RTInSignal stopElevator( void );
		inline RTOutSignal arrivedAtFloor( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_arrivedAtFloor = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_LEMProtocol = rti_arrivedAtFloor };

	public:
		inline RTInSignal arrivedAtFloor( void );
		inline RTOutSignal init( const RTTypedValue & value );
		inline RTOutSignal init( void );
		inline RTOutSignal moveElevatorUp( void );
		inline RTOutSignal moveElevatorDown( void );
		inline RTOutSignal stopElevator( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline LEMProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline LEMProtocol::Base::~Base( void )
{
}

inline RTInSignal LEMProtocol::Base::init( void )
{
	return RTInSignal( this, rti_init );
}

inline RTInSignal LEMProtocol::Base::moveElevatorUp( void )
{
	return RTInSignal( this, rti_moveElevatorUp );
}

inline RTInSignal LEMProtocol::Base::moveElevatorDown( void )
{
	return RTInSignal( this, rti_moveElevatorDown );
}

inline RTInSignal LEMProtocol::Base::stopElevator( void )
{
	return RTInSignal( this, rti_stopElevator );
}

inline RTOutSignal LEMProtocol::Base::arrivedAtFloor( void )
{
	return RTOutSignal( this, Conjugate::rti_arrivedAtFloor, (const void *)0, &RTType_void );
}

inline LEMProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline LEMProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal LEMProtocol::Conjugate::arrivedAtFloor( void )
{
	return RTInSignal( this, rti_arrivedAtFloor );
}

inline RTOutSignal LEMProtocol::Conjugate::init( const RTTypedValue & value )
{
	return RTOutSignal( this, Base::rti_init, value.data, value.type );
}

inline RTOutSignal LEMProtocol::Conjugate::init( void )
{
	return RTOutSignal( this, Base::rti_init, (void *)0, &RTType_void );
}

inline RTOutSignal LEMProtocol::Conjugate::moveElevatorUp( void )
{
	return RTOutSignal( this, Base::rti_moveElevatorUp, (const void *)0, &RTType_void );
}

inline RTOutSignal LEMProtocol::Conjugate::moveElevatorDown( void )
{
	return RTOutSignal( this, Base::rti_moveElevatorDown, (const void *)0, &RTType_void );
}

inline RTOutSignal LEMProtocol::Conjugate::stopElevator( void )
{
	return RTOutSignal( this, Base::rti_stopElevator, (const void *)0, &RTType_void );
}

#endif /* LEMProtocol_H */

// }}}RME
