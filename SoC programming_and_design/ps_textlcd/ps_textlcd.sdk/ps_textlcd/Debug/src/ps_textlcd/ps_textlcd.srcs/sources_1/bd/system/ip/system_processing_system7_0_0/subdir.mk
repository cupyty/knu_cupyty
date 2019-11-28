################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/ps7_init.c \
../src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/ps7_init_gpl.c 

OBJS += \
./src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/ps7_init.o \
./src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/ps7_init_gpl.o 

C_DEPS += \
./src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/ps7_init.d \
./src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/ps7_init_gpl.d 


# Each subdirectory must supply rules for building sources it contributes
src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/%.o: ../src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../ps_textlcd_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


