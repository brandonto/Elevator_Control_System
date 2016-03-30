// {{{RME classifier 'Logical View::Elevator_Request_Protocol'

#ifndef Elevator_Request_Protocol_H
#define Elevator_Request_Protocol_H

#ifdef PRAGMA
#pragma interface "Elevator_Request_Protocol.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct Elevator_Request_Protocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_Update_Information = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_Elevator_Request_Protocol = rti_Update_Information };

	public:
		inline RTInSignal Update_Information( void );
		inline RTOutSignal Add_Floor_Request( const int & data );
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
			rti_Add_Floor_Request = rtiLast_RTRootProtocol + 1
		  , rti_Open_Doors
		};

	protected:
		enum { rtiLast_Elevator_Request_Protocol = rti_Open_Doors };

	public:
		inline RTInSignal Add_Floor_Request( void );
		inline RTInSignal Open_Doors( void );
		inline RTOutSignal Update_Information( const int & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Elevator_Request_Protocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline Elevator_Request_Protocol::Base::~Base( void )
{
}

inline RTInSignal Elevator_Request_Protocol::Base::Update_Information( void )
{
	return RTInSignal( this, rti_Update_Information );
}

inline RTOutSignal Elevator_Request_Protocol::Base::Add_Floor_Request( const int & data )
{
	return RTOutSignal( this, Conjugate::rti_Add_Floor_Request, &data, &RTType_int );
}

inline RTOutSignal Elevator_Request_Protocol::Base::Open_Doors( void )
{
	return RTOutSignal( this, Conjugate::rti_Open_Doors, (const void *)0, &RTType_void );
}

inline Elevator_Request_Protocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Elevator_Request_Protocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal Elevator_Request_Protocol::Conjugate::Add_Floor_Request( void )
{
	return RTInSignal( this, rti_Add_Floor_Request );
}

inline RTInSignal Elevator_Request_Protocol::Conjugate::Open_Doors( void )
{
	return RTInSignal( this, rti_Open_Doors );
}

inline RTOutSignal Elevator_Request_Protocol::Conjugate::Update_Information( const int & data )
{
	return RTOutSignal( this, Base::rti_Update_Information, &data, &RTType_int );
}

#endif /* Elevator_Request_Protocol_H */

// }}}RME
