################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DLServer/Logic/DBCache/DLBetHandler.cpp \
../DLServer/Logic/DBCache/DLGmHandler.cpp \
../DLServer/Logic/DBCache/DLLoginHandler.cpp \
../DLServer/Logic/DBCache/DLLogoutHandler.cpp \
../DLServer/Logic/DBCache/DLManager.cpp \
../DLServer/Logic/DBCache/DLOnlineHandler.cpp \
../DLServer/Logic/DBCache/DLPvgGiftHandler.cpp \
../DLServer/Logic/DBCache/DLPvpGiftHandler.cpp \
../DLServer/Logic/DBCache/DLRoomHandler.cpp \
../DLServer/Logic/DBCache/DLTraceHandler.cpp 

OBJS += \
./DLServer/Logic/DBCache/DLBetHandler.o \
./DLServer/Logic/DBCache/DLGmHandler.o \
./DLServer/Logic/DBCache/DLLoginHandler.o \
./DLServer/Logic/DBCache/DLLogoutHandler.o \
./DLServer/Logic/DBCache/DLManager.o \
./DLServer/Logic/DBCache/DLOnlineHandler.o \
./DLServer/Logic/DBCache/DLPvgGiftHandler.o \
./DLServer/Logic/DBCache/DLPvpGiftHandler.o \
./DLServer/Logic/DBCache/DLRoomHandler.o \
./DLServer/Logic/DBCache/DLTraceHandler.o 

CPP_DEPS += \
./DLServer/Logic/DBCache/DLBetHandler.d \
./DLServer/Logic/DBCache/DLGmHandler.d \
./DLServer/Logic/DBCache/DLLoginHandler.d \
./DLServer/Logic/DBCache/DLLogoutHandler.d \
./DLServer/Logic/DBCache/DLManager.d \
./DLServer/Logic/DBCache/DLOnlineHandler.d \
./DLServer/Logic/DBCache/DLPvgGiftHandler.d \
./DLServer/Logic/DBCache/DLPvpGiftHandler.d \
./DLServer/Logic/DBCache/DLRoomHandler.d \
./DLServer/Logic/DBCache/DLTraceHandler.d 


# Each subdirectory must supply rules for building sources it contributes
DLServer/Logic/DBCache/%.o: ../DLServer/Logic/DBCache/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


