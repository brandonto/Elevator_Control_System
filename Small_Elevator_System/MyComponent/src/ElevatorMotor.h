// {{{RME classifier 'Logical View::ElevatorMotor'

#ifndef ElevatorMotor_H
#define ElevatorMotor_H

#ifdef PRAGMA
#pragma interface "ElevatorMotor.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEMProtocol.h>
class ElevatorStatus;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ElevatorMotor;

#define SUPER RTActor
class ElevatorMotor_Actor : public RTActor
{
public:
	// {{{RME tool 'OT::Cpp' property 'PublicDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

protected:
	// {{{RME tool 'OT::Cpp' property 'ProtectedDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME

private:
	// {{{RME tool 'OT::Cpp' property 'PrivateDeclarations'
	// {{{USR

	// }}}USR
	// }}}RME
	// {{{RME classAttribute 'id'
	int id;
	// }}}RME

protected:
	// {{{RME port 'LEMPort'
	LEMProtocol::Base LEMPort;
	// }}}RME
	// {{{RME port 'moveTimer'
	Timing::Base moveTimer;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	ElevatorMotor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ElevatorMotor_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Stopped:J56E0B1DF037B:moveUp'
	INLINE_METHODS void transition2_moveUp( const void * rtdata, LEMProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J56E0B1F40232:moveDown'
	INLINE_METHODS void transition3_moveDown( const void * rtdata, LEMProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:MoveUp:J56E0B201039D:stop'
	INLINE_METHODS void transition4_stop( const void * rtdata, LEMProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:MoveDown:J56E0B22202DD:stop'
	INLINE_METHODS void transition5_stop( const void * rtdata, LEMProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:MoveUp:J56FAF2DD00C8:arrivedAtFloor'
	INLINE_METHODS void transition6_arrivedAtFloor( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:MoveDown:J56FAF5B702A9:arriveAtFloor'
	INLINE_METHODS void transition7_arriveAtFloor( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J56FAF85402D3:ignoreTimeout'
	INLINE_METHODS void transition8_ignoreTimeout( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J56FB2E0F03E1:init'
	INLINE_METHODS void transition12_init( const void * rtdata, LEMProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain12_init( void );
	INLINE_CHAINS void chain2_moveUp( void );
	INLINE_CHAINS void chain3_moveDown( void );
	INLINE_CHAINS void chain9_ignoreStop( void );
	INLINE_CHAINS void chain8_ignoreTimeout( void );
	INLINE_CHAINS void chain10_ignoreMoveUp( void );
	INLINE_CHAINS void chain4_stop( void );
	INLINE_CHAINS void chain6_arrivedAtFloor( void );
	INLINE_CHAINS void chain11_ignoreMoveDown( void );
	INLINE_CHAINS void chain5_stop( void );
	INLINE_CHAINS void chain7_arriveAtFloor( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_ElevatorMotor_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ElevatorMotor_H */

// }}}RME
