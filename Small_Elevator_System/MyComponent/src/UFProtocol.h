// {{{RME classifier 'Logical View::UFProtocol'

#ifndef UFProtocol_H
#define UFProtocol_H

#ifdef PRAGMA
#pragma interface "UFProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct UFProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_pressFloorButton = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_UFProtocol = rti_pressFloorButton };

	public:
		inline RTInSignal pressFloorButton( void );
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
		enum { rtiLast_UFProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal pressFloorButton( const bool & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline UFProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline UFProtocol::Base::~Base( void )
{
}

inline RTInSignal UFProtocol::Base::pressFloorButton( void )
{
	return RTInSignal( this, rti_pressFloorButton );
}

inline UFProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline UFProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal UFProtocol::Conjugate::pressFloorButton( const bool & data )
{
	return RTOutSignal( this, Base::rti_pressFloorButton, &data, &RTType_bool );
}

#endif /* UFProtocol_H */

// }}}RME
