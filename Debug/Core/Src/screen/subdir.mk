################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/screen/screen.c 

OBJS += \
./Core/Src/screen/screen.o 

C_DEPS += \
./Core/Src/screen/screen.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/screen/%.o Core/Src/screen/%.su Core/Src/screen/%.cyclo: ../Core/Src/screen/%.c Core/Src/screen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-screen

clean-Core-2f-Src-2f-screen:
	-$(RM) ./Core/Src/screen/screen.cyclo ./Core/Src/screen/screen.d ./Core/Src/screen/screen.o ./Core/Src/screen/screen.su

.PHONY: clean-Core-2f-Src-2f-screen

