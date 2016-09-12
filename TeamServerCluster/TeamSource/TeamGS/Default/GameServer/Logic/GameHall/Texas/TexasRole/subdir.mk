################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/GameHall/Texas/TexasRole/TexasRole.cpp \
../GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleEntity.cpp \
../GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleMsgRes.cpp \
../GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleMsgSync.cpp 

OBJS += \
./GameServer/Logic/GameHall/Texas/TexasRole/TexasRole.o \
./GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleEntity.o \
./GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleMsgRes.o \
./GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleMsgSync.o 

CPP_DEPS += \
./GameServer/Logic/GameHall/Texas/TexasRole/TexasRole.d \
./GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleEntity.d \
./GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleMsgRes.d \
./GameServer/Logic/GameHall/Texas/TexasRole/TexasRoleMsgSync.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/GameHall/Texas/TexasRole/%.o: ../GameServer/Logic/GameHall/Texas/TexasRole/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


