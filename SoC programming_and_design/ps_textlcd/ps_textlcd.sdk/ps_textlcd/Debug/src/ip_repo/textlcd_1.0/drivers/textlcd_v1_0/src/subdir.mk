################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/textlcd.c \
../src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/textlcd_selftest.c 

OBJS += \
./src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/textlcd.o \
./src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/textlcd_selftest.o 

C_DEPS += \
./src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/textlcd.d \
./src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/textlcd_selftest.d 


# Each subdirectory must supply rules for building sources it contributes
src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/%.o: ../src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../ps_textlcd_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


