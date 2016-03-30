// {{{RME classifier 'Logical View::Elevator_Buttons'

#ifndef Elevator_Buttons_H
#define Elevator_Buttons_H

#ifdef PRAGMA
#pragma interface "Elevator_Buttons.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <E_Buttons.h>
#include <Elevator_Request_Protocol.h>
#include <System_Constants.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Elevator_Buttons;

#define SUPER RTActor
class Elevator_Buttons_Actor : public RTActor
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

protected:
	// {{{RME port 'Elevator_Request_Line_IN'
	Elevator_Request_Protocol::Base Elevator_Request_Line_IN;
	// }}}RME
	// {{{RME port 'Buttons_IN'
	E_Buttons::Base Buttons_IN;
	// }}}RME

public:
	Elevator_Buttons_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Elevator_Buttons_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Idle:J51575363012B:Handle_Button_Press'
	INLINE_METHODS void transition2_Handle_Button_Press( const int * rtdata, E_Buttons::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Idle:J5160B37C01A0:Open_Doors_Button'
	INLINE_METHODS void transition3_Open_Doors_Button( const void * rtdata, E_Buttons::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_Handle_Button_Press( void );
	INLINE_CHAINS void chain3_Open_Doors_Button( void );

public:
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTPortDescriptor rtg_ports[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Elevator_Buttons_H */

// }}}RME
