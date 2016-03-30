// {{{RME classifier 'Logical View::UEDBProtocol'

#ifndef UEDBProtocol_H
#define UEDBProtocol_H

#ifdef PRAGMA
#pragma interface "UEDBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct UEDBProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_pressElevatorButton = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_UEDBProtocol = rti_pressElevatorButton };

	public:
		inline RTInSignal pressElevatorButton( void );
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
		enum { rtiLast_UEDBProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal pressElevatorButton( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline UEDBProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline UEDBProtocol::Base::~Base( void )
{
}

inline RTInSignal UEDBProtocol::Base::pressElevatorButton( void )
{
	return RTInSignal( this, rti_pressElevatorButton );
}

inline UEDBProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline UEDBProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal UEDBProtocol::Conjugate::pressElevatorButton( void )
{
	return RTOutSignal( this, Base::rti_pressElevatorButton, (const void *)0, &RTType_void );
}

#endif /* UEDBProtocol_H */

// }}}RME
