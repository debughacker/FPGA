################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/conv1.c \
../src/conv2.c \
../src/copy_buffer.c \
../src/identi_cal.c \
../src/imx222.c \
../src/main.c \
../src/mult_core.c \
../src/v3_rgbin.c \
../src/v3_rgbout.c \
../src/zoom.c 

OBJS += \
./src/conv1.o \
./src/conv2.o \
./src/copy_buffer.o \
./src/identi_cal.o \
./src/imx222.o \
./src/main.o \
./src/mult_core.o \
./src/v3_rgbin.o \
./src/v3_rgbout.o \
./src/zoom.o 

C_DEPS += \
./src/conv1.d \
./src/conv2.d \
./src/copy_buffer.d \
./src/identi_cal.d \
./src/imx222.d \
./src/main.d \
./src/mult_core.d \
./src/v3_rgbin.d \
./src/v3_rgbout.d \
./src/zoom.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: SDSCC Compiler'
	sdscc -Wall -O0 -g -I"../src" -c -fmessage-length=0 -MT"$@" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" -sds-sys-config config0 -sds-proc a9_0 -sds-pf "D:/Coding/FPGA/np9/snowleo2"
	@echo 'Finished building: $<'
	@echo ' '


