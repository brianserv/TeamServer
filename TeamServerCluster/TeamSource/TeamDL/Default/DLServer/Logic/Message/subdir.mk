################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DLServer/Logic/Message/DLMessage.cpp \
../DLServer/Logic/Message/DLMessage_Bet.cpp \
../DLServer/Logic/Message/DLMessage_GM.cpp \
../DLServer/Logic/Message/DLMessage_Login.cpp \
../DLServer/Logic/Message/DLMessage_Logout.cpp \
../DLServer/Logic/Message/DLMessage_Online.cpp \
../DLServer/Logic/Message/DLMessage_Ping.cpp \
../DLServer/Logic/Message/DLMessage_PvgGift.cpp \
../DLServer/Logic/Message/DLMessage_PvpGift.cpp \
../DLServer/Logic/Message/DLMessage_Room.cpp \
../DLServer/Logic/Message/DLMessage_Trace.cpp 

OBJS += \
./DLServer/Logic/Message/DLMessage.o \
./DLServer/Logic/Message/DLMessage_Bet.o \
./DLServer/Logic/Message/DLMessage_GM.o \
./DLServer/Logic/Message/DLMessage_Login.o \
./DLServer/Logic/Message/DLMessage_Logout.o \
./DLServer/Logic/Message/DLMessage_Online.o \
./DLServer/Logic/Message/DLMessage_Ping.o \
./DLServer/Logic/Message/DLMessage_PvgGift.o \
./DLServer/Logic/Message/DLMessage_PvpGift.o \
./DLServer/Logic/Message/DLMessage_Room.o \
./DLServer/Logic/Message/DLMessage_Trace.o 

CPP_DEPS += \
./DLServer/Logic/Message/DLMessage.d \
./DLServer/Logic/Message/DLMessage_Bet.d \
./DLServer/Logic/Message/DLMessage_GM.d \
./DLServer/Logic/Message/DLMessage_Login.d \
./DLServer/Logic/Message/DLMessage_Logout.d \
./DLServer/Logic/Message/DLMessage_Online.d \
./DLServer/Logic/Message/DLMessage_Ping.d \
./DLServer/Logic/Message/DLMessage_PvgGift.d \
./DLServer/Logic/Message/DLMessage_PvpGift.d \
./DLServer/Logic/Message/DLMessage_Room.d \
./DLServer/Logic/Message/DLMessage_Trace.d 


# Each subdirectory must supply rules for building sources it contributes
DLServer/Logic/Message/%.o: ../DLServer/Logic/Message/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


