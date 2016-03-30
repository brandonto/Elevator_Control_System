// {{{RME classifier 'Logical View::CentralController'

#ifndef CentralController_H
#define CentralController_H

#ifdef PRAGMA
#pragma interface "CentralController.h"
#endif

#include <RTSystem/MyComponent.h>
#include <Constants.h>
#include <EPProtocol.h>
#include <FCProtocol.h>
class ButtonInfo;
class ElevatorStatus;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass CentralController;

#define SUPER RTActor
class CentralController_Actor : public RTActor
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
	// {{{RME classAttribute 'esList'
	ElevatorStatus * esList[ NUM_ELEVATORS ];
	// }}}RME

protected:
	// {{{RME capsuleRole 'floor'
	RTActorRef floor;
	// }}}RME
	// {{{RME port 'EPPort'
	EPProtocol::Conjugate EPPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME
	// {{{RME port 'FCPort'
	FCProtocol::Conjugate FCPort;
	// }}}RME

public:
	CentralController_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~CentralController_Actor( void );

protected:
	// {{{RME operation 'schedule(int,bool)'
	void schedule( int floorId, bool upDir );
	// }}}RME
	// {{{RME operation 'abs(int)'
	int abs( int n );
	// }}}RME

public:
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Ready:J56E0A85700B7:elevatorButtonPressed'
	INLINE_METHODS void transition2_elevatorButtonPressed( const ButtonInfo * rtdata, EPProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB26CA0023:elevatorInit'
	INLINE_METHODS void transition3_elevatorInit( const void * rtdata, EPProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB3A78010C:floorButtonPressed'
	INLINE_METHODS void transition4_floorButtonPressed( const ButtonInfo * rtdata, FCProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FC1D970385:clearButton'
	INLINE_METHODS void transition5_clearButton( const ButtonInfo * rtdata, EPProtocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain3_elevatorInit( void );
	INLINE_CHAINS void chain2_elevatorButtonPressed( void );
	INLINE_CHAINS void chain5_clearButton( void );
	INLINE_CHAINS void chain4_floorButtonPressed( void );

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
	static const RTFieldDescriptor rtg_CentralController_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* CentralController_H */

// }}}RME
