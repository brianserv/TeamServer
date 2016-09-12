################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/Message/CSMessage/CSMessage.cpp \
../GameServer/Logic/Message/CSMessage/CSMessage_Broadcast.cpp \
../GameServer/Logic/Message/CSMessage/CSMessage_GameRole.cpp \
../GameServer/Logic/Message/CSMessage/CSMessage_GameScene.cpp \
../GameServer/Logic/Message/CSMessage/CSMessage_HallRoom.cpp \
../GameServer/Logic/Message/CSMessage/CSMessage_UserLogin.cpp 

OBJS += \
./GameServer/Logic/Message/CSMessage/CSMessage.o \
./GameServer/Logic/Message/CSMessage/CSMessage_Broadcast.o \
./GameServer/Logic/Message/CSMessage/CSMessage_GameRole.o \
./GameServer/Logic/Message/CSMessage/CSMessage_GameScene.o \
./GameServer/Logic/Message/CSMessage/CSMessage_HallRoom.o \
./GameServer/Logic/Message/CSMessage/CSMessage_UserLogin.o 

CPP_DEPS += \
./GameServer/Logic/Message/CSMessage/CSMessage.d \
./GameServer/Logic/Message/CSMessage/CSMessage_Broadcast.d \
./GameServer/Logic/Message/CSMessage/CSMessage_GameRole.d \
./GameServer/Logic/Message/CSMessage/CSMessage_GameScene.d \
./GameServer/Logic/Message/CSMessage/CSMessage_HallRoom.d \
./GameServer/Logic/Message/CSMessage/CSMessage_UserLogin.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/Message/CSMessage/%.o: ../GameServer/Logic/Message/CSMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


