// {{{RME classifier 'Logical View::LEDBProtocol'

#ifndef LEDBProtocol_H
#define LEDBProtocol_H

#ifdef PRAGMA
#pragma interface "LEDBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct LEDBProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );

	protected:
		enum { rtiLast_LEDBProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal doorButtonPressed( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_doorButtonPressed = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_LEDBProtocol = rti_doorButtonPressed };

	public:
		inline RTInSignal doorButtonPressed( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline LEDBProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline LEDBProtocol::Base::~Base( void )
{
}

inline RTOutSignal LEDBProtocol::Base::doorButtonPressed( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_doorButtonPressed, &data, &RTType_int );
}

inline LEDBProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline LEDBProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal LEDBProtocol::Conjugate::doorButtonPressed( void )
{
	return RTInSignal( this, rti_doorButtonPressed );
}

#endif /* LEDBProtocol_H */

// }}}RME
