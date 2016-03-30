// {{{RME classifier 'Logical View::FBFProtocol'

#ifndef FBFProtocol_H
#define FBFProtocol_H

#ifdef PRAGMA
#pragma interface "FBFProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct FBFProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_init = rtiLast_RTRootProtocol + 1
		  , rti_clearButton
		};

	protected:
		enum { rtiLast_FBFProtocol = rti_clearButton };

	public:
		inline RTInSignal init( void );
		inline RTInSignal clearButton( void );
		inline RTOutSignal floorButtonPressed( const bool & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum { rti_floorButtonPressed = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_FBFProtocol = rti_floorButtonPressed };

	public:
		inline RTInSignal floorButtonPressed( void );
		inline RTOutSignal init( const int & data );
		inline RTOutSignal clearButton( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline FBFProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline FBFProtocol::Base::~Base( void )
{
}

inline RTInSignal FBFProtocol::Base::init( void )
{
	return RTInSignal( this, rti_init );
}

inline RTInSignal FBFProtocol::Base::clearButton( void )
{
	return RTInSignal( this, rti_clearButton );
}

inline RTOutSignal FBFProtocol::Base::floorButtonPressed( const bool & data )
{
	return RTOutSignal( this, Conjugate::rti_floorButtonPressed, &data, &RTType_bool );
}

inline FBFProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline FBFProtocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal FBFProtocol::Conjugate::floorButtonPressed( void )
{
	return RTInSignal( this, rti_floorButtonPressed );
}

inline RTOutSignal FBFProtocol::Conjugate::init( const int & data )
{
	return RTOutSignal( this, Base::rti_init, &data, &RTType_int );
}

inline RTOutSignal FBFProtocol::Conjugate::clearButton( void )
{
	return RTOutSignal( this, Base::rti_clearButton, (const void *)0, &RTType_void );
}

#endif /* FBFProtocol_H */

// }}}RME
