################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGame.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGameEntity.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGameManager.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerReq.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerRes.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerSync.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgReq.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgRes.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgSync.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGame_DBScene.cpp \
../GameServer/Logic/GameHall/Texas/TexasGame/TexasGame_DLScene.cpp 

OBJS += \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGame.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameEntity.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameManager.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerReq.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerRes.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerSync.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgReq.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgRes.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgSync.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGame_DBScene.o \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGame_DLScene.o 

CPP_DEPS += \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGame.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameEntity.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameManager.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerReq.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerRes.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgDealerSync.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgReq.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgRes.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGameMsgSync.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGame_DBScene.d \
./GameServer/Logic/GameHall/Texas/TexasGame/TexasGame_DLScene.d 


# Each subdirectory must supply rules for building sources it contributes
GameServer/Logic/GameHall/Texas/TexasGame/%.o: ../GameServer/Logic/GameHall/Texas/TexasGame/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/BaseInterface -I/mnt/hgfs/E/TeamServerCluster/Protocols -I/mnt/hgfs/E/TeamServerCluster/TeamSDK/Lib/third_lib/mysql/linux/include -O0 -g -Wall -c -fmessage-length=0 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


