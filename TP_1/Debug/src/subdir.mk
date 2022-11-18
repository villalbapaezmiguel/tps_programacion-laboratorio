################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP_1.c \
../src/funciones.c \
../src/utn.c 

C_DEPS += \
./src/TP_1.d \
./src/funciones.d \
./src/utn.d 

OBJS += \
./src/TP_1.o \
./src/funciones.o \
./src/utn.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/TP_1.d ./src/TP_1.o ./src/funciones.d ./src/funciones.o ./src/utn.d ./src/utn.o

.PHONY: clean-src

