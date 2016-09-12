################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CenterServer/FrameWork/BaseDefine.cpp \
../CenterServer/FrameWork/CenterApplication.cpp \
../CenterServer/FrameWork/CenterServer.cpp \
../CenterServer/FrameWork/CenterService.cpp \
../CenterServer/FrameWork/ConfigFile.cpp \
../CenterServer/FrameWork/DataBuffer.cpp \
../CenterServer/FrameWork/PlayerClient.cpp \
../CenterServer/FrameWork/main.cpp 

OBJS += \
./CenterServer/FrameWork/BaseDefine.o \
./CenterServer/FrameWork/CenterApplication.o \
./CenterServer/FrameWork/CenterServer.o \
./CenterServer/FrameWork/CenterService.o \
./CenterServer/FrameWork/ConfigFile.o \
./CenterServer/FrameWork/DataBuffer.o \
./CenterServer/FrameWork/PlayerClient.o \
./CenterServer/FrameWork/main.o 

CPP_DEPS += \
./CenterServer/FrameWork/BaseDefine.d \
./CenterServer/FrameWork/CenterApplication.d \
./CenterServer/FrameWork/CenterServer.d \
./CenterServer/FrameWork/CenterService.d \
./CenterServer/FrameWork/ConfigFile.d \
./CenterServer/FrameWork/DataBuffer.d \
./CenterServer/FrameWork/PlayerClient.d \
./CenterServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
CenterServer/FrameWork/%.o: ../CenterServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


