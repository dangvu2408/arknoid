################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/drivers/gpio.c \
../Src/drivers/timebase.c 

OBJS += \
./Src/drivers/gpio.o \
./Src/drivers/timebase.o 

C_DEPS += \
./Src/drivers/gpio.d \
./Src/drivers/timebase.d 


# Each subdirectory must supply rules for building sources it contributes
Src/drivers/%.o Src/drivers/%.su Src/drivers/%.cyclo: ../Src/drivers/%.c Src/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Drivers/CMSIS/Include" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/button" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/buzzer" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/led" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/rtos" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/sensor" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/serial" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/ucglib" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-drivers

clean-Src-2f-drivers:
	-$(RM) ./Src/drivers/gpio.cyclo ./Src/drivers/gpio.d ./Src/drivers/gpio.o ./Src/drivers/gpio.su ./Src/drivers/timebase.cyclo ./Src/drivers/timebase.d ./Src/drivers/timebase.o ./Src/drivers/timebase.su

.PHONY: clean-Src-2f-drivers

