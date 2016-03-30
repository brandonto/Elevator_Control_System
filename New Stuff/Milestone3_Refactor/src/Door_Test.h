// {{{RME classifier 'Logical View::Door_Test'

#ifndef Door_Test_H
#define Door_Test_H

#ifdef PRAGMA
#pragma interface "Door_Test.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

struct Door_Test
{
	class Base : public RTRootProtocol
	{
	public:
		inline Base( void );
		inline ~Base( void );
		enum
		{
			rti_TEST_Door_Obstructed = rtiLast_RTRootProtocol + 1
		  , rti_TEST_Command_Door_Open
		};

	protected:
		enum { rtiLast_Door_Test = rti_TEST_Command_Door_Open };

	public:
		inline RTInSignal TEST_Door_Obstructed( void );
		inline RTInSignal TEST_Command_Door_Open( void );
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
		enum { rtiLast_Door_Test = rtiLast_RTRootProtocol };

	public:
		inline RTOutSignal TEST_Door_Obstructed( const bool & data );
		inline RTOutSignal TEST_Command_Door_Open( const bool & data );
		static const RTProtocolDescriptor rt_class;

	private:
		static const RTSignalDescriptor rt_signals[];
	};
};

inline Door_Test::Base::Base( void )
	: RTRootProtocol()
{
}

inline Door_Test::Base::~Base( void )
{
}

inline RTInSignal Door_Test::Base::TEST_Door_Obstructed( void )
{
	return RTInSignal( this, rti_TEST_Door_Obstructed );
}

inline RTInSignal Door_Test::Base::TEST_Command_Door_Open( void )
{
	return RTInSignal( this, rti_TEST_Command_Door_Open );
}

inline Door_Test::Conjugate::Conjugate( void )
	: RTRootProtocol()
{
}

inline Door_Test::Conjugate::~Conjugate( void )
{
}

inline RTOutSignal Door_Test::Conjugate::TEST_Door_Obstructed( const bool & data )
{
	return RTOutSignal( this, Base::rti_TEST_Door_Obstructed, &data, &RTType_bool );
}

inline RTOutSignal Door_Test::Conjugate::TEST_Command_Door_Open( const bool & data )
{
	return RTOutSignal( this, Base::rti_TEST_Command_Door_Open, &data, &RTType_bool );
}

#endif /* Door_Test_H */

// }}}RME
