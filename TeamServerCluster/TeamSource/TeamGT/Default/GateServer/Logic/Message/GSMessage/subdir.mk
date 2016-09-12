################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GateServer/Logic/Message/GSMessage/GSMessage.cpp \
../GateServer/Logic/Message/GSMessage/GSMessage_GirlLogin.cpp \
../GateServer/Logic/Message/GSMessage/GSMessage_HeartBeat.cpp \
../GateServer/Logic/Message/GSMessage/GSMessage_TexasGame.cpp 

OBJS += \
./GateServer/Logic/Message/GSMessage/GSMessage.o \
./GateServer/Logic/Message/GSMessage/GSMessage_GirlLogin.o \
./GateServer/Logic/Message/GSMessage/GSMessage_HeartBeat.o \
./GateServer/Logic/Message/GSMessage/GSMessage_TexasGame.o 

CPP_DEPS += \
./GateServer/Logic/Message/GSMessage/GSMessage.d \
./GateServer/Logic/Message/GSMessage/GSMessage_GirlLogin.d \
./GateServer/Logic/Message/GSMessage/GSMessage_HeartBeat.d \
./GateServer/Logic/Message/GSMessage/GSMessage_TexasGame.d 


# Each subdirectory must supply rules for building sources it contributes
GateServer/Logic/Message/GSMessage/%.o: ../GateServer/Logic/Message/GSMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


