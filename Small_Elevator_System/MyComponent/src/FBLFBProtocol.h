// {{{RME classifier 'Logical View::FBLFBProtocol'

#ifndef FBLFBProtocol_H
#define FBLFBProtocol_H

#ifdef PRAGMA
#pragma interface "FBLFBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct FBLFBProtocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_light = rtiLast_RTRootProtocol + 1
		  , rti_unlight
		};

	protected:
		enum { rtiLast_FBLFBProtocol = rti_unlight };

	public:
		inline RTInSignal light( void );
		inline RTInSignal unlight( void );
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
		enum { rtiLast_FBLFBProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal light( void );
		inline RTOutSignal unlight( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline FBLFBProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline FBLFBProtocol::Base::~Base( void )
{
}

inline RTInSignal FBLFBProtocol::Base::light( void )
{
	return RTInSignal( this, rti_light );
}

inline RTInSignal FBLFBProtocol::Base::unlight( void )
{
	return RTInSignal( this, rti_unlight );
}

inline FBLFBProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline FBLFBProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal FBLFBProtocol::Conjugate::light( void )
{
	return RTOutSignal( this, Base::rti_light, (const void *)0, &RTType_void );
}

inline RTOutSignal FBLFBProtocol::Conjugate::unlight( void )
{
	return RTOutSignal( this, Base::rti_unlight, (const void *)0, &RTType_void );
}

#endif /* FBLFBProtocol_H */

// }}}RME
