################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/Message/DLMessage/DLMessage.cpp \
../GameServer/Logic/Message/DLMessage/DLMessage_TexasGameBet.cpp \
../GameServer/Logic/Message/DLMessage/DLMessage_UserLogin.cpp \
../GameServer/Logic/Message/DLMessage/DLMessage_UserLogout.cpp 

OBJS += \
./GameServer/Logic/Message/DLMessage/DLMessage.o \
./GameServer/Logic/Message/DLMessage/DLMessage_TexasGameBet.o \
./GameServer/Logic/Message/DLMessage/DLMessage_UserLogin.o \
./GameServer/Logic/Message/DLMessage/DLMessage_UserLogout.o 

CPP_DEPS += \
./GameServer/Logic/Message/DLMessage/DLMessage.d \
./GameServer/Logic/Message/DLMessage/DLMessage_TexasGameBet.d \
./GameServer/Logic/Message/DLMessage/DLMessage_UserLogin.d \
./GameServer/Logic/Message/DLMessage/DLMessage_UserLogout.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/Message/DLMessage/%.o: ../GameServer/Logic/Message/DLMessage/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


