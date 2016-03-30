// {{{RME classifier 'Logical View::Motor_Protocol'

#ifndef Motor_Protocol_H
#define Motor_Protocol_H

#ifdef PRAGMA
#pragma interface "Motor_Protocol.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct Motor_Protocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_Start_UP = rtiLast_RTRootProtocol + 1
		  , rti_Start_DOWN
		  , rti_STOP
		  , rti_E_Brake
		};

	protected:
		enum { rtiLast_Motor_Protocol = rti_E_Brake };

	public:
		inline RTInSignal Start_UP( void );
		inline RTInSignal Start_DOWN( void );
		inline RTInSignal STOP( void );
		inline RTInSignal E_Brake( void );
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
		enum { rtiLast_Motor_Protocol = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal Start_UP( const bool & data );
		inline RTOutSignal Start_DOWN( const bool & data );
		inline RTOutSignal STOP( const bool & data );
		inline RTOutSignal E_Brake( const bool & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Motor_Protocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline Motor_Protocol::Base::~Base( void )
{
}

inline RTInSignal Motor_Protocol::Base::Start_UP( void )
{
	return RTInSignal( this, rti_Start_UP );
}

inline RTInSignal Motor_Protocol::Base::Start_DOWN( void )
{
	return RTInSignal( this, rti_Start_DOWN );
}

inline RTInSignal Motor_Protocol::Base::STOP( void )
{
	return RTInSignal( this, rti_STOP );
}

inline RTInSignal Motor_Protocol::Base::E_Brake( void )
{
	return RTInSignal( this, rti_E_Brake );
}

inline Motor_Protocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Motor_Protocol::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal Motor_Protocol::Conjugate::Start_UP( const bool & data )
{
	return RTOutSignal( this, Base::rti_Start_UP, &data, &RTType_bool );
}

inline RTOutSignal Motor_Protocol::Conjugate::Start_DOWN( const bool & data )
{
	return RTOutSignal( this, Base::rti_Start_DOWN, &data, &RTType_bool );
}

inline RTOutSignal Motor_Protocol::Conjugate::STOP( const bool & data )
{
	return RTOutSignal( this, Base::rti_STOP, &data, &RTType_bool );
}

inline RTOutSignal Motor_Protocol::Conjugate::E_Brake( const bool & data )
{
	return RTOutSignal( this, Base::rti_E_Brake, &data, &RTType_bool );
}

#endif /* Motor_Protocol_H */

// }}}RME
