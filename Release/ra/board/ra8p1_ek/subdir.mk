################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/board/ra8p1_ek/board_init.c \
../ra/board/ra8p1_ek/board_leds.c 

C_DEPS += \
./ra/board/ra8p1_ek/board_init.d \
./ra/board/ra8p1_ek/board_leds.d 

OBJS += \
./ra/board/ra8p1_ek/board_init.o \
./ra/board/ra8p1_ek/board_leds.o 

SREC += \
ra8p1_my_qiansai.srec 

MAP += \
ra8p1_my_qiansai.map 


# Each subdirectory must supply rules for building sources it contributes
ra/board/ra8p1_ek/%.o: ../ra/board/ra8p1_ek/%.c
	$(file > $@.in,-mthumb -mfloat-abi=hard -mcpu=cortex-m85+nopacbti -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_RA_ -D_RA_CORE=CPU0 -D_RA_ORDINAL=1 -I"F:/project_of_competition/qian_sai/workspace/ra8p1_my_qiansai/ra_gen" -I"." -I"F:/project_of_competition/qian_sai/workspace/ra8p1_my_qiansai/ra_cfg/fsp_cfg/bsp" -I"F:/project_of_competition/qian_sai/workspace/ra8p1_my_qiansai/ra_cfg/fsp_cfg" -I"F:/project_of_competition/qian_sai/workspace/ra8p1_my_qiansai/src" -I"F:/project_of_competition/qian_sai/workspace/ra8p1_my_qiansai/ra/fsp/inc" -I"F:/project_of_competition/qian_sai/workspace/ra8p1_my_qiansai/ra/fsp/inc/api" -I"F:/project_of_competition/qian_sai/workspace/ra8p1_my_qiansai/ra/fsp/inc/instances" -I"F:/project_of_competition/qian_sai/workspace/ra8p1_my_qiansai/ra/arm/CMSIS_6/CMSIS/Core/Include" -std=c99 -Wno-stringop-overflow -Wno-format-truncation -flax-vector-conversions --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

