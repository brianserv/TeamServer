################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/Message/GSMessage/GSMessage.cpp \
../GameServer/Logic/Message/GSMessage/GSMessage_GameScene.cpp \
../GameServer/Logic/Message/GSMessage/GSMessage_GirlLogin.cpp \
../GameServer/Logic/Message/GSMessage/GSMessage_HallRoom.cpp 

OBJS += \
./GameServer/Logic/Message/GSMessage/GSMessage.o \
./GameServer/Logic/Message/GSMessage/GSMessage_GameScene.o \
./GameServer/Logic/Message/GSMessage/GSMessage_GirlLogin.o \
./GameServer/Logic/Message/GSMessage/GSMessage_HallRoom.o 

CPP_DEPS += \
./GameServer/Logic/Message/GSMessage/GSMessage.d \
./GameServer/Logic/Message/GSMessage/GSMessage_GameScene.d \
./GameServer/Logic/Message/GSMessage/GSMessage_GirlLogin.d \
./GameServer/Logic/Message/GSMessage/GSMessage_HallRoom.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/Message/GSMessage/%.o: ../GameServer/Logic/Message/GSMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


