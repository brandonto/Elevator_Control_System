// {{{RME classifier 'Logical View::LEBRProtocol'

#ifndef LEBRProtocol_H
#define LEBRProtocol_H

#ifdef PRAGMA
#pragma interface "LEBRProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct LEBRProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_init = rtiLast_RTRootProtocol + 1
		  , rti_activateEmergencyBrakes
		};

	protected:
		enum { rtiLast_LEBRProtocol = rti_activateEmergencyBrakes };

	public:
		inline RTInSignal init( void );
		inline RTInSignal activateEmergencyBrakes( void );
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
		enum { rtiLast_LEBRProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal init( const RTTypedValue & value );
		inline RTOutSignal init( void );
		inline RTOutSignal activateEmergencyBrakes( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline LEBRProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline LEBRProtocol::Base::~Base( void )
{
}

inline RTInSignal LEBRProtocol::Base::init( void )
{
	return RTInSignal( this, rti_init );
}

inline RTInSignal LEBRProtocol::Base::activateEmergencyBrakes( void )
{
	return RTInSignal( this, rti_activateEmergencyBrakes );
}

inline LEBRProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline LEBRProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal LEBRProtocol::Conjugate::init( const RTTypedValue & value )
{
	return RTOutSignal( this, Base::rti_init, value.data, value.type );
}

inline RTOutSignal LEBRProtocol::Conjugate::init( void )
{
	return RTOutSignal( this, Base::rti_init, (void *)0, &RTType_void );
}

inline RTOutSignal LEBRProtocol::Conjugate::activateEmergencyBrakes( void )
{
	return RTOutSignal( this, Base::rti_activateEmergencyBrakes, (const void *)0, &RTType_void );
}

#endif /* LEBRProtocol_H */

// }}}RME
