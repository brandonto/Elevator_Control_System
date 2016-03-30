// {{{RME classifier 'Logical View::FloorButtonLamp'

#ifndef FloorButtonLamp_H
#define FloorButtonLamp_H

#ifdef PRAGMA
#pragma interface "FloorButtonLamp.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FBLFBProtocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass FloorButtonLamp;

#define SUPER RTActor
class FloorButtonLamp_Actor : public RTActor
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
	// {{{RME port 'FBLFBPort'
	FBLFBProtocol::Base FBLFBPort;
	// }}}RME

public:
	FloorButtonLamp_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~FloorButtonLamp_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_light( void );
	INLINE_CHAINS void chain4_ignoreUnlight( void );
	INLINE_CHAINS void chain5_ignoreLight( void );
	INLINE_CHAINS void chain3_unlight( void );

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

#endif /* FloorButtonLamp_H */

// }}}RME
