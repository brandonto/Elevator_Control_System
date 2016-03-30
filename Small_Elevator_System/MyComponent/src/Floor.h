// {{{RME classifier 'Logical View::Floor'

#ifndef Floor_H
#define Floor_H

#ifdef PRAGMA
#pragma interface "Floor.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FBFProtocol.h>
#include <FCProtocol.h>
class ButtonInfo;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Floor;

#define SUPER RTActor
class Floor_Actor : public RTActor
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
	// {{{RME capsuleRole 'floorButton'
	RTActorRef floorButton;
	// }}}RME
	// {{{RME port 'FCPort'
	FCProtocol::Base FCPort;
	// }}}RME
	// {{{RME port 'FBFPort'
	FBFProtocol::Conjugate FBFPort;
	// }}}RME
	// {{{RME port 'initTimer'
	Timing::Base initTimer;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME

public:
	Floor_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Floor_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition1_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FB39B1032F:pressFloorButton'
	INLINE_METHODS void transition2_pressFloorButton( const bool * rtdata, FBFProtocol::Conjugate * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FC0E900351:init'
	INLINE_METHODS void transition3_init( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Ready:J56FC1E960292:arrivedAtFloor'
	INLINE_METHODS void transition4_arrivedAtFloor( const ButtonInfo * rtdata, FCProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain4_arrivedAtFloor( void );
	INLINE_CHAINS void chain2_pressFloorButton( void );
	INLINE_CHAINS void chain3_init( void );

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
	static const RTFieldDescriptor rtg_Floor_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* Floor_H */

// }}}RME
