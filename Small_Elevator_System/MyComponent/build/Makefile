RTS_HOME = C:/Program Files/Rational/Rose RealTime/C++/TargetRTS
PLATFORM = NT40
THREADED = T
LIBRARY_SET = x86-VisualC++-6.0
USER_CC = $(CC)
USER_CCFLAGS = $(DEBUG_TAG)
USER_INCPATHS = $(INCLUDE_TAG)../src
USER_DEPPATHS = $(DEPEND_TAG) ../src
TOP_CAPSULE = ElevatorControlSystem
BUILD_TARGET = MyComponent$(EXEC_EXT)
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
	ButtonInfo$(OBJ_EXT) \
	CentralController$(OBJ_EXT) \
	Constants$(OBJ_EXT) \
	DoorSensor$(OBJ_EXT) \
	EBLEBProtocol$(OBJ_EXT) \
	EDDSProtocol$(OBJ_EXT) \
	EPProtocol$(OBJ_EXT) \
	Elevator$(OBJ_EXT) \
	ElevatorButton$(OBJ_EXT) \
	ElevatorButtonLamp$(OBJ_EXT) \
	ElevatorControlSystem$(OBJ_EXT) \
	ElevatorDoor$(OBJ_EXT) \
	ElevatorDoorButton$(OBJ_EXT) \
	ElevatorMotor$(OBJ_EXT) \
	ElevatorStatus$(OBJ_EXT) \
	EmergencyBrake$(OBJ_EXT) \
	FBFProtocol$(OBJ_EXT) \
	FBLFBProtocol$(OBJ_EXT) \
	FCProtocol$(OBJ_EXT) \
	Floor$(OBJ_EXT) \
	FloorButton$(OBJ_EXT) \
	FloorButtonLamp$(OBJ_EXT) \
	LEBProtocol$(OBJ_EXT) \
	LEBRProtocol$(OBJ_EXT) \
	LEDBProtocol$(OBJ_EXT) \
	LEDProtocol$(OBJ_EXT) \
	LEMProtocol$(OBJ_EXT) \
	LEProtocol$(OBJ_EXT) \
	LocalController$(OBJ_EXT) \
	UDSProtocol$(OBJ_EXT) \
	UEBProtocol$(OBJ_EXT) \
	UEDBProtocol$(OBJ_EXT) \
	UFBPort$(OBJ_EXT) \
	RTSystem/MyComponent$(OBJ_EXT)

ALL_OBJS_LISTFILE = ALL_OBJS.olist
COMPILE_TARGET = $(BUILD_TARGET)
PURIFY_TARGET = Purify_MyComponent$(EXEC_EXT)
PURIFY = purify $(PURIFY_OPTIONS)
PURIFY_OPTIONS = "-log-file=$(PURIFY_TARGET).txt" -windows=no
RTCOMPONENT = "Component View::MyComponent"
USER_OBJS_LIST = $(USER_OBJS)
SPACEDEPS = -spacify dq
include <ButtonInfo.dep>
include <CentralController.dep>
include <Constants.dep>
include <DoorSensor.dep>
include <EBLEBProtocol.dep>
include <EDDSProtocol.dep>
include <EPProtocol.dep>
include <Elevator.dep>
include <ElevatorButton.dep>
include <ElevatorButtonLamp.dep>
include <ElevatorControlSystem.dep>
include <ElevatorDoor.dep>
include <ElevatorDoorButton.dep>
include <ElevatorMotor.dep>
include <ElevatorStatus.dep>
include <EmergencyBrake.dep>
include <FBFProtocol.dep>
include <FBLFBProtocol.dep>
include <FCProtocol.dep>
include <Floor.dep>
include <FloorButton.dep>
include <FloorButtonLamp.dep>
include <LEBProtocol.dep>
include <LEBRProtocol.dep>
include <LEDBProtocol.dep>
include <LEDProtocol.dep>
include <LEMProtocol.dep>
include <LEProtocol.dep>
include <LocalController.dep>
include <UDSProtocol.dep>
include <UEBProtocol.dep>
include <UEDBProtocol.dep>
include <UFBPort.dep>
include <RTSystem/MyComponent.dep>
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

