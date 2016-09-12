################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GateServer/Logic/DBCache/DBGirlHandler.cpp \
../GateServer/Logic/DBCache/DBManager.cpp 

OBJS += \
./GateServer/Logic/DBCache/DBGirlHandler.o \
./GateServer/Logic/DBCache/DBManager.o 

CPP_DEPS += \
./GateServer/Logic/DBCache/DBGirlHandler.d \
./GateServer/Logic/DBCache/DBManager.d 


# Each subdirectory must supply rules for building sources it contributes
GateServer/Logic/DBCache/%.o: ../GateServer/Logic/DBCache/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


