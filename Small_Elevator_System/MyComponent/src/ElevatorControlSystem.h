// {{{RME classifier 'Logical View::ElevatorControlSystem'

#ifndef ElevatorControlSystem_H
#define ElevatorControlSystem_H

#ifdef PRAGMA
#pragma interface "ElevatorControlSystem.h"
#endif

#include <RTSystem/MyComponent.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass ElevatorControlSystem;

#define SUPER RTActor
class ElevatorControlSystem_Actor : public RTActor
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
	// {{{RME capsuleRole 'centralController'
	RTActorRef centralController;
	// }}}RME
	// {{{RME capsuleRole 'elevator'
	RTActorRef elevator;
	// }}}RME

public:
	ElevatorControlSystem_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~ElevatorControlSystem_Actor( void );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );
	virtual void rtsBehavior( int signalIndex, int portIndex );
	virtual const RTActor_class * getActorData( void ) const;

protected:
	static const RTActor_class rtg_class;

public:
	static const RTStateId rtg_parent_state[];

private:
	static const RTComponentDescriptor rtg_capsule_roles[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* ElevatorControlSystem_H */

// }}}RME
