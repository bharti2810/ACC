################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BCM.cpp \
../ECM.cpp \
../Radar.cpp \
../Sensors.cpp \
../Speed_sensor.cpp 

OBJS += \
./BCM.o \
./ECM.o \
./Radar.o \
./Sensors.o \
./Speed_sensor.o 

CPP_DEPS += \
./BCM.d \
./ECM.d \
./Radar.d \
./Sensors.d \
./Speed_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


