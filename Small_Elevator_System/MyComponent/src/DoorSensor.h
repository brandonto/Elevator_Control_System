// {{{RME classifier 'Logical View::DoorSensor'

#ifndef DoorSensor_H
#define DoorSensor_H

#ifdef PRAGMA
#pragma interface "DoorSensor.h"
#endif

#include <RTSystem/MyComponent.h>
#include <EDDSProtocol.h>
#include <UDSProtocol.h>
class ElevatorStatus;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass DoorSensor;

#define SUPER RTActor
class DoorSensor_Actor : public RTActor
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
	// {{{RME port 'EDDSPort'
	EDDSProtocol::Base EDDSPort;
	// }}}RME
	// {{{RME port 'UDSPort'
	UDSProtocol::Base UDSPort;
	// }}}RME

public:
	DoorSensor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~DoorSensor_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Ready:J56FBEC8602DA:init'
	INLINE_METHODS void transition2_init( const void * rtdata, EDDSProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FBED4F0370:impede'
	INLINE_METHODS void transition3_impede( const void * rtdata, UDSProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_init( void );
	INLINE_CHAINS void chain3_impede( void );

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
	static const RTFieldDescriptor rtg_DoorSensor_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* DoorSensor_H */

// }}}RME
