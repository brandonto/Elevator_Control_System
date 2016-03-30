// {{{RME classifier 'Logical View::Elevator'

#ifndef Elevator_H
#define Elevator_H

#ifdef PRAGMA
#pragma interface "Elevator.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Door_Protocol.h>
#include <Elevator_Internals.h>
#include <Elevator_Test.h>
#include <Motor_Protocol.h>
#include <System_Constants.h>

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
	// {{{RME classAttribute 'TravelTimer_ID'
	RTTimerId TravelTimer_ID;
	// }}}RME
	// {{{RME classAttribute 'WatchDogTimer_ID'
	RTTimerId WatchDogTimer_ID;
	// }}}RME
	// {{{RME classAttribute 'Door_Ack_Wait'
	bool Door_Ack_Wait;
	// }}}RME
	// {{{RME classAttribute 'Target_Floor'
	int Target_Floor;
	// }}}RME
	// {{{RME classAttribute 'Current_Floor'
	int Current_Floor;
	// }}}RME
	// {{{RME classAttribute 'Target_Update'
	bool Target_Update;
	// }}}RME
	// {{{RME classAttribute 'DepartureTimer_ID'
	RTTimerId DepartureTimer_ID;
	// }}}RME

protected:
	// {{{RME capsuleRole 'Elevator_Door'
	RTActorRef Elevator_Door;
	// }}}RME
	// {{{RME capsuleRole 'Elevator_Motor'
	RTActorRef Elevator_Motor;
	// }}}RME
	// {{{RME port 'Travel_Timer'
	Timing::Base Travel_Timer;
	// }}}RME
	// {{{RME port 'WatchDog_Timer'
	Timing::Base WatchDog_Timer;
	// }}}RME
	// {{{RME port 'Elevator_Test'
	Elevator_Test::Base Elevator_Test;
	// }}}RME
	// {{{RME port 'Departure_Timer'
	Timing::Base Departure_Timer;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME
	// {{{RME port 'Door_OUT'
	Door_Protocol::Conjugate Door_OUT;
	// }}}RME
	// {{{RME port 'Motor_OUT'
	Motor_Protocol::Conjugate Motor_OUT;
	// }}}RME
	// {{{RME port 'Elevator_Internals_IN'
	Elevator_Internals::Conjugate Elevator_Internals_IN;
	// }}}RME

public:
	Elevator_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Elevator_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME enter ':TOP:Stopped'
	INLINE_METHODS void enter2_Stopped( void );
	// }}}RME
	virtual void enterStateV( void );
	// {{{RME enter ':TOP:Moving_Up'
	INLINE_METHODS void enter3_Moving_Up( void );
	// }}}RME
	// {{{RME enter ':TOP:Moving_Down'
	INLINE_METHODS void enter4_Moving_Down( void );
	// }}}RME
	// {{{RME enter ':TOP:Emergency_Stopped'
	INLINE_METHODS void enter5_Emergency_Stopped( void );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J51560A4201AB:Door_Open_Ack' guard '1'
	INLINE_METHODS int guard1_Door_Open_Ack_event1( const bool * rtdata, Door_Protocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J51560A4201AB:Door_Open_Ack'
	INLINE_METHODS void transition1_Door_Open_Ack( const bool * rtdata, Door_Protocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J5154C269036D:Moving_Up_A_Floor' guard '1'
	INLINE_METHODS int guard2_Moving_Up_A_Floor_event1( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J5154C269036D:Moving_Up_A_Floor'
	INLINE_METHODS void transition2_Moving_Up_A_Floor( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Up:J5154C2C900FF:Arriving_Up' guard '1'
	INLINE_METHODS int guard3_Arriving_Up_event1( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Up:J5154C2C900FF:Arriving_Up'
	INLINE_METHODS void transition3_Arriving_Up( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Up:J5154C5130034:Move_Another_Floor_Up' guard '1'
	INLINE_METHODS int guard4_Move_Another_Floor_Up_event1( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J5154C2B00299:Moving_Down_A_Floor' guard '1'
	INLINE_METHODS int guard5_Moving_Down_A_Floor_event1( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J5154C2B00299:Moving_Down_A_Floor'
	INLINE_METHODS void transition5_Moving_Down_A_Floor( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Down:J5154C2CB0256:Arriving_Down' guard '1'
	INLINE_METHODS int guard6_Arriving_Down_event1( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Down:J5154C2CB0256:Arriving_Down'
	INLINE_METHODS void transition6_Arriving_Down( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Down:J5154C52D0010:Move_Another_Floor_Down' guard '1'
	INLINE_METHODS int guard7_Move_Another_Floor_Down_event1( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J5154C30002FB:E_Brake'
	INLINE_METHODS void transition8_E_Brake( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Up:J5154C36F0145:E_Brake'
	INLINE_METHODS void transition9_E_Brake( const bool * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Down:J5154C30F01E0:E_Brake'
	INLINE_METHODS void transition10_E_Brake( const bool * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition11_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Stopped:J51587BFB0397:New_Target'
	INLINE_METHODS void transition12_New_Target( const int * rtdata, Elevator_Internals::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Up:J51587C4000B8:New_Target'
	INLINE_METHODS void transition13_New_Target( const int * rtdata, Elevator_Internals::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Moving_Down:J51587C5703D5:New_Target'
	INLINE_METHODS void transition14_New_Target( const int * rtdata, Elevator_Internals::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Doors_Open:J515887D70327:New_Target'
	INLINE_METHODS void transition16_New_Target( const int * rtdata, Elevator_Internals::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain11_Initial( void );
	INLINE_CHAINS void chain8_E_Brake( void );
	INLINE_CHAINS void chain2_Moving_Up_A_Floor( void );
	INLINE_CHAINS void chain5_Moving_Down_A_Floor( void );
	INLINE_CHAINS void chain1_Door_Open_Ack( void );
	INLINE_CHAINS void chain12_New_Target( void );
	INLINE_CHAINS void chain17_Open_Doors( void );
	INLINE_CHAINS void chain3_Arriving_Up( void );
	INLINE_CHAINS void chain4_Move_Another_Floor_Up( void );
	INLINE_CHAINS void chain9_E_Brake( void );
	INLINE_CHAINS void chain13_New_Target( void );
	INLINE_CHAINS void chain6_Arriving_Down( void );
	INLINE_CHAINS void chain7_Move_Another_Floor_Down( void );
	INLINE_CHAINS void chain10_E_Brake( void );
	INLINE_CHAINS void chain14_New_Target( void );
	INLINE_CHAINS void chain15_Doors_Closed( void );
	INLINE_CHAINS void chain16_New_Target( void );

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
