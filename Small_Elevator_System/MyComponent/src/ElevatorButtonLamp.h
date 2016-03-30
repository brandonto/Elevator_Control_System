// {{{RME classifier 'Logical View::ElevatorButtonLamp'

#ifndef ElevatorButtonLamp_H
#define ElevatorButtonLamp_H

#ifdef PRAGMA
#pragma interface "ElevatorButtonLamp.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EBLEBProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ElevatorButtonLamp;

#define SUPER RTActor
class ElevatorButtonLamp_Actor : public RTActor
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
	// {{{RME port 'EBLEBPort'
	EBLEBProtocol::Base EBLEBPort;
	// }}}RME

public:
	ElevatorButtonLamp_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ElevatorButtonLamp_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain3_light( void );
	INLINE_CHAINS void chain2_ignoreUnlight( void );
	INLINE_CHAINS void chain5_ignoreLight( void );
	INLINE_CHAINS void chain4_unlight( void );

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

#endif /* ElevatorButtonLamp_H */

// }}}RME
