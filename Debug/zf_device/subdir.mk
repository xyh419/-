################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../zf_device/zf_device_dl1b.c \
../zf_device/zf_device_ips200.c \
../zf_device/zf_device_scc8660.c 

C_DEPS += \
./zf_device/zf_device_dl1b.d \
./zf_device/zf_device_ips200.d \
./zf_device/zf_device_scc8660.d 

OBJS += \
./zf_device/zf_device_dl1b.o \
./zf_device/zf_device_ips200.o \
./zf_device/zf_device_scc8660.o 

SREC += \
cpkhmi_ra8p1_zf_device_ips200_demo.srec 

MAP += \
cpkhmi_ra8p1_zf_device_ips200_demo.map 


# Each subdirectory must supply rules for building sources it contributes
zf_device/%.o: ../zf_device/%.c
	$(file > $@.in,-mthumb -mfloat-abi=hard -mcpu=cortex-m85+nopacbti -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/ra_gen" -I"." -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/ra_cfg/fsp_cfg/bsp" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/ra_cfg/fsp_cfg" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/src" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/ra/fsp/inc" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/ra/fsp/inc/api" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/ra/fsp/inc/instances" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/ra/arm/CMSIS_6/CMSIS/Core/Include" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/zf_common" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/zf_driver" -I"D:/example project/cpkhmi_ra8p1_zf_device_ips200_original/zf_device" -std=c99 -Wno-stringop-overflow -Wno-format-truncation -flax-vector-conversions --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

