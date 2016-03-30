// {{{RME classifier 'Logical View::EDDSProtocol'

#ifndef EDDSProtocol_H
#define EDDSProtocol_H

#ifdef PRAGMA
#pragma interface "EDDSProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct EDDSProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_init = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_EDDSProtocol = rti_init };

	public:
		inline RTInSignal init( void );
		inline RTOutSignal impede( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_impede = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_EDDSProtocol = rti_impede };

	public:
		inline RTInSignal impede( void );
		inline RTOutSignal init( const RTTypedValue & value );
		inline RTOutSignal init( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline EDDSProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline EDDSProtocol::Base::~Base( void )
{
}

inline RTInSignal EDDSProtocol::Base::init( void )
{
	return RTInSignal( this, rti_init );
}

inline RTOutSignal EDDSProtocol::Base::impede( void )
{
	return RTOutSignal( this, Conjugate::rti_impede, (const void *)0, &RTType_void );
}

inline EDDSProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline EDDSProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal EDDSProtocol::Conjugate::impede( void )
{
	return RTInSignal( this, rti_impede );
}

inline RTOutSignal EDDSProtocol::Conjugate::init( const RTTypedValue & value )
{
	return RTOutSignal( this, Base::rti_init, value.data, value.type );
}

inline RTOutSignal EDDSProtocol::Conjugate::init( void )
{
	return RTOutSignal( this, Base::rti_init, (void *)0, &RTType_void );
}

#endif /* EDDSProtocol_H */

// }}}RME
