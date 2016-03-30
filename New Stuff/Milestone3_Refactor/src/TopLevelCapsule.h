// {{{RME classifier 'Logical View::TopLevelCapsule'

#ifndef TopLevelCapsule_H
#define TopLevelCapsule_H

#ifdef PRAGMA
#pragma interface "TopLevelCapsule.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass TopLevelCapsule;

#define SUPER RTActor
class TopLevelCapsule_Actor : public RTActor
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
	// {{{RME capsuleRole 'central_ControllerR1'
	RTActorRef central_ControllerR1;
	// }}}RME

public:
	TopLevelCapsule_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~TopLevelCapsule_Actor( void );
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

#endif /* TopLevelCapsule_H */

// }}}RME
