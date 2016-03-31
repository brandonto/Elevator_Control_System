RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
include <$(RTS_HOME)/codegen/rtgen.mk>
MODEL = "M:/SYSC 4805/ElevatorProject/Elevator_Control_System/Small_Elevator_System/Small_Elevator_System.rtmdl"
COMPONENT = "Component View::MyComponent"
RTGEN_FLAGS = -codesync -model $(MODEL) -component $(COMPONENT) -spacedeps dq
include <RTSystem/MyComponent.dep>
CODESYNC_TARGETS = $(MyComponent_SYSTARGET_CS)
RTCODESYNC_TARGET = $(CODESYNC_TARGETS)

RTcodesync : $(RTCODESYNC_TARGET)

.PRECIOUS : $(CODESYNC_TARGETS)

$(MyComponent_SYSTARGET_CS) : $(MyComponent_SYSDEPS_CS)
	$(RTGEN) $(RTGEN_FLAGS) -system

