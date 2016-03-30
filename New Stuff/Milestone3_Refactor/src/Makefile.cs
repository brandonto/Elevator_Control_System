RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = "M:/SYSC 4805/Elevator Project Part Deux/New Stuff/Milestone 3 - March 29.rtmdl"
COMPONENT = "Component View::Milestone3_Refactor"
RTGEN_FLAGS = -codesync -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/Milestone3_Refactor.dep>
CODESYNC_TARGETS = $(Milestone3_Refactor_SYSTARGET_CS)
RTCODESYNC_TARGET = $(CODESYNC_TARGETS)

RTcodesync : $(RTCODESYNC_TARGET)

.PRECIOUS : $(CODESYNC_TARGETS)

$(Milestone3_Refactor_SYSTARGET_CS) : $(Milestone3_Refactor_SYSDEPS_CS)
	$(RTGEN) $(RTGEN_FLAGS) -system

