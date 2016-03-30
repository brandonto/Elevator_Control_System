// {{{RME classifier 'Logical View::Elevator_Test'

#ifndef Elevator_Test_H
#define Elevator_Test_H

#ifdef PRAGMA
#pragma interface "Elevator_Test.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct Elevator_Test
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum { rti_TEST_Doors_Open = rtiLast_RTRootProtocol + 1 };

	protected:
		enum { rtiLast_Elevator_Test = rti_TEST_Doors_Open };

	public:
		inline RTInSignal TEST_Doors_Open( void );
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
		enum { rtiLast_Elevator_Test = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal TEST_Doors_Open( const bool & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Elevator_Test::Base::Base( void )
	: RTRootProtocol()
{
}

inline Elevator_Test::Base::~Base( void )
{
}

inline RTInSignal Elevator_Test::Base::TEST_Doors_Open( void )
{
	return RTInSignal( this, rti_TEST_Doors_Open );
}

inline Elevator_Test::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Elevator_Test::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal Elevator_Test::Conjugate::TEST_Doors_Open( const bool & data )
{
	return RTOutSignal( this, Base::rti_TEST_Doors_Open, &data, &RTType_bool );
}

#endif /* Elevator_Test_H */

// }}}RME
