// {{{RME classifier 'Logical View::Central_Coordinator'

#ifndef Central_Coordinator_H
#define Central_Coordinator_H

#ifdef PRAGMA
#pragma interface "Central_Coordinator.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Elevator_Request_Protocol.h>
#include <F_Buttons.h>
#include <Service_Modes.h>
#include <System_Constants.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Central_Coordinator;

#define SUPER RTActor
class Central_Coordinator_Actor : public RTActor
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
	// {{{RME classAttribute 'Elevator_List'
	int Elevator_List[ NUM_ELEVATORS ];
	// }}}RME
	// {{{RME classAttribute 'Motor_Saver_Mode'
	bool Motor_Saver_Mode;
	// }}}RME

protected:
	// {{{RME capsuleRole 'System_Elevators'
	RTActorRef System_Elevators;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME
	// {{{RME port 'Central_OUT'
	Elevator_Request_Protocol::Base Central_OUT;
	// }}}RME
	// {{{RME port 'F_Buttons_IN'
	F_Buttons::Base F_Buttons_IN;
	// }}}RME
	// {{{RME port 'Service_Modes_IN'
	Service_Modes::Base Service_Modes_IN;
	// }}}RME

public:
	Central_Coordinator_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Central_Coordinator_Actor( void );

protected:
	// {{{RME operation 'Assign_Floor_Request(int)'
	void Assign_Floor_Request( int floor_req );
	// }}}RME

public:
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J51599FFE01E8:Handle_Request'
	INLINE_METHODS void transition2_Handle_Request( const int * rtdata, F_Buttons::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J51608D720180:Update_Elevator_Info'
	INLINE_METHODS void transition3_Update_Elevator_Info( const int * rtdata, Elevator_Request_Protocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J5160C6CC023C:Change_Service_Mode'
	INLINE_METHODS void transition4_Change_Service_Mode( const void * rtdata, Service_Modes::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain3_Update_Elevator_Info( void );
	INLINE_CHAINS void chain2_Handle_Request( void );
	INLINE_CHAINS void chain4_Change_Service_Mode( void );

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
	static const RTFieldDescriptor rtg_Central_Coordinator_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Central_Coordinator_H */

// }}}RME
