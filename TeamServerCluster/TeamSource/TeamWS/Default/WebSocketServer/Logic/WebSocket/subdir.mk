################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WebSocketServer/Logic/WebSocket/WebSocketFrameHandler.cpp \
../WebSocketServer/Logic/WebSocket/WebSocketWorker.cpp 

OBJS += \
./WebSocketServer/Logic/WebSocket/WebSocketFrameHandler.o \
./WebSocketServer/Logic/WebSocket/WebSocketWorker.o 

CPP_DEPS += \
./WebSocketServer/Logic/WebSocket/WebSocketFrameHandler.d \
./WebSocketServer/Logic/WebSocket/WebSocketWorker.d 


# Each subdirectory must supply rules for building sources it contributes
WebSocketServer/Logic/WebSocket/%.o: ../WebSocketServer/Logic/WebSocket/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


