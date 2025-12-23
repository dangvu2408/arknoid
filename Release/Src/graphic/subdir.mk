################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/graphic/display_init.c \
../Src/graphic/render.c 

OBJS += \
./Src/graphic/display_init.o \
./Src/graphic/render.o 

C_DEPS += \
./Src/graphic/display_init.d \
./Src/graphic/render.d 


# Each subdirectory must supply rules for building sources it contributes
Src/graphic/%.o Src/graphic/%.su Src/graphic/%.cyclo: ../Src/graphic/%.c Src/graphic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-graphic

clean-Src-2f-graphic:
	-$(RM) ./Src/graphic/display_init.cyclo ./Src/graphic/display_init.d ./Src/graphic/display_init.o ./Src/graphic/display_init.su ./Src/graphic/render.cyclo ./Src/graphic/render.d ./Src/graphic/render.o ./Src/graphic/render.su

.PHONY: clean-Src-2f-graphic

