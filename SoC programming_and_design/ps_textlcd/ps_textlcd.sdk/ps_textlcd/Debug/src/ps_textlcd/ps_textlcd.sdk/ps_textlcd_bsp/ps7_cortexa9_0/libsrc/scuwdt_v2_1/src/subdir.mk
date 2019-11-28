################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt.c \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_g.c \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_selftest.c \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_sinit.c 

OBJS += \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt.o \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_g.o \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_selftest.o \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_sinit.o 

C_DEPS += \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt.d \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_g.d \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_selftest.d \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/xscuwdt_sinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/%.o: ../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../ps_textlcd_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


