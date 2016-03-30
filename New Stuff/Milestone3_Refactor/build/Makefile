RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
PLATFORM = NT40
THREADED = T
LIBRARY_SET = x86-VisualC++-6.0
USER_CC = $(CC)
USER_CCFLAGS = $(DEBUG_TAG)
USER_INCPATHS = $(INCLUDE_TAG)../src
USER_DEPPATHS = $(DEPEND_TAG) ../src
TOP_CAPSULE = TopLevelCapsule
BUILD_TARGET = Milestone3_Refactor$(EXEC_EXT)
USER_LD = $(LD)
USER_LDFLAGS =
USER_OBJS =
USER_LIBS =
RTCOMPONENT_LIBS =
RTCOMPONENT_LIBS_DEP = $(RTCOMPONENT_LIBS)
SOURCE_DIR = ../src
RTCOMPILE_DAT = rtcompile.dat
RTLINK_DAT = rtlink.dat
ALL_OBJS = \
	Central_Coordinator$(OBJ_EXT) \
	Door$(OBJ_EXT) \
	Door_Protocol$(OBJ_EXT) \
	Door_Test$(OBJ_EXT) \
	E_Buttons$(OBJ_EXT) \
	Elevator$(OBJ_EXT) \
	Elevator_Buttons$(OBJ_EXT) \
	Elevator_Internals$(OBJ_EXT) \
	Elevator_Request_Protocol$(OBJ_EXT) \
	Elevator_Test$(OBJ_EXT) \
	F_Buttons$(OBJ_EXT) \
	Local_Controller$(OBJ_EXT) \
	Motor$(OBJ_EXT) \
	Motor_Protocol$(OBJ_EXT) \
	Service_Modes$(OBJ_EXT) \
	System_Constants$(OBJ_EXT) \
	TopLevelCapsule$(OBJ_EXT) \
	RTSystem/Milestone3_Refactor$(OBJ_EXT)

ALL_OBJS_LISTFILE = ALL_OBJS.olist
COMPILE_TARGET = $(BUILD_TARGET)
PURIFY_TARGET = Purify_Milestone3_Refactor$(EXEC_EXT)
PURIFY = purify $(PURIFY_OPTIONS)
PURIFY_OPTIONS = "-log-file=$(PURIFY_TARGET).txt" -windows=no
RTCOMPONENT = "Component View::Milestone3_Refactor"
USER_OBJS_LIST = $(USER_OBJS)
SPACEDEPS = -spacify dq
include <Central_Coordinator.dep>
include <Door.dep>
include <Door_Protocol.dep>
include <Door_Test.dep>
include <E_Buttons.dep>
include <Elevator.dep>
include <Elevator_Buttons.dep>
include <Elevator_Internals.dep>
include <Elevator_Request_Protocol.dep>
include <Elevator_Test.dep>
include <F_Buttons.dep>
include <Local_Controller.dep>
include <Motor.dep>
include <Motor_Protocol.dep>
include <Service_Modes.dep>
include <System_Constants.dep>
include <TopLevelCapsule.dep>
include <RTSystem/Milestone3_Refactor.dep>
include <$(RTS_HOME)/codegen/ms_nmake.mk>

RTcompile : $(COMPILE_TARGET)

RTpurify : $(PURIFY_TARGET)

$(BUILD_TARGET) : $(ALL_OBJS) $(USER_OBJS) $(RTCOMPONENT_LIBS_DEP) $(ALL_OBJS_LISTFILE) $(RTLINK_DAT)
	$(RTLINK) -vendor $(VENDOR) -exe "$(BUILD_TARGET)" -component $(RTCOMPONENT) -- \
		$(USER_LD) $(LD_HEAD) $(USER_LDFLAGS) \
		$(ALL_OBJS_LIST) $(USER_OBJS_LIST) \
		$(RTCOMPONENT_LIBS) $(USER_LIBS) $(LD_TAIL)

