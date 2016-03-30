// {{{RME classifier 'Logical View::FloorButton'

#ifndef FloorButton_H
#define FloorButton_H

#ifdef PRAGMA
#pragma interface "FloorButton.h"
#endif

#include <RTSystem/MyComponent.h>
#include <FBFProtocol.h>
#include <FBLFBProtocol.h>
#include <UFBPort.h>
class Constants;

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass FloorButton;

#define SUPER RTActor
class FloorButton_Actor : public RTActor
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
	// {{{RME classAttribute 'active'
	bool active;
	// }}}RME
	// {{{RME classAttribute 'upDir'
	bool upDir;
	// }}}RME

protected:
	// {{{RME capsuleRole 'floorButtonLamp'
	RTActorRef floorButtonLamp;
	// }}}RME
	// {{{RME port 'FBFPort'
	FBFProtocol::Base FBFPort;
	// }}}RME
	// {{{RME port 'UFBPort'
	UFBPort::Base UFBPort;
	// }}}RME
	// {{{RME port 'log'
	Log::Base log;
	// }}}RME
	// {{{RME port 'FBLFBPort'
	FBLFBProtocol::Conjugate FBLFBPort;
	// }}}RME

public:
	FloorButton_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~FloorButton_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );
	virtual int _followOutV( RTBindingEnd & rtg_end, int rtg_compId, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:inactive:J56FC12190333:init'
	INLINE_METHODS void transition1_init( const int * rtdata, FBFProtocol::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Unpressed:J56FC10680042:floorButtonPressed'
	INLINE_METHODS void transition2_floorButtonPressed( const void * rtdata, UFBPort::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Initial:Initial'
	INLINE_METHODS void transition4_Initial( const void * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Pressed:J56FC1F2E039E:clearButton'
	INLINE_METHODS void transition7_clearButton( const void * rtdata, FBFProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain4_Initial( void );
	INLINE_CHAINS void chain2_floorButtonPressed( void );
	INLINE_CHAINS void chain7_clearButton( void );
	INLINE_CHAINS void chain3_ignorePress( void );
	INLINE_CHAINS void chain1_init( void );

protected:
	// {{{RME choicePoint ':TOP:isActive'
	INLINE_METHODS int choicePoint1_isActive( const int * rtdata, FBFProtocol::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain5_True( void );
	INLINE_CHAINS void chain6_False( void );

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
	static const RTFieldDescriptor rtg_FloorButton_fields[];
};
#undef SUPER

// {{{RME tool 'OT::Cpp' property 'HeaderEnding'
// {{{USR

// }}}USR
// }}}RME

#endif /* FloorButton_H */

// }}}RME
