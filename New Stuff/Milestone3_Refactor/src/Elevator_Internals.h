// {{{RME classifier 'Logical View::Elevator_Internals'

#ifndef Elevator_Internals_H
#define Elevator_Internals_H

#ifdef PRAGMA
#pragma interface "Elevator_Internals.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct Elevator_Internals
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_Arrived_Target = rtiLast_RTRootProtocol + 1
		  , rti_New_Current_Floor
		  , rti_E_Brake_Engaged
		};

	protected:
		enum { rtiLast_Elevator_Internals = rti_E_Brake_Engaged };

	public:
		inline RTInSignal Arrived_Target( void );
		inline RTInSignal New_Current_Floor( void );
		inline RTInSignal E_Brake_Engaged( void );
		inline RTOutSignal New_Target( const int & data );
		inline RTOutSignal Open_Doors( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
	class Conjugate : public RTRootProtocol
	{
	public:
		inline Conjugate( void );
		inline ~Conjugate( void );
		enum
		{
			rti_New_Target = rtiLast_RTRootProtocol + 1
		  , rti_Open_Doors
		};

	protected:
		enum { rtiLast_Elevator_Internals = rti_Open_Doors };

	public:
		inline RTInSignal New_Target( void );
		inline RTInSignal Open_Doors( void );
		inline RTOutSignal Arrived_Target( void );
		inline RTOutSignal New_Current_Floor( const int & data );
		inline RTOutSignal E_Brake_Engaged( void );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Elevator_Internals::Base::Base( void )
	: RTRootProtocol()
{
}

inline Elevator_Internals::Base::~Base( void )
{
}

inline RTInSignal Elevator_Internals::Base::Arrived_Target( void )
{
	return RTInSignal( this, rti_Arrived_Target );
}

inline RTInSignal Elevator_Internals::Base::New_Current_Floor( void )
{
	return RTInSignal( this, rti_New_Current_Floor );
}

inline RTInSignal Elevator_Internals::Base::E_Brake_Engaged( void )
{
	return RTInSignal( this, rti_E_Brake_Engaged );
}

inline RTOutSignal Elevator_Internals::Base::New_Target( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_New_Target, &data, &RTType_int );
}

inline RTOutSignal Elevator_Internals::Base::Open_Doors( void )
{
	return RTOutSignal( this, Conjugate::rti_Open_Doors, (const void *)0, &RTType_void );
}

inline Elevator_Internals::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Elevator_Internals::Conjugate::~Conjugate( void )
{
}

inline RTInSignal Elevator_Internals::Conjugate::New_Target( void )
{
	return RTInSignal( this, rti_New_Target );
}

inline RTInSignal Elevator_Internals::Conjugate::Open_Doors( void )
{
	return RTInSignal( this, rti_Open_Doors );
}

inline RTOutSignal Elevator_Internals::Conjugate::Arrived_Target( void )
{
	return RTOutSignal( this, Base::rti_Arrived_Target, (const void *)0, &RTType_void );
}

inline RTOutSignal Elevator_Internals::Conjugate::New_Current_Floor( const int & data )
{
	return RTOutSignal( this, Base::rti_New_Current_Floor, &data, &RTType_int );
}

inline RTOutSignal Elevator_Internals::Conjugate::E_Brake_Engaged( void )
{
	return RTOutSignal( this, Base::rti_E_Brake_Engaged, (const void *)0, &RTType_void );
}

#endif /* Elevator_Internals_H */

// }}}RME
