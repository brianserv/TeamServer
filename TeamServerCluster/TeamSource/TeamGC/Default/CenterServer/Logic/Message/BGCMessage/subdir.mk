################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CenterServer/Logic/Message/BGCMessage/BGCMessage.cpp 

OBJS += \
./CenterServer/Logic/Message/BGCMessage/BGCMessage.o 

CPP_DEPS += \
./CenterServer/Logic/Message/BGCMessage/BGCMessage.d 


# Each subdirectory must supply rules for building sources it contributes
CenterServer/Logic/Message/BGCMessage/%.o: ../CenterServer/Logic/Message/BGCMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


