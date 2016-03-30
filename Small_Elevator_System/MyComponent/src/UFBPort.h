// {{{RME classifier 'Logical View::UFBPort'

#ifndef UFBPort_H
#define UFBPort_H

#ifdef PRAGMA
#pragma interface "UFBPort.h"
#endif

#include <RTSystem/MyComponent.h>

struct UFBPort
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_pressFloorButton = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_UFBPort = rti_pressFloorButton };

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
		enum { rtiLast_UFBPort = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal pressFloorButton( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline UFBPort::Base::Base( void )
	: RTRootProtocol()
{
}

inline UFBPort::Base::~Base( void )
{
}

inline RTInSignal UFBPort::Base::pressFloorButton( void )
{
	return RTInSignal( this, rti_pressFloorButton );
}

inline UFBPort::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline UFBPort::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal UFBPort::Conjugate::pressFloorButton( void )
{
	return RTOutSignal( this, Base::rti_pressFloorButton, (const void *)0, &RTType_void );
}

#endif /* UFBPort_H */

// }}}RME
