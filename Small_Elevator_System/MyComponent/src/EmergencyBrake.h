// {{{RME classifier 'Logical View::EmergencyBrake'

#ifndef EmergencyBrake_H
#define EmergencyBrake_H

#ifdef PRAGMA
#pragma interface "EmergencyBrake.h"
#endif

#include <RTSystem/MyComponent.h>
#include <LEBRProtocol.h>
class ElevatorStatus;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass EmergencyBrake;

#define SUPER RTActor
class EmergencyBrake_Actor : public RTActor
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
	// {{{RME classAttribute 'es'
	ElevatorStatus * es;
	// }}}RME

protected:
	// {{{RME port 'LEBRPort'
	LEBRProtocol::Base LEBRPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	EmergencyBrake_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~EmergencyBrake_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Unactivated:J56FC35CD02BB:init'
	INLINE_METHODS void transition2_init( const void * rtdata, LEBRProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Unactivated:J56FC35E90300:activateEmergencyBrakes'
	INLINE_METHODS void transition3_activateEmergencyBrakes( const void * rtdata, LEBRProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_init( void );
	INLINE_CHAINS void chain3_activateEmergencyBrakes( void );

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
	static const RTFieldDescriptor rtg_EmergencyBrake_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* EmergencyBrake_H */

// }}}RME
