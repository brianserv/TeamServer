################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CenterServer/Logic/GameHall/Texas/TexasGameRoom/TexasGameRoom.cpp 

OBJS += \
./CenterServer/Logic/GameHall/Texas/TexasGameRoom/TexasGameRoom.o 

CPP_DEPS += \
./CenterServer/Logic/GameHall/Texas/TexasGameRoom/TexasGameRoom.d 


# Each subdirectory must supply rules for building sources it contributes
CenterServer/Logic/GameHall/Texas/TexasGameRoom/%.o: ../CenterServer/Logic/GameHall/Texas/TexasGameRoom/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -O0 -g3 -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


