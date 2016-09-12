################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/DBCache/DBHallEntity/DBHallEntity.cpp \
../GameServer/Logic/DBCache/DBHallEntity/DBHallEntityManager.cpp 

OBJS += \
./GameServer/Logic/DBCache/DBHallEntity/DBHallEntity.o \
./GameServer/Logic/DBCache/DBHallEntity/DBHallEntityManager.o 

CPP_DEPS += \
./GameServer/Logic/DBCache/DBHallEntity/DBHallEntity.d \
./GameServer/Logic/DBCache/DBHallEntity/DBHallEntityManager.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/DBCache/DBHallEntity/%.o: ../GameServer/Logic/DBCache/DBHallEntity/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


