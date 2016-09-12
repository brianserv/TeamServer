################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DBServer/Logic/Resource/DBPrizePoolData.cpp \
../DBServer/Logic/Resource/DBResourceManager.cpp \
../DBServer/Logic/Resource/DBRoleData.cpp \
../DBServer/Logic/Resource/DBTexasBoardData.cpp \
../DBServer/Logic/Resource/DBTexasHistoryBoard10Data.cpp 

OBJS += \
./DBServer/Logic/Resource/DBPrizePoolData.o \
./DBServer/Logic/Resource/DBResourceManager.o \
./DBServer/Logic/Resource/DBRoleData.o \
./DBServer/Logic/Resource/DBTexasBoardData.o \
./DBServer/Logic/Resource/DBTexasHistoryBoard10Data.o 

CPP_DEPS += \
./DBServer/Logic/Resource/DBPrizePoolData.d \
./DBServer/Logic/Resource/DBResourceManager.d \
./DBServer/Logic/Resource/DBRoleData.d \
./DBServer/Logic/Resource/DBTexasBoardData.d \
./DBServer/Logic/Resource/DBTexasHistoryBoard10Data.d 


# Each subdirectory must supply rules for building sources it contributes
DBServer/Logic/Resource/%.o: ../DBServer/Logic/Resource/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


