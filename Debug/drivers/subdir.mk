################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/adc.c \
../drivers/clock.c \
../drivers/gpio.c \
../drivers/nvic.c \
../drivers/port.c \
../drivers/systick.c 

C_DEPS += \
./drivers/adc.d \
./drivers/clock.d \
./drivers/gpio.d \
./drivers/nvic.d \
./drivers/port.d \
./drivers/systick.d 

OBJS += \
./drivers/adc.o \
./drivers/clock.o \
./drivers/gpio.o \
./drivers/nvic.o \
./drivers/port.o \
./drivers/systick.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"F:\KL46Project\MKL46Z4_DriverMCU\workspace\MKL46Z4_LightSensor\source" -I"F:\KL46Project\MKL46Z4_DriverMCU\workspace\MKL46Z4_LightSensor\interface" -I"F:\KL46Project\MKL46Z4_DriverMCU\workspace\MKL46Z4_LightSensor\middleware" -I"F:\KL46Project\MKL46Z4_DriverMCU\workspace\MKL46Z4_LightSensor\drivers" -I"F:\KL46Project\MKL46Z4_DriverMCU\workspace\MKL46Z4_LightSensor" -I"F:\KL46Project\MKL46Z4_DriverMCU\workspace\MKL46Z4_LightSensor\CMSIS" -I"F:\KL46Project\MKL46Z4_DriverMCU\workspace\MKL46Z4_LightSensor\startup" -I"F:\KL46Project\MKL46Z4_DriverMCU\workspace\MKL46Z4_LightSensor\drivers" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/adc.d ./drivers/adc.o ./drivers/clock.d ./drivers/clock.o ./drivers/gpio.d ./drivers/gpio.o ./drivers/nvic.d ./drivers/nvic.o ./drivers/port.d ./drivers/port.o ./drivers/systick.d ./drivers/systick.o

.PHONY: clean-drivers

