################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WebSocketServer/Logic/WebFrameFilter/WebFrameFilter.cpp 

OBJS += \
./WebSocketServer/Logic/WebFrameFilter/WebFrameFilter.o 

CPP_DEPS += \
./WebSocketServer/Logic/WebFrameFilter/WebFrameFilter.d 


# Each subdirectory must supply rules for building sources it contributes
WebSocketServer/Logic/WebFrameFilter/%.o: ../WebSocketServer/Logic/WebFrameFilter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


