// {{{RME classifier 'Logical View::LEBProtocol'

#ifndef LEBProtocol_H
#define LEBProtocol_H

#ifdef PRAGMA
#pragma interface "LEBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct LEBProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_clearButton = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_LEBProtocol = rti_clearButton };

	public:
		inline RTInSignal clearButton( void );
		inline RTOutSignal elevatorButtonPressed( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_elevatorButtonPressed = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_LEBProtocol = rti_elevatorButtonPressed };

	public:
		inline RTInSignal elevatorButtonPressed( void );
		inline RTOutSignal clearButton( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline LEBProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline LEBProtocol::Base::~Base( void )
{
}

inline RTInSignal LEBProtocol::Base::clearButton( void )
{
	return RTInSignal( this, rti_clearButton );
}

inline RTOutSignal LEBProtocol::Base::elevatorButtonPressed( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_elevatorButtonPressed, &data, &RTType_int );
}

inline LEBProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline LEBProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal LEBProtocol::Conjugate::elevatorButtonPressed( void )
{
	return RTInSignal( this, rti_elevatorButtonPressed );
}

inline RTOutSignal LEBProtocol::Conjugate::clearButton( void )
{
	return RTOutSignal( this, Base::rti_clearButton, (const void *)0, &RTType_void );
}

#endif /* LEBProtocol_H */

// }}}RME
