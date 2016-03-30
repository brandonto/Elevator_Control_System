// {{{RME classifier 'Logical View::ElevatorDoor'

#ifndef ElevatorDoor_H
#define ElevatorDoor_H

#ifdef PRAGMA
#pragma interface "ElevatorDoor.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EDDSProtocol.h>
#include <LEDProtocol.h>
class ElevatorStatus;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ElevatorDoor;

#define SUPER RTActor
class ElevatorDoor_Actor : public RTActor
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
	// {{{RME classAttribute 'es'
	ElevatorStatus * es;
	// }}}RME

protected:
	// {{{RME capsuleRole 'doorSensor'
	RTActorRef doorSensor;
	// }}}RME
	// {{{RME port 'LEDPort'
	LEDProtocol::Base LEDPort;
	// }}}RME
	// {{{RME port 'EDDSPort'
	EDDSProtocol::Conjugate EDDSPort;
	// }}}RME
	// {{{RME port 'doorTimer'
	Timing::Base doorTimer;
	// }}}RME
	// {{{RME port 'closeTimer'
	Timing::Base closeTimer;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	ElevatorDoor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ElevatorDoor_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Closed:J56FB14B003AE:openDoor'
	INLINE_METHODS void transition2_openDoor( const void * rtdata, LEDProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Opened:J56FB14B5027F:closeDoor'
	INLINE_METHODS void transition3_closeDoor( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Closed:J56FB2E660011:init'
	INLINE_METHODS void transition4_init( const void * rtdata, LEDProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Opening:J56FBEF9B0125:doorOpened'
	INLINE_METHODS void transition6_doorOpened( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Closing:J56FBF20503B0:doorClosed'
	INLINE_METHODS void transition8_doorClosed( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Closing:J56FBF27D0218:impede'
	INLINE_METHODS void transition9_impede( const void * rtdata, EDDSProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Closing:J56FC59A200D0:openDoor'
	INLINE_METHODS void transition11_openDoor( const void * rtdata, LEDProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain4_init( void );
	INLINE_CHAINS void chain2_openDoor( void );
	INLINE_CHAINS void chain5_ignore( void );
	INLINE_CHAINS void chain10_ignore( void );
	INLINE_CHAINS void chain3_closeDoor( void );
	INLINE_CHAINS void chain11_openDoor( void );
	INLINE_CHAINS void chain12_ignoreClose( void );
	INLINE_CHAINS void chain9_impede( void );
	INLINE_CHAINS void chain8_doorClosed( void );
	INLINE_CHAINS void chain7_ignore( void );
	INLINE_CHAINS void chain6_doorOpened( void );

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
	static const RTFieldDescriptor rtg_ElevatorDoor_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ElevatorDoor_H */

// }}}RME
