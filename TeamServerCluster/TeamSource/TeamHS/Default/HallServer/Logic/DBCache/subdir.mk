################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HallServer/Logic/DBCache/DBHallHandler.cpp \
../HallServer/Logic/DBCache/DBManager.cpp 

OBJS += \
./HallServer/Logic/DBCache/DBHallHandler.o \
./HallServer/Logic/DBCache/DBManager.o 

CPP_DEPS += \
./HallServer/Logic/DBCache/DBHallHandler.d \
./HallServer/Logic/DBCache/DBManager.d 


# Each subdirectory must supply rules for building sources it contributes
HallServer/Logic/DBCache/%.o: ../HallServer/Logic/DBCache/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


