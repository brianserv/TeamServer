################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GateServer/Logic/Girl/Girl.cpp \
../GateServer/Logic/Girl/GirlManager.cpp 

OBJS += \
./GateServer/Logic/Girl/Girl.o \
./GateServer/Logic/Girl/GirlManager.o 

CPP_DEPS += \
./GateServer/Logic/Girl/Girl.d \
./GateServer/Logic/Girl/GirlManager.d 


# Each subdirectory must supply rules for building sources it contributes
GateServer/Logic/Girl/%.o: ../GateServer/Logic/Girl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


