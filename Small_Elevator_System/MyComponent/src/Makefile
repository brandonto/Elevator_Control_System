RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = "M:/SYSC 4805/ElevatorProject/Elevator_Control_System/Small_Elevator_System/Small_Elevator_System.rtmdl"
COMPONENT = "Component View::MyComponent"
RTGEN_FLAGS = -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/MyComponent.dep>
TARGETS = $(MyComponent_SYSTARGET)
RTGENERATE_TARGET = $(TARGETS)
RTGENERATE_DAT = rtgenerate.dat

RTgenerate : $(RTGENERATE_TARGET)

.PRECIOUS : $(TARGETS)

$(MyComponent_SYSTARGET) : $(MyComponent_SYSDEPS) $(RTGENERATE_DAT)
	$(RTGEN) $(RTGEN_FLAGS) -system

