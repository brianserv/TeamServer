################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WebSocketServer/FrameWork/BackendClient.cpp \
../WebSocketServer/FrameWork/BaseDefine.cpp \
../WebSocketServer/FrameWork/ConfigFile.cpp \
../WebSocketServer/FrameWork/DataBuffer.cpp \
../WebSocketServer/FrameWork/HallClient.cpp \
../WebSocketServer/FrameWork/PlayerClient.cpp \
../WebSocketServer/FrameWork/WebSocketApplication.cpp \
../WebSocketServer/FrameWork/WebSocketServer.cpp \
../WebSocketServer/FrameWork/WebSocketService.cpp \
../WebSocketServer/FrameWork/main.cpp 

OBJS += \
./WebSocketServer/FrameWork/BackendClient.o \
./WebSocketServer/FrameWork/BaseDefine.o \
./WebSocketServer/FrameWork/ConfigFile.o \
./WebSocketServer/FrameWork/DataBuffer.o \
./WebSocketServer/FrameWork/HallClient.o \
./WebSocketServer/FrameWork/PlayerClient.o \
./WebSocketServer/FrameWork/WebSocketApplication.o \
./WebSocketServer/FrameWork/WebSocketServer.o \
./WebSocketServer/FrameWork/WebSocketService.o \
./WebSocketServer/FrameWork/main.o 

CPP_DEPS += \
./WebSocketServer/FrameWork/BackendClient.d \
./WebSocketServer/FrameWork/BaseDefine.d \
./WebSocketServer/FrameWork/ConfigFile.d \
./WebSocketServer/FrameWork/DataBuffer.d \
./WebSocketServer/FrameWork/HallClient.d \
./WebSocketServer/FrameWork/PlayerClient.d \
./WebSocketServer/FrameWork/WebSocketApplication.d \
./WebSocketServer/FrameWork/WebSocketServer.d \
./WebSocketServer/FrameWork/WebSocketService.d \
./WebSocketServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
WebSocketServer/FrameWork/%.o: ../WebSocketServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


