################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/Resource/JsonTable/TableLimit/TableLimit.cpp 

OBJS += \
./GameServer/Logic/Resource/JsonTable/TableLimit/TableLimit.o 

CPP_DEPS += \
./GameServer/Logic/Resource/JsonTable/TableLimit/TableLimit.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/Resource/JsonTable/TableLimit/%.o: ../GameServer/Logic/Resource/JsonTable/TableLimit/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