$(PURIFY_TARGET) : $(ALL_OBJS) $(USER_OBJS) $(RTCOMPONENT_LIBS_DEP) $(ALL_OBJS_LISTFILE) $(RTLINK_DAT)
	$(RTLINK) -vendor $(VENDOR) -purify -exe "$(PURIFY_TARGET)" -component $(RTCOMPONENT) -- \
		$(PURIFY) $(USER_LD) $(LD_HEAD) $(USER_LDFLAGS) \
		$(ALL_OBJS_LIST) $(USER_OBJS_LIST) \
		$(RTCOMPONENT_LIBS) $(USER_LIBS) $(LD_TAIL)

Central_Coordinator$(OBJ_EXT) : $(Central_Coordinator_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Central_Coordinator $(SOURCE_DIR)/Central_Coordinator.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Central_Coordinator.cpp $(CC_TAIL)

Door$(OBJ_EXT) : $(Door_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Door $(SOURCE_DIR)/Door.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Door.cpp $(CC_TAIL)

Door_Protocol$(OBJ_EXT) : $(Door_Protocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Door_Protocol $(SOURCE_DIR)/Door_Protocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Door_Protocol.cpp $(CC_TAIL)

Door_Test$(OBJ_EXT) : $(Door_Test_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Door_Test $(SOURCE_DIR)/Door_Test.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Door_Test.cpp $(CC_TAIL)

E_Buttons$(OBJ_EXT) : $(E_Buttons_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src E_Buttons $(SOURCE_DIR)/E_Buttons.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/E_Buttons.cpp $(CC_TAIL)

Elevator$(OBJ_EXT) : $(Elevator_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Elevator $(SOURCE_DIR)/Elevator.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Elevator.cpp $(CC_TAIL)

Elevator_Buttons$(OBJ_EXT) : $(Elevator_Buttons_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Elevator_Buttons $(SOURCE_DIR)/Elevator_Buttons.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Elevator_Buttons.cpp $(CC_TAIL)

Elevator_Internals$(OBJ_EXT) : $(Elevator_Internals_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Elevator_Internals $(SOURCE_DIR)/Elevator_Internals.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Elevator_Internals.cpp $(CC_TAIL)

Elevator_Request_Protocol$(OBJ_EXT) : $(Elevator_Request_Protocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Elevator_Request_Protocol $(SOURCE_DIR)/Elevator_Request_Protocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Elevator_Request_Protocol.cpp $(CC_TAIL)

Elevator_Test$(OBJ_EXT) : $(Elevator_Test_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Elevator_Test $(SOURCE_DIR)/Elevator_Test.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Elevator_Test.cpp $(CC_TAIL)

F_Buttons$(OBJ_EXT) : $(F_Buttons_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src F_Buttons $(SOURCE_DIR)/F_Buttons.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/F_Buttons.cpp $(CC_TAIL)

Local_Controller$(OBJ_EXT) : $(Local_Controller_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Local_Controller $(SOURCE_DIR)/Local_Controller.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Local_Controller.cpp $(CC_TAIL)

Motor$(OBJ_EXT) : $(Motor_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Motor $(SOURCE_DIR)/Motor.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Motor.cpp $(CC_TAIL)

Motor_Protocol$(OBJ_EXT) : $(Motor_Protocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Motor_Protocol $(SOURCE_DIR)/Motor_Protocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Motor_Protocol.cpp $(CC_TAIL)

Service_Modes$(OBJ_EXT) : $(Service_Modes_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Service_Modes $(SOURCE_DIR)/Service_Modes.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Service_Modes.cpp $(CC_TAIL)

System_Constants$(OBJ_EXT) : $(System_Constants_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src System_Constants $(SOURCE_DIR)/System_Constants.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/System_Constants.cpp $(CC_TAIL)

TopLevelCapsule$(OBJ_EXT) : $(TopLevelCapsule_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src TopLevelCapsule $(SOURCE_DIR)/TopLevelCapsule.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/TopLevelCapsule.cpp $(CC_TAIL)

RTSystem/Milestone3_Refactor$(OBJ_EXT) : $(Milestone3_Refactor_SYSDEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-dep Milestone3_Refactor_SYSDEPS RTSystem/Milestone3_Refactor.dep \
		-component $(RTCOMPONENT) -src Milestone3_Refactor ../src/RTSystem/Milestone3_Refactor.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		../src/RTSystem/Milestone3_Refactor.cpp $(CC_TAIL)

