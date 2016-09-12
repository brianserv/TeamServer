################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DLServer/Logic/Table/DLBet.cpp \
../DLServer/Logic/Table/DLGm.cpp \
../DLServer/Logic/Table/DLLogin.cpp \
../DLServer/Logic/Table/DLLogout.cpp \
../DLServer/Logic/Table/DLOnline.cpp \
../DLServer/Logic/Table/DLPvgGift.cpp \
../DLServer/Logic/Table/DLPvpGift.cpp \
../DLServer/Logic/Table/DLRoom.cpp \
../DLServer/Logic/Table/DLTrace.cpp 

OBJS += \
./DLServer/Logic/Table/DLBet.o \
./DLServer/Logic/Table/DLGm.o \
./DLServer/Logic/Table/DLLogin.o \
./DLServer/Logic/Table/DLLogout.o \
./DLServer/Logic/Table/DLOnline.o \
./DLServer/Logic/Table/DLPvgGift.o \
./DLServer/Logic/Table/DLPvpGift.o \
./DLServer/Logic/Table/DLRoom.o \
./DLServer/Logic/Table/DLTrace.o 

CPP_DEPS += \
./DLServer/Logic/Table/DLBet.d \
./DLServer/Logic/Table/DLGm.d \
./DLServer/Logic/Table/DLLogin.d \
./DLServer/Logic/Table/DLLogout.d \
./DLServer/Logic/Table/DLOnline.d \
./DLServer/Logic/Table/DLPvgGift.d \
./DLServer/Logic/Table/DLPvpGift.d \
./DLServer/Logic/Table/DLRoom.d \
./DLServer/Logic/Table/DLTrace.d 


# Each subdirectory must supply rules for building sources it contributes
DLServer/Logic/Table/%.o: ../DLServer/Logic/Table/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


