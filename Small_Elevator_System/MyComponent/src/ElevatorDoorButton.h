// {{{RME classifier 'Logical View::ElevatorDoorButton'

#ifndef ElevatorDoorButton_H
#define ElevatorDoorButton_H

#ifdef PRAGMA
#pragma interface "ElevatorDoorButton.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEDBProtocol.h>
#include <UEDBProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ElevatorDoorButton;

#define SUPER RTActor
class ElevatorDoorButton_Actor : public RTActor
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
	// {{{RME port 'LEDBPort'
	LEDBProtocol::Base LEDBPort;
	// }}}RME
	// {{{RME port 'UEDBPort'
	UEDBProtocol::Base UEDBPort;
	// }}}RME

public:
	ElevatorDoorButton_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ElevatorDoorButton_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FC57C700E6:doorButtonPressed'
	INLINE_METHODS void transition2_doorButtonPressed( const void * rtdata, UEDBProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_doorButtonPressed( void );

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
	static const RTFieldDescriptor rtg_ElevatorDoorButton_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ElevatorDoorButton_H */

// }}}RME
