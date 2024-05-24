################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/screen/pages/connection_page.c \
../Core/Src/screen/pages/date_page.c \
../Core/Src/screen/pages/home_page.c \
../Core/Src/screen/pages/info_page.c \
../Core/Src/screen/pages/menu_page.c 

OBJS += \
./Core/Src/screen/pages/connection_page.o \
./Core/Src/screen/pages/date_page.o \
./Core/Src/screen/pages/home_page.o \
./Core/Src/screen/pages/info_page.o \
./Core/Src/screen/pages/menu_page.o 

C_DEPS += \
./Core/Src/screen/pages/connection_page.d \
./Core/Src/screen/pages/date_page.d \
./Core/Src/screen/pages/home_page.d \
./Core/Src/screen/pages/info_page.d \
./Core/Src/screen/pages/menu_page.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/screen/pages/%.o Core/Src/screen/pages/%.su Core/Src/screen/pages/%.cyclo: ../Core/Src/screen/pages/%.c Core/Src/screen/pages/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-screen-2f-pages

clean-Core-2f-Src-2f-screen-2f-pages:
	-$(RM) ./Core/Src/screen/pages/connection_page.cyclo ./Core/Src/screen/pages/connection_page.d ./Core/Src/screen/pages/connection_page.o ./Core/Src/screen/pages/connection_page.su ./Core/Src/screen/pages/date_page.cyclo ./Core/Src/screen/pages/date_page.d ./Core/Src/screen/pages/date_page.o ./Core/Src/screen/pages/date_page.su ./Core/Src/screen/pages/home_page.cyclo ./Core/Src/screen/pages/home_page.d ./Core/Src/screen/pages/home_page.o ./Core/Src/screen/pages/home_page.su ./Core/Src/screen/pages/info_page.cyclo ./Core/Src/screen/pages/info_page.d ./Core/Src/screen/pages/info_page.o ./Core/Src/screen/pages/info_page.su ./Core/Src/screen/pages/menu_page.cyclo ./Core/Src/screen/pages/menu_page.d ./Core/Src/screen/pages/menu_page.o ./Core/Src/screen/pages/menu_page.su

.PHONY: clean-Core-2f-Src-2f-screen-2f-pages

