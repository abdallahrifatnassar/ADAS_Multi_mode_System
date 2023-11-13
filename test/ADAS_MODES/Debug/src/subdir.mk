################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AALC_program.c \
../src/ACC_program.c \
../src/ALKA_IR.c \
../src/HIR_program.c \
../src/HLDR_program.c \
../src/HMOTORS_program.c \
../src/HULTRASONIC_program.c \
../src/LDW_program.c \
../src/MGPIO_program.c \
../src/MNVIC_program.c \
../src/MRCC_program.c \
../src/MSYSTICK_program.c \
../src/MTIMER_program.c \
../src/MUSART_program.c \
../src/initialize-hardware.c \
../src/main.c \
../src/stm32f4xx_hal_msp.c \
../src/write.c 

OBJS += \
./src/AALC_program.o \
./src/ACC_program.o \
./src/ALKA_IR.o \
./src/HIR_program.o \
./src/HLDR_program.o \
./src/HMOTORS_program.o \
./src/HULTRASONIC_program.o \
./src/LDW_program.o \
./src/MGPIO_program.o \
./src/MNVIC_program.o \
./src/MRCC_program.o \
./src/MSYSTICK_program.o \
./src/MTIMER_program.o \
./src/MUSART_program.o \
./src/initialize-hardware.o \
./src/main.o \
./src/stm32f4xx_hal_msp.o \
./src/write.o 

C_DEPS += \
./src/AALC_program.d \
./src/ACC_program.d \
./src/ALKA_IR.d \
./src/HIR_program.d \
./src/HLDR_program.d \
./src/HMOTORS_program.d \
./src/HULTRASONIC_program.d \
./src/LDW_program.d \
./src/MGPIO_program.d \
./src/MNVIC_program.d \
./src/MRCC_program.d \
./src/MSYSTICK_program.d \
./src/MTIMER_program.d \
./src/MUSART_program.d \
./src/initialize-hardware.d \
./src/main.d \
./src/stm32f4xx_hal_msp.d \
./src/write.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -Wno-padded -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


