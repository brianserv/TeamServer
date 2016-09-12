################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/DBCache/DBHallHandler.cpp \
../GameServer/Logic/DBCache/DBManager.cpp 

OBJS += \
./GameServer/Logic/DBCache/DBHallHandler.o \
./GameServer/Logic/DBCache/DBManager.o 

CPP_DEPS += \
./GameServer/Logic/DBCache/DBHallHandler.d \
./GameServer/Logic/DBCache/DBManager.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/DBCache/%.o: ../GameServer/Logic/DBCache/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


