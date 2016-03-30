// {{{RME classifier 'Logical View::EPProtocol'

#ifndef EPProtocol_H
#define EPProtocol_H

#ifdef PRAGMA
#pragma interface "EPProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ButtonInfo.h>

struct EPProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_init = rtiLast_RTRootProtocol + 1
		  , rti_elevatorButtonPressed
		  , rti_moveElevator
		  , rti_update
		  , rti_clearButton
		};

	protected:
		enum { rtiLast_EPProtocol = rti_clearButton };

	public:
		inline RTSymmetricSignal init( void );
		inline RTInSignal elevatorButtonPressed( void );
		inline RTInSignal moveElevator( void );
		inline RTSymmetricSignal update( void );
		inline RTInSignal clearButton( void );
		inline RTOutSignal init( const RTTypedValue & value );
		inline RTOutSignal elevatorButtonPressed( const RTTypedValue_ButtonInfo & data );
		inline RTOutSignal moveElevator( const int & data );
		inline RTOutSignal clearButton( const RTTypedValue_ButtonInfo & data );
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
			rti_init = rtiLast_RTRootProtocol + 1
		  , rti_elevatorButtonPressed
		  , rti_moveElevator
		  , rti_update
		  , rti_clearButton
		};

	protected:
		enum { rtiLast_EPProtocol = rti_clearButton };

	public:
		inline RTSymmetricSignal init( void );
		inline RTInSignal elevatorButtonPressed( void );
		inline RTInSignal moveElevator( void );
		inline RTSymmetricSignal update( void );
		inline RTInSignal clearButton( void );
		inline RTOutSignal init( const RTTypedValue & value );
		inline RTOutSignal elevatorButtonPressed( const RTTypedValue_ButtonInfo & data );
		inline RTOutSignal moveElevator( const int & data );
		inline RTOutSignal clearButton( const RTTypedValue_ButtonInfo & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline EPProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline EPProtocol::Base::~Base( void )
{
}

inline RTSymmetricSignal EPProtocol::Base::init( void )
{
	return RTSymmetricSignal( this, rti_init, Conjugate::rti_init );
}

inline RTInSignal EPProtocol::Base::elevatorButtonPressed( void )
{
	return RTInSignal( this, rti_elevatorButtonPressed );
}

inline RTInSignal EPProtocol::Base::moveElevator( void )
{
	return RTInSignal( this, rti_moveElevator );
}

inline RTSymmetricSignal EPProtocol::Base::update( void )
{
	return RTSymmetricSignal( this, rti_update, Conjugate::rti_update );
}

inline RTInSignal EPProtocol::Base::clearButton( void )
{
	return RTInSignal( this, rti_clearButton );
}

inline RTOutSignal EPProtocol::Base::init( const RTTypedValue & value )
{
	return RTOutSignal( this, Conjugate::rti_init, value.data, value.type );
}

inline RTOutSignal EPProtocol::Base::elevatorButtonPressed( const RTTypedValue_ButtonInfo & data )
{
	return RTOutSignal( this, Conjugate::rti_elevatorButtonPressed, data.data, data.type );
}

inline RTOutSignal EPProtocol::Base::moveElevator( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_moveElevator, &data, &RTType_int );
}

inline RTOutSignal EPProtocol::Base::clearButton( const RTTypedValue_ButtonInfo & data )
{
	return RTOutSignal( this, Conjugate::rti_clearButton, data.data, data.type );
}

inline EPProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline EPProtocol::Conjugate::~Conjugate( void )
{
}

inline RTSymmetricSignal EPProtocol::Conjugate::init( void )
{
	return RTSymmetricSignal( this, rti_init, Base::rti_init );
}

inline RTInSignal EPProtocol::Conjugate::elevatorButtonPressed( void )
{
	return RTInSignal( this, rti_elevatorButtonPressed );
}

inline RTInSignal EPProtocol::Conjugate::moveElevator( void )
{
	return RTInSignal( this, rti_moveElevator );
}

inline RTSymmetricSignal EPProtocol::Conjugate::update( void )
{
	return RTSymmetricSignal( this, rti_update, Base::rti_update );
}

inline RTInSignal EPProtocol::Conjugate::clearButton( void )
{
	return RTInSignal( this, rti_clearButton );
}

inline RTOutSignal EPProtocol::Conjugate::init( const RTTypedValue & value )
{
	return RTOutSignal( this, Base::rti_init, value.data, value.type );
}

inline RTOutSignal EPProtocol::Conjugate::elevatorButtonPressed( const RTTypedValue_ButtonInfo & data )
{
	return RTOutSignal( this, Base::rti_elevatorButtonPressed, data.data, data.type );
}

inline RTOutSignal EPProtocol::Conjugate::moveElevator( const int & data )
{
	return RTOutSignal( this, Base::rti_moveElevator, &data, &RTType_int );
}

inline RTOutSignal EPProtocol::Conjugate::clearButton( const RTTypedValue_ButtonInfo & data )
{
	return RTOutSignal( this, Base::rti_clearButton, data.data, data.type );
}

#endif /* EPProtocol_H */

// }}}RME
