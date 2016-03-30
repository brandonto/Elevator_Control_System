// {{{RME classifier 'Logical View::Local_Controller'

#ifndef Local_Controller_H
#define Local_Controller_H

#ifdef PRAGMA
#pragma interface "Local_Controller.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Elevator_Internals.h>
#include <Elevator_Request_Protocol.h>
#include <System_Constants.h>
extern const RTActorClass Elevator;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Local_Controller;

#define SUPER RTActor
class Local_Controller_Actor : public RTActor
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
	// {{{RME classAttribute 'Path_List'
	int Path_List[ NUM_FLOORS ];
	// }}}RME
	// {{{RME classAttribute 'Current_Floor'
	int Current_Floor;
	// }}}RME
	// {{{RME classAttribute 'Floors_in_Path'
	int Floors_in_Path;
	// }}}RME
	// {{{RME classAttribute 'Direction_of_Travel'
	int Direction_of_Travel;
	// }}}RME
	// {{{RME classAttribute 'Elevator_Index'
	int Elevator_Index;
	// }}}RME
	// {{{RME classAttribute 'E_Brake'
	bool E_Brake;
	// }}}RME

protected:
	// {{{RME capsuleRole 'Elevator_Buttons_Handler'
	RTActorRef Elevator_Buttons_Handler;
	// }}}RME
	// {{{RME capsuleRole 'elevator_body'
	RTActorRef elevator_body;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME
	// {{{RME port 'Updater'
	Timing::Base Updater;
	// }}}RME
	// {{{RME port 'Elevator_Request_Line_OUT'
	Elevator_Request_Protocol::Conjugate Elevator_Request_Line_OUT;
	// }}}RME
	// {{{RME port 'Central_IN'
	Elevator_Request_Protocol::Conjugate Central_IN;
	// }}}RME
	// {{{RME port 'Elevator_Internals_OUT'
	Elevator_Internals::Base Elevator_Internals_OUT;
	// }}}RME

public:
	Local_Controller_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Local_Controller_Actor( void );

protected:
	// {{{RME operation 'Add_Floor_Request(int)'
	void Add_Floor_Request( int Floor_Number );
	// }}}RME
	// {{{RME operation 'Order_Path()'
	void Order_Path( void );
	// }}}RME
	// {{{RME operation 'Clear_Path_List()'
	void Clear_Path_List( void );
	// }}}RME
	// {{{RME operation 'Remove_Current_Floor()'
	void Remove_Current_Floor( void );
	// }}}RME

public:
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J5160971603E1:Handle_Floor_Request_Internal'
	INLINE_METHODS void transition2_Handle_Floor_Request_Internal( const int * rtdata, Elevator_Request_Protocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51587D6D03E5:Arrive_at_Floor'
	INLINE_METHODS void transition3_Arrive_at_Floor( const void * rtdata, Elevator_Internals::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51587F200387:New_Current_Floor'
	INLINE_METHODS void transition4_New_Current_Floor( const int * rtdata, Elevator_Internals::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J51608853014E:Update'
	INLINE_METHODS void transition5_Update( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J5160972300D3:Handle_Floor_Request_External'
	INLINE_METHODS void transition6_Handle_Floor_Request_External( const int * rtdata, Elevator_Request_Protocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J5160B140001E:E_BRAKE'
	INLINE_METHODS void transition7_E_BRAKE( const void * rtdata, Elevator_Internals::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J5160B3F103C1:Open_Doors'
	INLINE_METHODS void transition8_Open_Doors( const void * rtdata, Elevator_Request_Protocol::Conjugate * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain5_Update( void );
	INLINE_CHAINS void chain2_Handle_Floor_Request_Internal( void );
	INLINE_CHAINS void chain8_Open_Doors( void );
	INLINE_CHAINS void chain6_Handle_Floor_Request_External( void );
	INLINE_CHAINS void chain3_Arrive_at_Floor( void );
	INLINE_CHAINS void chain4_New_Current_Floor( void );
	INLINE_CHAINS void chain7_E_BRAKE( void );

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
	static const RTFieldDescriptor rtg_Local_Controller_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Local_Controller_H */

// }}}RME
