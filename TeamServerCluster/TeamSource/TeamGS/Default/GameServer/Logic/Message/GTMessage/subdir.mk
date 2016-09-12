################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/Message/GTMessage/GTMessage.cpp \
../GameServer/Logic/Message/GTMessage/GTMessage_Ping.cpp 

OBJS += \
./GameServer/Logic/Message/GTMessage/GTMessage.o \
./GameServer/Logic/Message/GTMessage/GTMessage_Ping.o 

CPP_DEPS += \
./GameServer/Logic/Message/GTMessage/GTMessage.d \
./GameServer/Logic/Message/GTMessage/GTMessage_Ping.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/Message/GTMessage/%.o: ../GameServer/Logic/Message/GTMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


