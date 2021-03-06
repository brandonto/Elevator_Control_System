// {{{RME classifier 'Logical View::LEProtocol'

#ifndef LEProtocol_H
#define LEProtocol_H

#ifdef PRAGMA
#pragma interface "LEProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ButtonInfo.h>

struct LEProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_init = rtiLast_RTRootProtocol + 1
		  , rti_moveElevator
		  , rti_openDoor
		  , rti_clearButton
		};

	protected:
		enum { rtiLast_LEProtocol = rti_clearButton };

	public:
		inline RTInSignal init( void );
		inline RTInSignal moveElevator( void );
		inline RTInSignal openDoor( void );
		inline RTInSignal clearButton( void );
		inline RTOutSignal elevatorButtonPressed( const RTTypedValue_ButtonInfo & data );
		inline RTOutSignal arrivedAtFloor( void );
		inline RTOutSignal doorClosed( void );
		inline RTOutSignal activateEmergencyBrakes( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum
		{
			rti_elevatorButtonPressed = rtiLast_RTRootProtocol + 1
		  , rti_arrivedAtFloor
		  , rti_doorClosed
		  , rti_activateEmergencyBrakes
		};

	protected:
		enum { rtiLast_LEProtocol = rti_activateEmergencyBrakes };

	public:
		inline RTInSignal elevatorButtonPressed( void );
		inline RTInSignal arrivedAtFloor( void );
		inline RTInSignal doorClosed( void );
		inline RTInSignal activateEmergencyBrakes( void );
		inline RTOutSignal init( const RTTypedValue & value );
		inline RTOutSignal init( void );
		inline RTOutSignal moveElevator( const int & data );
		inline RTOutSignal openDoor( void );
		inline RTOutSignal clearButton( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline LEProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline LEProtocol::Base::~Base( void )
{
}

inline RTInSignal LEProtocol::Base::init( void )
{
	return RTInSignal( this, rti_init );
}

inline RTInSignal LEProtocol::Base::moveElevator( void )
{
	return RTInSignal( this, rti_moveElevator );
}

inline RTInSignal LEProtocol::Base::openDoor( void )
{
	return RTInSignal( this, rti_openDoor );
}

inline RTInSignal LEProtocol::Base::clearButton( void )
{
	return RTInSignal( this, rti_clearButton );
}

inline RTOutSignal LEProtocol::Base::elevatorButtonPressed( const RTTypedValue_ButtonInfo & data )
{
	return RTOutSignal( this, Conjugate::rti_elevatorButtonPressed, data.data, data.type );
}

inline RTOutSignal LEProtocol::Base::arrivedAtFloor( void )
{
	return RTOutSignal( this, Conjugate::rti_arrivedAtFloor, (const void *)0, &RTType_void );
}

inline RTOutSignal LEProtocol::Base::doorClosed( void )
{
	return RTOutSignal( this, Conjugate::rti_doorClosed, (const void *)0, &RTType_void );
}

inline RTOutSignal LEProtocol::Base::activateEmergencyBrakes( void )
{
	return RTOutSignal( this, Conjugate::rti_activateEmergencyBrakes, (const void *)0, &RTType_void );
}

inline LEProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline LEProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal LEProtocol::Conjugate::elevatorButtonPressed( void )
{
	return RTInSignal( this, rti_elevatorButtonPressed );
}

inline RTInSignal LEProtocol::Conjugate::arrivedAtFloor( void )
{
	return RTInSignal( this, rti_arrivedAtFloor );
}

inline RTInSignal LEProtocol::Conjugate::doorClosed( void )
{
	return RTInSignal( this, rti_doorClosed );
}

inline RTInSignal LEProtocol::Conjugate::activateEmergencyBrakes( void )
{
	return RTInSignal( this, rti_activateEmergencyBrakes );
}

inline RTOutSignal LEProtocol::Conjugate::init( const RTTypedValue & value )
{
	return RTOutSignal( this, Base::rti_init, value.data, value.type );
}

inline RTOutSignal LEProtocol::Conjugate::init( void )
{
	return RTOutSignal( this, Base::rti_init, (void *)0, &RTType_void );
}

inline RTOutSignal LEProtocol::Conjugate::moveElevator( const int & data )
{
	return RTOutSignal( this, Base::rti_moveElevator, &data, &RTType_int );
}

inline RTOutSignal LEProtocol::Conjugate::openDoor( void )
{
	return RTOutSignal( this, Base::rti_openDoor, (const void *)0, &RTType_void );
}

inline RTOutSignal LEProtocol::Conjugate::clearButton( const int & data )
{
	return RTOutSignal( this, Base::rti_clearButton, &data, &RTType_int );
}

#endif /* LEProtocol_H */

// }}}RME
