################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/Message/DBMessage/DBMessage.cpp \
../GameServer/Logic/Message/DBMessage/DBMessage_PrizePool.cpp \
../GameServer/Logic/Message/DBMessage/DBMessage_Role.cpp \
../GameServer/Logic/Message/DBMessage/DBMessage_TexasBoard.cpp \
../GameServer/Logic/Message/DBMessage/DBMessage_TexasHistoryBoard.cpp 

OBJS += \
./GameServer/Logic/Message/DBMessage/DBMessage.o \
./GameServer/Logic/Message/DBMessage/DBMessage_PrizePool.o \
./GameServer/Logic/Message/DBMessage/DBMessage_Role.o \
./GameServer/Logic/Message/DBMessage/DBMessage_TexasBoard.o \
./GameServer/Logic/Message/DBMessage/DBMessage_TexasHistoryBoard.o 

CPP_DEPS += \
./GameServer/Logic/Message/DBMessage/DBMessage.d \
./GameServer/Logic/Message/DBMessage/DBMessage_PrizePool.d \
./GameServer/Logic/Message/DBMessage/DBMessage_Role.d \
./GameServer/Logic/Message/DBMessage/DBMessage_TexasBoard.d \
./GameServer/Logic/Message/DBMessage/DBMessage_TexasHistoryBoard.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/Message/DBMessage/%.o: ../GameServer/Logic/Message/DBMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


