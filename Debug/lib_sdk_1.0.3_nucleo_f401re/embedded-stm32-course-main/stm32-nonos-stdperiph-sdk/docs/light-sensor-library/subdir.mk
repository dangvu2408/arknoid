################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.c 

OBJS += \
./lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.o 

C_DEPS += \
./lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.d 


# Each subdirectory must supply rules for building sources it contributes
lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.o: D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.c lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Drivers/CMSIS/Include" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/button" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/buzzer" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/led" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/rtos" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/sensor" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/serial" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Middle/ucglib" -I"D:/STM32CubePrj/lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/shared/Utilities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lib_sdk_1-2e-0-2e-3_nucleo_f401re-2f-embedded-2d-stm32-2d-course-2d-main-2f-stm32-2d-nonos-2d-stdperiph-2d-sdk-2f-docs-2f-light-2d-sensor-2d-library

clean-lib_sdk_1-2e-0-2e-3_nucleo_f401re-2f-embedded-2d-stm32-2d-course-2d-main-2f-stm32-2d-nonos-2d-stdperiph-2d-sdk-2f-docs-2f-light-2d-sensor-2d-library:
	-$(RM) ./lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.cyclo ./lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.d ./lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.o ./lib_sdk_1.0.3_nucleo_f401re/embedded-stm32-course-main/stm32-nonos-stdperiph-sdk/docs/light-sensor-library/LightDependentResistor.su

.PHONY: clean-lib_sdk_1-2e-0-2e-3_nucleo_f401re-2f-embedded-2d-stm32-2d-course-2d-main-2f-stm32-2d-nonos-2d-stdperiph-2d-sdk-2f-docs-2f-light-2d-sensor-2d-library

