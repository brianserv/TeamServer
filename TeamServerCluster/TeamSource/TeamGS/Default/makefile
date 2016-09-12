################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include GameServer/Logic/Role/subdir.mk
-include GameServer/Logic/Resource/subdir.mk
-include GameServer/Logic/Resource/JsonTable/TableLimit/subdir.mk
-include GameServer/Logic/Resource/JsonTable/TableGift/subdir.mk
-include GameServer/Logic/Resource/JsonTable/TableBroadcast/subdir.mk
-include GameServer/Logic/Resource/JsonTable/TableBetTea/subdir.mk
-include GameServer/Logic/PrizePool/subdir.mk
-include GameServer/Logic/Message/WSSMessage/subdir.mk
-include GameServer/Logic/Message/PSMessage/subdir.mk
-include GameServer/Logic/Message/HGSMessage/subdir.mk
-include GameServer/Logic/Message/subdir.mk
-include GameServer/Logic/Message/GTMessage/subdir.mk
-include GameServer/Logic/Message/GSMessage/subdir.mk
-include GameServer/Logic/Message/GCMessage/subdir.mk
-include GameServer/Logic/Message/DLMessage/subdir.mk
-include GameServer/Logic/Message/DBMessage/subdir.mk
-include GameServer/Logic/Message/CSMessage/subdir.mk
-include GameServer/Logic/Httplink/subdir.mk
-include GameServer/Logic/Girl/subdir.mk
-include GameServer/Logic/GameHall/Texas/TexasRoom/subdir.mk
-include GameServer/Logic/GameHall/Texas/TexasRole/subdir.mk
-include GameServer/Logic/GameHall/Texas/TexasGame/subdir.mk
-include GameServer/Logic/GameHall/subdir.mk
-include GameServer/Logic/GameFormula/subdir.mk
-include GameServer/Logic/DBCache/subdir.mk
-include GameServer/Logic/DBCache/DBHallEntity/subdir.mk
-include GameServer/Logic/Card/subdir.mk
-include GameServer/FrameWork/subdir.mk
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
all: /mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamGameServer

# Tool invocations
/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamGameServer: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/native_lib/Platform/Linux/Debug -L/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/lib -o"/mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamGameServer" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) /mnt/hgfs/E/TeamServerCluster/Bin/Platform/Linux/Debug/TeamGameServer
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
