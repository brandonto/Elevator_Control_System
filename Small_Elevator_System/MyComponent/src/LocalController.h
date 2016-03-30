// {{{RME classifier 'Logical View::LocalController'

#ifndef LocalController_H
#define LocalController_H

#ifdef PRAGMA
#pragma interface "LocalController.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEBProtocol.h>
#include <LEBRProtocol.h>
#include <LEDProtocol.h>
#include <LEMProtocol.h>
#include <LEProtocol.h>
class ButtonInfo;
class ElevatorStatus;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass LocalController;

#define SUPER RTActor
class LocalController_Actor : public RTActor
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
	// {{{RME capsuleRole 'elevatorMotor'
	RTActorRef elevatorMotor;
	// }}}RME
	// {{{RME capsuleRole 'elevatorDoor'
	RTActorRef elevatorDoor;
	// }}}RME
	// {{{RME capsuleRole 'emergencyBrake'
	RTActorRef emergencyBrake;
	// }}}RME
	// {{{RME capsuleRole 'elevatorButton'
	RTActorRef elevatorButton;
	// }}}RME
	// {{{RME port 'LEPort'
	LEProtocol::Base LEPort;
	// }}}RME
	// {{{RME port 'LEMPort'
	LEMProtocol::Conjugate LEMPort;
	// }}}RME
	// {{{RME port 'LEDPort'
	LEDProtocol::Conjugate LEDPort;
	// }}}RME
	// {{{RME port 'LEBRPort'
	LEBRProtocol::Conjugate LEBRPort;
	// }}}RME
	// {{{RME port 'LEBPort'
	LEBProtocol::Conjugate LEBPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	LocalController_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~LocalController_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Ready:J56FC05E3011B:elevatorButtonPressed'
	INLINE_METHODS void transition2_elevatorButtonPressed( const int * rtdata, LEBProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56E0AD2E0043:moveElevator'
	INLINE_METHODS void transition3_moveElevator( const int * rtdata, LEProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FAF39101FE:arrivedAtFloor'
	INLINE_METHODS void transition4_arrivedAtFloor( const void * rtdata, LEMProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB13130365:openDoor'
	INLINE_METHODS void transition5_openDoor( const void * rtdata, LEProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB15530146:doorClosed'
	INLINE_METHODS void transition6_doorClosed( const void * rtdata, LEDProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB2DA700CA:init'
	INLINE_METHODS void transition7_init( const void * rtdata, LEProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FC4FA0036C:clearButton'
	INLINE_METHODS void transition8_clearButton( const int * rtdata, LEProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain7_init( void );
	INLINE_CHAINS void chain3_moveElevator( void );
	INLINE_CHAINS void chain5_openDoor( void );
	INLINE_CHAINS void chain8_clearButton( void );
	INLINE_CHAINS void chain4_arrivedAtFloor( void );
	INLINE_CHAINS void chain6_doorClosed( void );
	INLINE_CHAINS void chain2_elevatorButtonPressed( void );

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
	static const RTFieldDescriptor rtg_LocalController_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* LocalController_H */

// }}}RME
