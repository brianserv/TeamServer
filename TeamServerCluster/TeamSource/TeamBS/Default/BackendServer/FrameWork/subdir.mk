################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BackendServer/FrameWork/BackendApplication.cpp \
../BackendServer/FrameWork/BackendServer.cpp \
../BackendServer/FrameWork/BackendService.cpp \
../BackendServer/FrameWork/BaseDefine.cpp \
../BackendServer/FrameWork/CenterClient.cpp \
../BackendServer/FrameWork/ConfigFile.cpp \
../BackendServer/FrameWork/DataBuffer.cpp \
../BackendServer/FrameWork/PlayerClient.cpp \
../BackendServer/FrameWork/main.cpp 

OBJS += \
./BackendServer/FrameWork/BackendApplication.o \
./BackendServer/FrameWork/BackendServer.o \
./BackendServer/FrameWork/BackendService.o \
./BackendServer/FrameWork/BaseDefine.o \
./BackendServer/FrameWork/CenterClient.o \
./BackendServer/FrameWork/ConfigFile.o \
./BackendServer/FrameWork/DataBuffer.o \
./BackendServer/FrameWork/PlayerClient.o \
./BackendServer/FrameWork/main.o 

CPP_DEPS += \
./BackendServer/FrameWork/BackendApplication.d \
./BackendServer/FrameWork/BackendServer.d \
./BackendServer/FrameWork/BackendService.d \
./BackendServer/FrameWork/BaseDefine.d \
./BackendServer/FrameWork/CenterClient.d \
./BackendServer/FrameWork/ConfigFile.d \
./BackendServer/FrameWork/DataBuffer.d \
./BackendServer/FrameWork/PlayerClient.d \
./BackendServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
BackendServer/FrameWork/%.o: ../BackendServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O2 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


