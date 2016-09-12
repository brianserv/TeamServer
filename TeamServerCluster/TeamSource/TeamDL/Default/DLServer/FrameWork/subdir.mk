################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DLServer/FrameWork/BaseDefine.cpp \
../DLServer/FrameWork/ConfigFile.cpp \
../DLServer/FrameWork/DLApplication.cpp \
../DLServer/FrameWork/DLServer.cpp \
../DLServer/FrameWork/DLService.cpp \
../DLServer/FrameWork/DataBuffer.cpp \
../DLServer/FrameWork/PlayerClient.cpp \
../DLServer/FrameWork/main.cpp 

OBJS += \
./DLServer/FrameWork/BaseDefine.o \
./DLServer/FrameWork/ConfigFile.o \
./DLServer/FrameWork/DLApplication.o \
./DLServer/FrameWork/DLServer.o \
./DLServer/FrameWork/DLService.o \
./DLServer/FrameWork/DataBuffer.o \
./DLServer/FrameWork/PlayerClient.o \
./DLServer/FrameWork/main.o 

CPP_DEPS += \
./DLServer/FrameWork/BaseDefine.d \
./DLServer/FrameWork/ConfigFile.d \
./DLServer/FrameWork/DLApplication.d \
./DLServer/FrameWork/DLServer.d \
./DLServer/FrameWork/DLService.d \
./DLServer/FrameWork/DataBuffer.d \
./DLServer/FrameWork/PlayerClient.d \
./DLServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
DLServer/FrameWork/%.o: ../DLServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


