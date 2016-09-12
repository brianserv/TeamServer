################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/Httplink/HttpLinkEvent.cpp \
../GameServer/Logic/Httplink/HttpLinkFB.cpp \
../GameServer/Logic/Httplink/HttpLinkManager.cpp \
../GameServer/Logic/Httplink/HttpLinkYY.cpp 

OBJS += \
./GameServer/Logic/Httplink/HttpLinkEvent.o \
./GameServer/Logic/Httplink/HttpLinkFB.o \
./GameServer/Logic/Httplink/HttpLinkManager.o \
./GameServer/Logic/Httplink/HttpLinkYY.o 

CPP_DEPS += \
./GameServer/Logic/Httplink/HttpLinkEvent.d \
./GameServer/Logic/Httplink/HttpLinkFB.d \
./GameServer/Logic/Httplink/HttpLinkManager.d \
./GameServer/Logic/Httplink/HttpLinkYY.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/Httplink/%.o: ../GameServer/Logic/Httplink/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


