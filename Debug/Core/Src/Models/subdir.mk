################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Models/screen_model.c 

OBJS += \
./Core/Src/Models/screen_model.o 

C_DEPS += \
./Core/Src/Models/screen_model.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Models/%.o Core/Src/Models/%.su Core/Src/Models/%.cyclo: ../Core/Src/Models/%.c Core/Src/Models/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Models

clean-Core-2f-Src-2f-Models:
	-$(RM) ./Core/Src/Models/screen_model.cyclo ./Core/Src/Models/screen_model.d ./Core/Src/Models/screen_model.o ./Core/Src/Models/screen_model.su

.PHONY: clean-Core-2f-Src-2f-Models

