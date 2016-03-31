// {{{RME classifier 'Logical View::Elevator'

#ifndef Elevator_H
#define Elevator_H

#ifdef PRAGMA
#pragma interface "Elevator.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EPProtocol.h>
#include <ElevatorStatus.h>
#include <LEProtocol.h>
class ButtonInfo;
class Constants;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Elevator;

#define SUPER RTActor
class Elevator_Actor : public RTActor
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
	// {{{RME classAttribute 'es'
	ElevatorStatus * es;
	// }}}RME

protected:
	// {{{RME capsuleRole 'localController'
	RTActorRef localController;
	// }}}RME
	// {{{RME port 'LEPort'
	LEProtocol::Conjugate LEPort;
	// }}}RME
	// {{{RME port 'EPPort'
	EPProtocol::Conjugate EPPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME
	// {{{RME port 'initTimer'
	Timing::Base initTimer;
	// }}}RME

public:
	Elevator_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Elevator_Actor( void );

protected:
	// {{{RME operation 'update()'
	void update( void );
	// }}}RME

public:
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FC070100AE:elevatorButtonPressed'
	INLINE_METHODS void transition2_elevatorButtonPressed( const ButtonInfo * rtdata, LEProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FC4E3D0305:arrivedAtFloor'
	INLINE_METHODS void transition3_arrivedAtFloor( const void * rtdata, LEProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB04610211:update'
	INLINE_METHODS void transition4_update( const void * rtdata, EPProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB15A60330:doorClosed'
	INLINE_METHODS void transition5_doorClosed( const void * rtdata, LEProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB25B10282:init'
	INLINE_METHODS void transition6_init( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FC665B02FB:activateEmergencyBrakes'
	INLINE_METHODS void transition7_activateEmergencyBrakes( const void * rtdata, LEProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_elevatorButtonPressed( void );
	INLINE_CHAINS void chain3_arrivedAtFloor( void );
	INLINE_CHAINS void chain5_doorClosed( void );
	INLINE_CHAINS void chain7_activateEmergencyBrakes( void );
	INLINE_CHAINS void chain4_update( void );
	INLINE_CHAINS void chain6_init( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTComponentDescriptor rtg_capsule_roles[];
	static const RTPortDescriptor rtg_ports[];

public:
	static const RTFieldDescriptor rtg_Elevator_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Elevator_H */

// }}}RME
