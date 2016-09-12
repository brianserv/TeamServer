################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DBServer/Logic/DBCache/DBManager.cpp \
../DBServer/Logic/DBCache/DBPrizePoolHandler.cpp \
../DBServer/Logic/DBCache/DBRoleHandler.cpp \
../DBServer/Logic/DBCache/DBTexasBoardHandler.cpp \
../DBServer/Logic/DBCache/DBTexasHistoryBoard10Handler.cpp 

OBJS += \
./DBServer/Logic/DBCache/DBManager.o \
./DBServer/Logic/DBCache/DBPrizePoolHandler.o \
./DBServer/Logic/DBCache/DBRoleHandler.o \
./DBServer/Logic/DBCache/DBTexasBoardHandler.o \
./DBServer/Logic/DBCache/DBTexasHistoryBoard10Handler.o 

CPP_DEPS += \
./DBServer/Logic/DBCache/DBManager.d \
./DBServer/Logic/DBCache/DBPrizePoolHandler.d \
./DBServer/Logic/DBCache/DBRoleHandler.d \
./DBServer/Logic/DBCache/DBTexasBoardHandler.d \
./DBServer/Logic/DBCache/DBTexasHistoryBoard10Handler.d 


# Each subdirectory must supply rules for building sources it contributes
DBServer/Logic/DBCache/%.o: ../DBServer/Logic/DBCache/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


