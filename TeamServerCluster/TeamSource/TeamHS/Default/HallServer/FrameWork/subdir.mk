################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HallServer/FrameWork/BaseDefine.cpp \
../HallServer/FrameWork/ConfigFile.cpp \
../HallServer/FrameWork/DataBuffer.cpp \
../HallServer/FrameWork/GameClient.cpp \
../HallServer/FrameWork/HallApplication.cpp \
../HallServer/FrameWork/HallServer.cpp \
../HallServer/FrameWork/HallService.cpp \
../HallServer/FrameWork/PlayerClient.cpp \
../HallServer/FrameWork/main.cpp 

OBJS += \
./HallServer/FrameWork/BaseDefine.o \
./HallServer/FrameWork/ConfigFile.o \
./HallServer/FrameWork/DataBuffer.o \
./HallServer/FrameWork/GameClient.o \
./HallServer/FrameWork/HallApplication.o \
./HallServer/FrameWork/HallServer.o \
./HallServer/FrameWork/HallService.o \
./HallServer/FrameWork/PlayerClient.o \
./HallServer/FrameWork/main.o 

CPP_DEPS += \
./HallServer/FrameWork/BaseDefine.d \
./HallServer/FrameWork/ConfigFile.d \
./HallServer/FrameWork/DataBuffer.d \
./HallServer/FrameWork/GameClient.d \
./HallServer/FrameWork/HallApplication.d \
./HallServer/FrameWork/HallServer.d \
./HallServer/FrameWork/HallService.d \
./HallServer/FrameWork/PlayerClient.d \
./HallServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
HallServer/FrameWork/%.o: ../HallServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


