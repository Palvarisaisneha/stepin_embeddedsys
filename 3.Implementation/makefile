PROJ_NAME = Embedded_sys

 
# All header file paths
INC = -I inc
BUILD_DIR = Build

# Configuring for Both Windows and Linux Operating System
ifdef OS	# Windwos OS
# Correct the path based on OS
   FixPath = $(subst /,\,$1)
# AVR Compiler
   CC = avr-gcc.exe
# .elf to .hex
   AVR_OBJ_CPY = avr-objcopy.exe
else # Linux OS
   ifeq ($(shell uname), Linux)
# Correct the path based on Linux
      FixPath = $1				
 
	  CC = avr-gcc
# N.elf to .hex
	  AVR_OBJ_CPY = avr-objcopy 
   endif
endif
.PHONY:all analysis clean doc

all:$(BUILD_DIR)
 
$(BUILD_DIR):
# Create directory to store the built files
	mkdir $(BUILD_DIR)

analysis: $(SRC)
# Analyse the code using Cppcheck command line utility
	cppcheck --enable=all $^

doc:
# Build the code code documentation using Doxygen command line utility
	make -C documentation

clean:
# Remove all the build files and generated document files
	rm -rf $(call FixPath,$(BUILD_DIR)/*)
	make -C documentation clean
