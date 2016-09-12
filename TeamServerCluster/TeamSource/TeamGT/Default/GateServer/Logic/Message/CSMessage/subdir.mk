################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GateServer/Logic/Message/CSMessage/CSMessage.cpp \
../GateServer/Logic/Message/CSMessage/CSMessage_HeartBeat.cpp \
../GateServer/Logic/Message/CSMessage/CSMessage_UserLogin.cpp 

OBJS += \
./GateServer/Logic/Message/CSMessage/CSMessage.o \
./GateServer/Logic/Message/CSMessage/CSMessage_HeartBeat.o \
./GateServer/Logic/Message/CSMessage/CSMessage_UserLogin.o 

CPP_DEPS += \
./GateServer/Logic/Message/CSMessage/CSMessage.d \
./GateServer/Logic/Message/CSMessage/CSMessage_HeartBeat.d \
./GateServer/Logic/Message/CSMessage/CSMessage_UserLogin.d 


# Each subdirectory must supply rules for building sources it contributes
GateServer/Logic/Message/CSMessage/%.o: ../GateServer/Logic/Message/CSMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


