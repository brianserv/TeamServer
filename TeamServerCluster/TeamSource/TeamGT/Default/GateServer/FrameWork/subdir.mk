################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GateServer/FrameWork/BaseDefine.cpp \
../GateServer/FrameWork/ConfigFile.cpp \
../GateServer/FrameWork/DataBuffer.cpp \
../GateServer/FrameWork/GameClient.cpp \
../GateServer/FrameWork/GateApplication.cpp \
../GateServer/FrameWork/GateServer.cpp \
../GateServer/FrameWork/GateService.cpp \
../GateServer/FrameWork/PlayerClient.cpp \
../GateServer/FrameWork/main.cpp 

OBJS += \
./GateServer/FrameWork/BaseDefine.o \
./GateServer/FrameWork/ConfigFile.o \
./GateServer/FrameWork/DataBuffer.o \
./GateServer/FrameWork/GameClient.o \
./GateServer/FrameWork/GateApplication.o \
./GateServer/FrameWork/GateServer.o \
./GateServer/FrameWork/GateService.o \
./GateServer/FrameWork/PlayerClient.o \
./GateServer/FrameWork/main.o 

CPP_DEPS += \
./GateServer/FrameWork/BaseDefine.d \
./GateServer/FrameWork/ConfigFile.d \
./GateServer/FrameWork/DataBuffer.d \
./GateServer/FrameWork/GameClient.d \
./GateServer/FrameWork/GateApplication.d \
./GateServer/FrameWork/GateServer.d \
./GateServer/FrameWork/GateService.d \
./GateServer/FrameWork/PlayerClient.d \
./GateServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
GateServer/FrameWork/%.o: ../GateServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


