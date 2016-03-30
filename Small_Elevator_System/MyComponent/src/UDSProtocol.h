// {{{RME classifier 'Logical View::UDSProtocol'

#ifndef UDSProtocol_H
#define UDSProtocol_H

#ifdef PRAGMA
#pragma interface "UDSProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct UDSProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_impede = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_UDSProtocol = rti_impede };

	public:
		inline RTInSignal impede( void );
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
		enum { rtiLast_UDSProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal impede( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline UDSProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline UDSProtocol::Base::~Base( void )
{
}

inline RTInSignal UDSProtocol::Base::impede( void )
{
	return RTInSignal( this, rti_impede );
}

inline UDSProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline UDSProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal UDSProtocol::Conjugate::impede( void )
{
	return RTOutSignal( this, Base::rti_impede, (const void *)0, &RTType_void );
}

#endif /* UDSProtocol_H */

// }}}RME
