// {{{RME classifier 'Logical View::Door_Protocol'

#ifndef Door_Protocol_H
#define Door_Protocol_H

#ifdef PRAGMA
#pragma interface "Door_Protocol.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct Door_Protocol
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_Command_Door_Open = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_Door_Protocol = rti_Command_Door_Open };

	public:
		inline RTInSignal Command_Door_Open( void );
		inline RTOutSignal Doors_Closed( const bool & data );
		inline RTOutSignal Doors_Open( const bool & data );
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
			rti_Doors_Closed = rtiLast_RTRootProtocol + 1
		  , rti_Doors_Open
		};

	protected:
		enum { rtiLast_Door_Protocol = rti_Doors_Open };

	public:
		inline RTInSignal Doors_Closed( void );
		inline RTInSignal Doors_Open( void );
		inline RTOutSignal Command_Door_Open( const bool & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Door_Protocol::Base::Base( void )
	: RTRootProtocol()
{
}

inline Door_Protocol::Base::~Base( void )
{
}

inline RTInSignal Door_Protocol::Base::Command_Door_Open( void )
{
	return RTInSignal( this, rti_Command_Door_Open );
}

inline RTOutSignal Door_Protocol::Base::Doors_Closed( const bool & data )
{
	return RTOutSignal( this, Conjugate::rti_Doors_Closed, &data, &RTType_bool );
}

inline RTOutSignal Door_Protocol::Base::Doors_Open( const bool & data )
{
	return RTOutSignal( this, Conjugate::rti_Doors_Open, &data, &RTType_bool );
}

inline Door_Protocol::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Door_Protocol::Conjugate::~Conjugate( void )
{
}

inline RTInSignal Door_Protocol::Conjugate::Doors_Closed( void )
{
	return RTInSignal( this, rti_Doors_Closed );
}

inline RTInSignal Door_Protocol::Conjugate::Doors_Open( void )
{
	return RTInSignal( this, rti_Doors_Open );
}

inline RTOutSignal Door_Protocol::Conjugate::Command_Door_Open( const bool & data )
{
	return RTOutSignal( this, Base::rti_Command_Door_Open, &data, &RTType_bool );
}

#endif /* Door_Protocol_H */

// }}}RME
