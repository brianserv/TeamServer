################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include DLServer/Logic/Table/subdir.mk
-include DLServer/Logic/Message/subdir.mk
-include DLServer/Logic/DBCache/subdir.mk
-include DLServer/FrameWork/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: /mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamDLServer

# Tool invocations
/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamDLServer: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/native_lib/Platform/Linux/Debug -L/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/lib -o"/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamDLServer" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) /mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamDLServer
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
