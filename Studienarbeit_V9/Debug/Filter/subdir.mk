################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Filter/filter.c 

OBJS += \
./Filter/filter.o 

C_DEPS += \
./Filter/filter.d 


# Each subdirectory must supply rules for building sources it contributes
Filter/%.o Filter/%.su Filter/%.cyclo: ../Filter/%.c Filter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu18 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4S5xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Lucas/git/Studienarbeit_Software_Engineering/Studienarbeit_V9/Sensors" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/Lucas/git/Studienarbeit_Software_Engineering/Studienarbeit_V9/Middlewares/Third_Party/Segger" -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Filter

clean-Filter:
	-$(RM) ./Filter/filter.cyclo ./Filter/filter.d ./Filter/filter.o ./Filter/filter.su

.PHONY: clean-Filter

