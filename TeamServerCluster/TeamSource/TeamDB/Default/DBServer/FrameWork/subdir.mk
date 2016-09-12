################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DBServer/FrameWork/BaseDefine.cpp \
../DBServer/FrameWork/ConfigFile.cpp \
../DBServer/FrameWork/DBApplication.cpp \
../DBServer/FrameWork/DBServer.cpp \
../DBServer/FrameWork/DBService.cpp \
../DBServer/FrameWork/DataBuffer.cpp \
../DBServer/FrameWork/PlayerClient.cpp \
../DBServer/FrameWork/main.cpp 

OBJS += \
./DBServer/FrameWork/BaseDefine.o \
./DBServer/FrameWork/ConfigFile.o \
./DBServer/FrameWork/DBApplication.o \
./DBServer/FrameWork/DBServer.o \
./DBServer/FrameWork/DBService.o \
./DBServer/FrameWork/DataBuffer.o \
./DBServer/FrameWork/PlayerClient.o \
./DBServer/FrameWork/main.o 

CPP_DEPS += \
./DBServer/FrameWork/BaseDefine.d \
./DBServer/FrameWork/ConfigFile.d \
./DBServer/FrameWork/DBApplication.d \
./DBServer/FrameWork/DBServer.d \
./DBServer/FrameWork/DBService.d \
./DBServer/FrameWork/DataBuffer.d \
./DBServer/FrameWork/PlayerClient.d \
./DBServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
DBServer/FrameWork/%.o: ../DBServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


