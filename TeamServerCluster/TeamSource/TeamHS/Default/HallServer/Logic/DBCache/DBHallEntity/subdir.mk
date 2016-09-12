################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HallServer/Logic/DBCache/DBHallEntity/DBHallEntity.cpp \
../HallServer/Logic/DBCache/DBHallEntity/DBHallEntityManager.cpp 

OBJS += \
./HallServer/Logic/DBCache/DBHallEntity/DBHallEntity.o \
./HallServer/Logic/DBCache/DBHallEntity/DBHallEntityManager.o 

CPP_DEPS += \
./HallServer/Logic/DBCache/DBHallEntity/DBHallEntity.d \
./HallServer/Logic/DBCache/DBHallEntity/DBHallEntityManager.d 


# Each subdirectory must supply rules for building sources it contributes
HallServer/Logic/DBCache/DBHallEntity/%.o: ../HallServer/Logic/DBCache/DBHallEntity/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


