################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DBServer/Logic/Message/DBMessage.cpp \
../DBServer/Logic/Message/DBMessage_Ping.cpp \
../DBServer/Logic/Message/DBMessage_PrizePool.cpp \
../DBServer/Logic/Message/DBMessage_Role.cpp \
../DBServer/Logic/Message/DBMessage_TexasBoard.cpp \
../DBServer/Logic/Message/DBMessage_TexasHistoryBoard10.cpp 

OBJS += \
./DBServer/Logic/Message/DBMessage.o \
./DBServer/Logic/Message/DBMessage_Ping.o \
./DBServer/Logic/Message/DBMessage_PrizePool.o \
./DBServer/Logic/Message/DBMessage_Role.o \
./DBServer/Logic/Message/DBMessage_TexasBoard.o \
./DBServer/Logic/Message/DBMessage_TexasHistoryBoard10.o 

CPP_DEPS += \
./DBServer/Logic/Message/DBMessage.d \
./DBServer/Logic/Message/DBMessage_Ping.d \
./DBServer/Logic/Message/DBMessage_PrizePool.d \
./DBServer/Logic/Message/DBMessage_Role.d \
./DBServer/Logic/Message/DBMessage_TexasBoard.d \
./DBServer/Logic/Message/DBMessage_TexasHistoryBoard10.d 


# Each subdirectory must supply rules for building sources it contributes
DBServer/Logic/Message/%.o: ../DBServer/Logic/Message/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


