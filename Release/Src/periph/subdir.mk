################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/periph/button.c \
../Src/periph/buzzer.c \
../Src/periph/led.c 

OBJS += \
./Src/periph/button.o \
./Src/periph/buzzer.o \
./Src/periph/led.o 

C_DEPS += \
./Src/periph/button.d \
./Src/periph/buzzer.d \
./Src/periph/led.d 


# Each subdirectory must supply rules for building sources it contributes
Src/periph/%.o Src/periph/%.su Src/periph/%.cyclo: ../Src/periph/%.c Src/periph/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-periph

clean-Src-2f-periph:
	-$(RM) ./Src/periph/button.cyclo ./Src/periph/button.d ./Src/periph/button.o ./Src/periph/button.su ./Src/periph/buzzer.cyclo ./Src/periph/buzzer.d ./Src/periph/buzzer.o ./Src/periph/buzzer.su ./Src/periph/led.cyclo ./Src/periph/led.d ./Src/periph/led.o ./Src/periph/led.su

.PHONY: clean-Src-2f-periph

