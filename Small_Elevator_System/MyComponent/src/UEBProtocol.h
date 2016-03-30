// {{{RME classifier 'Logical View::UEBProtocol'

#ifndef UEBProtocol_H
#define UEBProtocol_H

#ifdef PRAGMA
#pragma interface "UEBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct UEBProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_pressElevatorButton = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_UEBProtocol = rti_pressElevatorButton };

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
		enum { rtiLast_UEBProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal pressElevatorButton( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline UEBProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline UEBProtocol::Base::~Base( void )
{
}

inline RTInSignal UEBProtocol::Base::pressElevatorButton( void )
{
	return RTInSignal( this, rti_pressElevatorButton );
}

inline UEBProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline UEBProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal UEBProtocol::Conjugate::pressElevatorButton( void )
{
	return RTOutSignal( this, Base::rti_pressElevatorButton, (const void *)0, &RTType_void );
}

#endif /* UEBProtocol_H */

// }}}RME
