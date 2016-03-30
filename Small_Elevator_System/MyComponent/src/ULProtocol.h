// {{{RME classifier 'Logical View::ULProtocol'

#ifndef ULProtocol_H
#define ULProtocol_H

#ifdef PRAGMA
#pragma interface "ULProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct ULProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_pressElevatorButton = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_ULProtocol = rti_pressElevatorButton };

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
		enum { rtiLast_ULProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal pressElevatorButton( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline ULProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline ULProtocol::Base::~Base( void )
{
}

inline RTInSignal ULProtocol::Base::pressElevatorButton( void )
{
	return RTInSignal( this, rti_pressElevatorButton );
}

inline ULProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline ULProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal ULProtocol::Conjugate::pressElevatorButton( const int & data )
{
	return RTOutSignal( this, Base::rti_pressElevatorButton, &data, &RTType_int );
}

#endif /* ULProtocol_H */

// }}}RME
