################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/cli_command.c \
../Core/Src/cli_command_table.c \
../Core/Src/cli_type.c \
../Core/Src/gettemp_ci.c \
../Core/Src/lm35.c \
../Core/Src/main.c \
../Core/Src/response.c \
../Core/Src/settemp_ci.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/uart.c 

OBJS += \
./Core/Src/cli_command.o \
./Core/Src/cli_command_table.o \
./Core/Src/cli_type.o \
./Core/Src/gettemp_ci.o \
./Core/Src/lm35.o \
./Core/Src/main.o \
./Core/Src/response.o \
./Core/Src/settemp_ci.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/uart.o 

C_DEPS += \
./Core/Src/cli_command.d \
./Core/Src/cli_command_table.d \
./Core/Src/cli_type.d \
./Core/Src/gettemp_ci.d \
./Core/Src/lm35.d \
./Core/Src/main.d \
./Core/Src/response.d \
./Core/Src/settemp_ci.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/cli_command.cyclo ./Core/Src/cli_command.d ./Core/Src/cli_command.o ./Core/Src/cli_command.su ./Core/Src/cli_command_table.cyclo ./Core/Src/cli_command_table.d ./Core/Src/cli_command_table.o ./Core/Src/cli_command_table.su ./Core/Src/cli_type.cyclo ./Core/Src/cli_type.d ./Core/Src/cli_type.o ./Core/Src/cli_type.su ./Core/Src/gettemp_ci.cyclo ./Core/Src/gettemp_ci.d ./Core/Src/gettemp_ci.o ./Core/Src/gettemp_ci.su ./Core/Src/lm35.cyclo ./Core/Src/lm35.d ./Core/Src/lm35.o ./Core/Src/lm35.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/response.cyclo ./Core/Src/response.d ./Core/Src/response.o ./Core/Src/response.su ./Core/Src/settemp_ci.cyclo ./Core/Src/settemp_ci.d ./Core/Src/settemp_ci.o ./Core/Src/settemp_ci.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/uart.cyclo ./Core/Src/uart.d ./Core/Src/uart.o ./Core/Src/uart.su

.PHONY: clean-Core-2f-Src

