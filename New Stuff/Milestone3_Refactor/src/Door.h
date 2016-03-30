// {{{RME classifier 'Logical View::Door'

#ifndef Door_H
#define Door_H

#ifdef PRAGMA
#pragma interface "Door.h"
#endif

#include <RTSystem/Milestone3_Refactor.h>
#include <Door_Protocol.h>
#include <Door_Test.h>

// {{{RME tool 'OT::Cpp' property 'HeaderPreface'
// {{{USR

// }}}USR
// }}}RME

extern const RTActorClass Door;

#define SUPER RTActor
class Door_Actor : public RTActor
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
	// {{{RME classAttribute 'DoorTimer_ID'
	RTTimerId DoorTimer_ID;
	// }}}RME

protected:
	// {{{RME port 'Door_Test'
	Door_Test::Base Door_Test;
	// }}}RME
	// {{{RME port 'Door_Timer'
	Timing::Base Door_Timer;
	// }}}RME
	// {{{RME port 'Door_IN'
	Door_Protocol::Base Door_IN;
	// }}}RME

public:
	Door_Actor( RTController * rtg_rts, RTActorRef * rtg_ref );
	virtual ~Door_Actor( void );
	virtual int _followInV( RTBindingEnd & rtg_end, int rtg_portId, int rtg_repIndex );

protected:
	// {{{RME transition ':TOP:Door_Closed:J5154A1CF02FD:Door_Open_Start'
	INLINE_METHODS void transition2_Door_Open_Start( const bool * rtdata, RTProtocol * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Door_Opening:J5154A1EC0163:Door_Open_Finish'
	INLINE_METHODS void transition3_Door_Open_Finish( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Door_Open:J5154A1F50096:Door_Close_Start'
	INLINE_METHODS void transition4_Door_Close_Start( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Door_Closing:J5154A1FC0141:Door_Close_Finish'
	INLINE_METHODS void transition5_Door_Close_Finish( const void * rtdata, Timing::Base * rtport );
	// }}}RME
	// {{{RME transition ':TOP:Door_Closing:J5154A2340169:Door_Obstructed'
	INLINE_METHODS void transition6_Door_Obstructed( const bool * rtdata, Door_Test::Base * rtport );
	// }}}RME

private:
	INLINE_CHAINS void chain1_Initial( void );
	INLINE_CHAINS void chain2_Door_Open_Start( void );
	INLINE_CHAINS void chain3_Door_Open_Finish( void );
	INLINE_CHAINS void chain4_Door_Close_Start( void );
	INLINE_CHAINS void chain6_Door_Obstructed( void );
	INLINE_CHAINS void chain5_Door_Close_Finish( void );

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

#endif /* Door_H */

// }}}RME
