RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = "M:/SYSC 4805/Elevator Project Part Deux/New Stuff/Milestone 3 - March 29.rtmdl"
COMPONENT = "Component View::Milestone3_Refactor"
RTGEN_FLAGS = -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/Milestone3_Refactor.dep>
TARGETS = $(Milestone3_Refactor_SYSTARGET)
RTGENERATE_TARGET = $(TARGETS)
RTGENERATE_DAT = rtgenerate.dat

RTgenerate : $(RTGENERATE_TARGET)

.PRECIOUS : $(TARGETS)

$(Milestone3_Refactor_SYSTARGET) : $(Milestone3_Refactor_SYSDEPS) $(RTGENERATE_DAT)
	$(RTGEN) $(RTGEN_FLAGS) -system

