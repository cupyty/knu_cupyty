################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/textlcd/textlcd.sim/sim_1/behav/xsim/xsim.dir/tb_textlcd_behav/obj/subdir.mk
-include src/ps_textlcd/ps_textlcd.srcs/sources_1/bd/system/ip/system_processing_system7_0_0/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/system_wrapper_hw_platform_0/drivers/textlcd_v1_0/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/system_wrapper_hw_platform_0/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/xadcps_v2_2/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/uartps_v3_5/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/textlcd_v1_0/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/standalone_v6_5/src/profile/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/standalone_v6_5/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scuwdt_v2_1/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scutimer_v2_1/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/scugic_v3_8/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/dmaps_v2_3/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/devcfg_v3_5/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/ps_textlcd_bsp/ps7_cortexa9_0/libsrc/coresightps_dcc_v1_4/src/subdir.mk
-include src/ps_textlcd/ps_textlcd.sdk/.metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include src/ip_repo/textlcd_1.0/drivers/textlcd_v1_0/src/subdir.mk
-include src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_vending_machine_behav/obj/subdir.mk
-include src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_jk_ff_behav/obj/subdir.mk
-include src/Verilog_2/Verilog_2.sim/sim_1/behav/xsim/xsim.dir/tb_bcd_counter_behav/obj/subdir.mk
-include src/Verilog_1/Verilog_1.sim/sim_1/behav/xsim/xsim.dir/mux_behav/obj/subdir.mk
-include src/Verilog_1/Verilog_1.sim/sim_1/behav/xsim/xsim.dir/mux_4_behav/obj/subdir.mk
-include src/Verilog_1/Verilog_1.sim/sim_1/behav/xsim/xsim.dir/decoder_behav/obj/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
ps_textlcd.elf.size \


# All Target
all: pre-build main-build

# Main-build Target
main-build: ps_textlcd.elf secondary-outputs

# Tool invocations
ps_textlcd.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM v7 gcc linker'
	arm-none-eabi-gcc -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -Wl,-build-id=none -specs=Xilinx.spec -Wl,-T -Wl,../src/lscript.ld -L../../ps_textlcd_bsp/ps7_cortexa9_0/lib -o "ps_textlcd.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ps_textlcd.elf.size: ps_textlcd.elf
	@echo 'Invoking: ARM v7 Print Size'
	arm-none-eabi-size ps_textlcd.elf  |tee "ps_textlcd.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(S_UPPER_DEPS)$(C_DEPS)$(ELFSIZE) ps_textlcd.elf
	-@echo ' '

pre-build:
	-a9-linaro-pre-build-step
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets
