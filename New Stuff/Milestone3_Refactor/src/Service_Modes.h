// {{{RME classifier 'Logical View::Service_Modes'

#ifndef Service_Modes_H
#define Service_Modes_H

#ifdef PRAGMA
#pragma interface "Service_Modes.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct Service_Modes
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_Swap_Modes = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_Service_Modes = rti_Swap_Modes };

	public:
		inline RTInSignal Swap_Modes( void );
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
		enum { rtiLast_Service_Modes = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal Swap_Modes( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Service_Modes::Base::Base( void )
	: RTRootProtocol()
{
}

inline Service_Modes::Base::~Base( void )
{
}

inline RTInSignal Service_Modes::Base::Swap_Modes( void )
{
	return RTInSignal( this, rti_Swap_Modes );
}

inline Service_Modes::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Service_Modes::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal Service_Modes::Conjugate::Swap_Modes( void )
{
	return RTOutSignal( this, Base::rti_Swap_Modes, (const void *)0, &RTType_void );
}

#endif /* Service_Modes_H */

// }}}RME
