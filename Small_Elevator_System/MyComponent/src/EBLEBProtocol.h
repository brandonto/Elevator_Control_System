// {{{RME classifier 'Logical View::EBLEBProtocol'

#ifndef EBLEBProtocol_H
#define EBLEBProtocol_H

#ifdef PRAGMA
#pragma interface "EBLEBProtocol.h"
#endif

#include <RTSystem/MyComponent.h>

struct EBLEBProtocol
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
		enum { rtiLast_EBLEBProtocol = rti_unlight };

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
		enum { rtiLast_EBLEBProtocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal light( void );
		inline RTOutSignal unlight( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline EBLEBProtocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline EBLEBProtocol::Base::~Base( void )
{
}

inline RTInSignal EBLEBProtocol::Base::light( void )
{
	return RTInSignal( this, rti_light );
}

inline RTInSignal EBLEBProtocol::Base::unlight( void )
{
	return RTInSignal( this, rti_unlight );
}

inline EBLEBProtocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline EBLEBProtocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal EBLEBProtocol::Conjugate::light( void )
{
	return RTOutSignal( this, Base::rti_light, (const void *)0, &RTType_void );
}

inline RTOutSignal EBLEBProtocol::Conjugate::unlight( void )
{
	return RTOutSignal( this, Base::rti_unlight, (const void *)0, &RTType_void );
}

#endif /* EBLEBProtocol_H */

// }}}RME
