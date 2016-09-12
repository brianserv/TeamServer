################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DBServer/Logic/Table/DBPrizePool.cpp \
../DBServer/Logic/Table/DBRole.cpp \
../DBServer/Logic/Table/DBTexasBoard.cpp \
../DBServer/Logic/Table/DBTexasHistoryBoard10.cpp 

OBJS += \
./DBServer/Logic/Table/DBPrizePool.o \
./DBServer/Logic/Table/DBRole.o \
./DBServer/Logic/Table/DBTexasBoard.o \
./DBServer/Logic/Table/DBTexasHistoryBoard10.o 

CPP_DEPS += \
./DBServer/Logic/Table/DBPrizePool.d \
./DBServer/Logic/Table/DBRole.d \
./DBServer/Logic/Table/DBTexasBoard.d \
./DBServer/Logic/Table/DBTexasHistoryBoard10.d 


# Each subdirectory must supply rules for building sources it contributes
DBServer/Logic/Table/%.o: ../DBServer/Logic/Table/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


