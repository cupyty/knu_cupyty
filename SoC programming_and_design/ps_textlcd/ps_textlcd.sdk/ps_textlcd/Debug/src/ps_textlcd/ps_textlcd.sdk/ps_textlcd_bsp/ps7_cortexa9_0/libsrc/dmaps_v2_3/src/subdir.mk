################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps.c \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_g.c \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_hw.c \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_selftest.c \
../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_sinit.c 

OBJS += \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps.o \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_g.o \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_hw.o \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_selftest.o \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_sinit.o 

C_DEPS += \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps.d \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_g.d \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_hw.d \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_selftest.d \
./src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/xdmaps_sinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/%.o: ../src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../ps_textlcd_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


