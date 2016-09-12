################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/Role/Role.cpp \
../GameServer/Logic/Role/RoleAttr.cpp \
../GameServer/Logic/Role/RoleManager.cpp 

OBJS += \
./GameServer/Logic/Role/Role.o \
./GameServer/Logic/Role/RoleAttr.o \
./GameServer/Logic/Role/RoleManager.o 

CPP_DEPS += \
./GameServer/Logic/Role/Role.d \
./GameServer/Logic/Role/RoleAttr.d \
./GameServer/Logic/Role/RoleManager.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/Role/%.o: ../GameServer/Logic/Role/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