ButtonInfo$(OBJ_EXT) : $(ButtonInfo_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src ButtonInfo $(SOURCE_DIR)/ButtonInfo.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/ButtonInfo.cpp $(CC_TAIL)

CentralController$(OBJ_EXT) : $(CentralController_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src CentralController $(SOURCE_DIR)/CentralController.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/CentralController.cpp $(CC_TAIL)

Constants$(OBJ_EXT) : $(Constants_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Constants $(SOURCE_DIR)/Constants.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Constants.cpp $(CC_TAIL)

DoorSensor$(OBJ_EXT) : $(DoorSensor_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src DoorSensor $(SOURCE_DIR)/DoorSensor.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/DoorSensor.cpp $(CC_TAIL)

EBLEBProtocol$(OBJ_EXT) : $(EBLEBProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src EBLEBProtocol $(SOURCE_DIR)/EBLEBProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/EBLEBProtocol.cpp $(CC_TAIL)

EDDSProtocol$(OBJ_EXT) : $(EDDSProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src EDDSProtocol $(SOURCE_DIR)/EDDSProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/EDDSProtocol.cpp $(CC_TAIL)

EPProtocol$(OBJ_EXT) : $(EPProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src EPProtocol $(SOURCE_DIR)/EPProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/EPProtocol.cpp $(CC_TAIL)

Elevator$(OBJ_EXT) : $(Elevator_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Elevator $(SOURCE_DIR)/Elevator.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Elevator.cpp $(CC_TAIL)

ElevatorButton$(OBJ_EXT) : $(ElevatorButton_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src ElevatorButton $(SOURCE_DIR)/ElevatorButton.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/ElevatorButton.cpp $(CC_TAIL)

ElevatorButtonLamp$(OBJ_EXT) : $(ElevatorButtonLamp_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src ElevatorButtonLamp $(SOURCE_DIR)/ElevatorButtonLamp.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/ElevatorButtonLamp.cpp $(CC_TAIL)

ElevatorControlSystem$(OBJ_EXT) : $(ElevatorControlSystem_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src ElevatorControlSystem $(SOURCE_DIR)/ElevatorControlSystem.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/ElevatorControlSystem.cpp $(CC_TAIL)

ElevatorDoor$(OBJ_EXT) : $(ElevatorDoor_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src ElevatorDoor $(SOURCE_DIR)/ElevatorDoor.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/ElevatorDoor.cpp $(CC_TAIL)

ElevatorDoorButton$(OBJ_EXT) : $(ElevatorDoorButton_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src ElevatorDoorButton $(SOURCE_DIR)/ElevatorDoorButton.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/ElevatorDoorButton.cpp $(CC_TAIL)

ElevatorMotor$(OBJ_EXT) : $(ElevatorMotor_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src ElevatorMotor $(SOURCE_DIR)/ElevatorMotor.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/ElevatorMotor.cpp $(CC_TAIL)

ElevatorStatus$(OBJ_EXT) : $(ElevatorStatus_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src ElevatorStatus $(SOURCE_DIR)/ElevatorStatus.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/ElevatorStatus.cpp $(CC_TAIL)

EmergencyBrake$(OBJ_EXT) : $(EmergencyBrake_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src EmergencyBrake $(SOURCE_DIR)/EmergencyBrake.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/EmergencyBrake.cpp $(CC_TAIL)

FBFProtocol$(OBJ_EXT) : $(FBFProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src FBFProtocol $(SOURCE_DIR)/FBFProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/FBFProtocol.cpp $(CC_TAIL)

FBLFBProtocol$(OBJ_EXT) : $(FBLFBProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src FBLFBProtocol $(SOURCE_DIR)/FBLFBProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/FBLFBProtocol.cpp $(CC_TAIL)

FCProtocol$(OBJ_EXT) : $(FCProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src FCProtocol $(SOURCE_DIR)/FCProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/FCProtocol.cpp $(CC_TAIL)

Floor$(OBJ_EXT) : $(Floor_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src Floor $(SOURCE_DIR)/Floor.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/Floor.cpp $(CC_TAIL)

FloorButton$(OBJ_EXT) : $(FloorButton_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src FloorButton $(SOURCE_DIR)/FloorButton.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/FloorButton.cpp $(CC_TAIL)

FloorButtonLamp$(OBJ_EXT) : $(FloorButtonLamp_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src FloorButtonLamp $(SOURCE_DIR)/FloorButtonLamp.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/FloorButtonLamp.cpp $(CC_TAIL)

LEBProtocol$(OBJ_EXT) : $(LEBProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src LEBProtocol $(SOURCE_DIR)/LEBProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/LEBProtocol.cpp $(CC_TAIL)

LEBRProtocol$(OBJ_EXT) : $(LEBRProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src LEBRProtocol $(SOURCE_DIR)/LEBRProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/LEBRProtocol.cpp $(CC_TAIL)

LEDBProtocol$(OBJ_EXT) : $(LEDBProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src LEDBProtocol $(SOURCE_DIR)/LEDBProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/LEDBProtocol.cpp $(CC_TAIL)

LEDProtocol$(OBJ_EXT) : $(LEDProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src LEDProtocol $(SOURCE_DIR)/LEDProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/LEDProtocol.cpp $(CC_TAIL)

LEMProtocol$(OBJ_EXT) : $(LEMProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src LEMProtocol $(SOURCE_DIR)/LEMProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/LEMProtocol.cpp $(CC_TAIL)

LEProtocol$(OBJ_EXT) : $(LEProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src LEProtocol $(SOURCE_DIR)/LEProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/LEProtocol.cpp $(CC_TAIL)

LocalController$(OBJ_EXT) : $(LocalController_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src LocalController $(SOURCE_DIR)/LocalController.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/LocalController.cpp $(CC_TAIL)

UDSProtocol$(OBJ_EXT) : $(UDSProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src UDSProtocol $(SOURCE_DIR)/UDSProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/UDSProtocol.cpp $(CC_TAIL)

UEBProtocol$(OBJ_EXT) : $(UEBProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src UEBProtocol $(SOURCE_DIR)/UEBProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/UEBProtocol.cpp $(CC_TAIL)

UEDBProtocol$(OBJ_EXT) : $(UEDBProtocol_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src UEDBProtocol $(SOURCE_DIR)/UEDBProtocol.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/UEDBProtocol.cpp $(CC_TAIL)

UFBPort$(OBJ_EXT) : $(UFBPort_DEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-component $(RTCOMPONENT) -src UFBPort $(SOURCE_DIR)/UFBPort.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		 $(SOURCE_DIR)/UFBPort.cpp $(CC_TAIL)

RTSystem/MyComponent$(OBJ_EXT) : $(MyComponent_SYSDEPS) $(RTCOMPILE_DAT)
	$(RTCOMP) -vendor $(VENDOR) $(SPACEDEPS) $(USER_DEPPATHS) \
		-dep MyComponent_SYSDEPS RTSystem/MyComponent.dep \
		-component $(RTCOMPONENT) -src MyComponent ../src/RTSystem/MyComponent.cpp -- \
		$(USER_CC) $(CC_HEAD) $(USER_CCFLAGS) $(USER_INCPATHS) \
		../src/RTSystem/MyComponent.cpp $(CC_TAIL)

