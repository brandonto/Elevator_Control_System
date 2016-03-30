// {{{RME classifier 'Logical View::ElevatorButton'

#ifndef ElevatorButton_H
#define ElevatorButton_H

#ifdef PRAGMA
#pragma interface "ElevatorButton.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EBLEBProtocol.h>
#include <LEBProtocol.h>
#include <UEBProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ElevatorButton;

#define SUPER RTActor
class ElevatorButton_Actor : public RTActor
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
	// {{{RME capsuleRole 'elevatorButtonLamp'
	RTActorRef elevatorButtonLamp;
	// }}}RME
	// {{{RME port 'LEBPort'
	LEBProtocol::Base LEBPort;
	// }}}RME
	// {{{RME port 'UEBPort'
	UEBProtocol::Base UEBPort;
	// }}}RME
	// {{{RME port 'EBLEBPort'
	EBLEBProtocol::Conjugate EBLEBPort;
	// }}}RME

public:
	ElevatorButton_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ElevatorButton_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Unpressed:J56FC3EC6014A:elevatorButtonPressed'
	INLINE_METHODS void transition2_elevatorButtonPressed( const void * rtdata, UEBProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Pressed:J56FC3EED0164:clearButton'
	INLINE_METHODS void transition3_clearButton( const void * rtdata, LEBProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain5_ignoreClearButton( void );
	INLINE_CHAINS void chain2_elevatorButtonPressed( void );
	INLINE_CHAINS void chain3_clearButton( void );
	INLINE_CHAINS void chain4_ignorePress( void );

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
	static const RTFieldDescriptor rtg_ElevatorButton_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ElevatorButton_H */

// }}}RME
