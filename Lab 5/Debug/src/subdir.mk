################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lab5_main.c \
../src/name_list.c \
../src/rm_library.c 

OBJS += \
./src/lab5_main.o \
./src/name_list.o \
./src/rm_library.o 

C_DEPS += \
./src/lab5_main.d \
./src/name_list.d \
./src/rm_library.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -include../name_list.h -include../rm_library.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


