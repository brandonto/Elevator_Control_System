// {{{RME classifier 'Logical View::FCProtocol'

#ifndef FCProtocol_H
#define FCProtocol_H

#ifdef PRAGMA
#pragma interface "FCProtocol.h"
#endif

#include <RTSystem/MyComponent.h>
#include <ButtonInfo.h>

struct FCProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_clearButton = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_FCProtocol = rti_clearButton };

	public:
		inline RTInSignal clearButton( void );
		inline RTOutSignal floorButtonPressed( const RTTypedValue_ButtonInfo & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_floorButtonPressed = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_FCProtocol = rti_floorButtonPressed };

	public:
		inline RTInSignal floorButtonPressed( void );
		inline RTOutSignal clearButton( const RTTypedValue_ButtonInfo & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline FCProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline FCProtocol::Base::~Base( void )
{
}

inline RTInSignal FCProtocol::Base::clearButton( void )
{
	return RTInSignal( this, rti_clearButton );
}

inline RTOutSignal FCProtocol::Base::floorButtonPressed( const RTTypedValue_ButtonInfo & data )
{
	return RTOutSignal( this, Conjugate::rti_floorButtonPressed, data.data, data.type );
}

inline FCProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline FCProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal FCProtocol::Conjugate::floorButtonPressed( void )
{
	return RTInSignal( this, rti_floorButtonPressed );
}

inline RTOutSignal FCProtocol::Conjugate::clearButton( const RTTypedValue_ButtonInfo & data )
{
	return RTOutSignal( this, Base::rti_clearButton, data.data, data.type );
}

#endif /* FCProtocol_H */

// }}}RME
