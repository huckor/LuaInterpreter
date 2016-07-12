################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/robo/workspace/LuaInterpreter/src/Conv.cpp \
/home/robo/workspace/LuaInterpreter/src/Log.cpp \
/home/robo/workspace/LuaInterpreter/src/LuaInterpreter.cpp \
/home/robo/workspace/LuaInterpreter/src/Path.cpp \
/home/robo/workspace/LuaInterpreter/src/Time.cpp \
/home/robo/workspace/LuaInterpreter/src/main.cpp 

OBJS += \
./Conv.o \
./Log.o \
./LuaInterpreter.o \
./Path.o \
./Time.o \
./main.o 

CPP_DEPS += \
./Conv.d \
./Log.d \
./LuaInterpreter.d \
./Path.d \
./Time.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
Conv.o: /home/robo/workspace/LuaInterpreter/src/Conv.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../../dep/lua/include -O0 -g3 -Wall -c -fmessage-length=0 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Log.o: /home/robo/workspace/LuaInterpreter/src/Log.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../../dep/lua/include -O0 -g3 -Wall -c -fmessage-length=0 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

LuaInterpreter.o: /home/robo/workspace/LuaInterpreter/src/LuaInterpreter.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../../dep/lua/include -O0 -g3 -Wall -c -fmessage-length=0 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Path.o: /home/robo/workspace/LuaInterpreter/src/Path.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../../dep/lua/include -O0 -g3 -Wall -c -fmessage-length=0 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Time.o: /home/robo/workspace/LuaInterpreter/src/Time.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../../dep/lua/include -O0 -g3 -Wall -c -fmessage-length=0 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: /home/robo/workspace/LuaInterpreter/src/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../../dep/lua/include -O0 -g3 -Wall -c -fmessage-length=0 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


