################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
OBJ_SRCS += \
../src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_bcd_counter_behav/obj/xsim_0.win64.obj \
../src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_bcd_counter_behav/obj/xsim_1.win64.obj 

C_SRCS += \
../src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_bcd_counter_behav/obj/xsim_1.c 

OBJS += \
./src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_bcd_counter_behav/obj/xsim_1.o 

C_DEPS += \
./src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_bcd_counter_behav/obj/xsim_1.d 


# Each subdirectory must supply rules for building sources it contributes
src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_bcd_counter_behav/obj/%.o: ../src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_bcd_counter_behav/obj/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../ps_textlcd_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


