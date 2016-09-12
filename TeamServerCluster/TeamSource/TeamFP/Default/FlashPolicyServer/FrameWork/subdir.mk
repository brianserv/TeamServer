################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FlashPolicyServer/FrameWork/BaseDefine.cpp \
../FlashPolicyServer/FrameWork/ConfigFile.cpp \
../FlashPolicyServer/FrameWork/DataBuffer.cpp \
../FlashPolicyServer/FrameWork/FlashPolicyApplication.cpp \
../FlashPolicyServer/FrameWork/FlashPolicyServer.cpp \
../FlashPolicyServer/FrameWork/FlashPolicyService.cpp \
../FlashPolicyServer/FrameWork/FlashWebClient.cpp \
../FlashPolicyServer/FrameWork/main.cpp 

OBJS += \
./FlashPolicyServer/FrameWork/BaseDefine.o \
./FlashPolicyServer/FrameWork/ConfigFile.o \
./FlashPolicyServer/FrameWork/DataBuffer.o \
./FlashPolicyServer/FrameWork/FlashPolicyApplication.o \
./FlashPolicyServer/FrameWork/FlashPolicyServer.o \
./FlashPolicyServer/FrameWork/FlashPolicyService.o \
./FlashPolicyServer/FrameWork/FlashWebClient.o \
./FlashPolicyServer/FrameWork/main.o 

CPP_DEPS += \
./FlashPolicyServer/FrameWork/BaseDefine.d \
./FlashPolicyServer/FrameWork/ConfigFile.d \
./FlashPolicyServer/FrameWork/DataBuffer.d \
./FlashPolicyServer/FrameWork/FlashPolicyApplication.d \
./FlashPolicyServer/FrameWork/FlashPolicyServer.d \
./FlashPolicyServer/FrameWork/FlashPolicyService.d \
./FlashPolicyServer/FrameWork/FlashWebClient.d \
./FlashPolicyServer/FrameWork/main.d 


# Each subdirectory must supply rules for building sources it contributes
FlashPolicyServer/FrameWork/%.o: ../FlashPolicyServer/FrameWork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


