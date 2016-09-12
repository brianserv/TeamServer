################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/FrameWork/BaseDefine.cpp \
../GameServer/FrameWork/CenterClient.cpp \
../GameServer/FrameWork/ConfigFile.cpp \
../GameServer/FrameWork/DBClient.cpp \
../GameServer/FrameWork/DBLogClient.cpp \
../GameServer/FrameWork/DataBuffer.cpp \
../GameServer/FrameWork/GameApplication.cpp \
../GameServer/FrameWork/GameServer.cpp \
../GameServer/FrameWork/GameService.cpp \
../GameServer/FrameWork/HttpLinkApplication.cpp \
../GameServer/FrameWork/PlayerClient.cpp \
../GameServer/FrameWork/main.cpp 

OBJS += \
./GameServer/FrameWork/BaseDefine.o \
./GameServer/FrameWork/CenterClient.o \
./GameServer/FrameWork/ConfigFile.o \
./GameServer/FrameWork/DBClient.o \
./GameServer/FrameWork/DBLogClient.o \
./GameServer/FrameWork/DataBuffer.o \
./GameServer/FrameWork/GameApplication.o \
./GameServer/FrameWork/GameServer.o \
./GameServer/FrameWork/GameService.o \
./GameServer/FrameWork/HttpLinkApplication.o \
./GameServer/FrameWork/PlayerClient.o \
./GameServer/FrameWork/main.o 

CPP_DEPS += \
./GameServer/FrameWork/BaseDefine.d \
./GameServer/FrameWork/CenterClient.d \
./GameServer/FrameWork/ConfigFile.d \
./GameServer/FrameWork/DBClient.d \
./GameServer/FrameWork/DBLogClient.d \
./GameServer/FrameWork/DataBuffer.d \
./GameServer/FrameWork/GameApplication.d \
./GameServer/FrameWork/GameServer.d \
./GameServer/FrameWork/GameService.d \
./GameServer/FrameWork/HttpLinkApplication.d \
./GameServer/FrameWork/PlayerClient.d \
./GameServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/FrameWork/%.o: ../GameServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


