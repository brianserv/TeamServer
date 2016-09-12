################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BackendServer/Logic/Message/BGCMessage/BGCMessage.cpp 

OBJS += \
./BackendServer/Logic/Message/BGCMessage/BGCMessage.o 

CPP_DEPS += \
./BackendServer/Logic/Message/BGCMessage/BGCMessage.d 


# Each subdirectory must supply rules for building sources it contributes
BackendServer/Logic/Message/BGCMessage/%.o: ../BackendServer/Logic/Message/BGCMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


