################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WebSocketServer/Logic/Message/WBMessage/WBMessage.cpp 

OBJS += \
./WebSocketServer/Logic/Message/WBMessage/WBMessage.o 

CPP_DEPS += \
./WebSocketServer/Logic/Message/WBMessage/WBMessage.d 


# Each subdirectory must supply rules for building sources it contributes
WebSocketServer/Logic/Message/WBMessage/%.o: ../WebSocketServer/Logic/Message/WBMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


