// {{{RME classifier 'Logical View::Motor'

#ifndef Motor_H
#define Motor_H

#ifdef PRAGMA
#pragma interface "Motor.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Motor_Protocol.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Motor;

#define SUPER RTActor
class Motor_Actor : public RTActor
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
	// {{{RME port 'Motor_IN'
	Motor_Protocol::Base Motor_IN;
	// }}}RME

public:
	Motor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Motor_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_Start_Up( void );
	INLINE_CHAINS void chain4_Start_Down( void );
	INLINE_CHAINS void chain8_E_Brake( void );
	INLINE_CHAINS void chain5_Stop( void );
	INLINE_CHAINS void chain6_E_Brake( void );
	INLINE_CHAINS void chain3_Stop( void );
	INLINE_CHAINS void chain7_E_Brake( void );

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

#endif /* Motor_H */

// }}}RME
