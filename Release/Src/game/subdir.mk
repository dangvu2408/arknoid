################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/game/collision.c \
../Src/game/levels.c \
../Src/game/menu_ui.c \
../Src/game/run_game.c 

OBJS += \
./Src/game/collision.o \
./Src/game/levels.o \
./Src/game/menu_ui.o \
./Src/game/run_game.o 

C_DEPS += \
./Src/game/collision.d \
./Src/game/levels.d \
./Src/game/menu_ui.d \
./Src/game/run_game.d 


# Each subdirectory must supply rules for building sources it contributes
Src/game/%.o Src/game/%.su Src/game/%.cyclo: ../Src/game/%.c Src/game/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-game

clean-Src-2f-game:
	-$(RM) ./Src/game/collision.cyclo ./Src/game/collision.d ./Src/game/collision.o ./Src/game/collision.su ./Src/game/levels.cyclo ./Src/game/levels.d ./Src/game/levels.o ./Src/game/levels.su ./Src/game/menu_ui.cyclo ./Src/game/menu_ui.d ./Src/game/menu_ui.o ./Src/game/menu_ui.su ./Src/game/run_game.cyclo ./Src/game/run_game.d ./Src/game/run_game.o ./Src/game/run_game.su

.PHONY: clean-Src-2f-game

