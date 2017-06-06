###############################################################################
# Executables

PREFIX		?= arm-none-eabi

CC		:= $(PREFIX)-gcc
CXX		:= $(PREFIX)-g++
LD		:= $(PREFIX)-gcc
AR		:= $(PREFIX)-ar
AS		:= $(PREFIX)-as
OBJCOPY		:= $(PREFIX)-objcopy
OBJDUMP		:= $(PREFIX)-objdump
GDB		:= $(PREFIX)-gdb
STFLASH		= $(shell which st-flash)
STYLECHECK	:= /checkpatch.pl
STYLECHECKFLAGS	:= --no-tree -f --terse --mailback
FP_FLAGS    ?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
STYLECHECKFILES	:= $(shell find . -name '*.[ch]')
###############################################################################

TGT_CFLAGS	= -Os \
		  -Wall -Wextra -Wimplicit-function-declaration \
		  -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		  -Wundef -Wshadow \
		  -fno-common \
		  -mcpu=cortex-m4 -mthumb $(FP_FLAGS) \
		  -Wstrict-prototypes \
		  -ffunction-sections -fdata-sections -MD -DSTM32F4

###############################################################################
OS_LIB_PATH=$(PWD)/lib
OS_LIB=libLOS
OS_SRC_PATH := $(PWD)
OS_SRC := $(wildcard $(OS_SRC_PATH)*.c)
OS_SRC :=$(notdir $(OS_SRC))
OBJS :=$(OS_SRC:.c=.o)

###############################################################################
LIBOPENCM3_INCLUDE_PATH=$(PWD)/../libopencm3/include
DRIVER_INCLUDE_PATH=$(PWD)../driver/stm32/include
LSQFLAG = -I$(OS_INCLUDE_PATH)
LSQFLAG += -I$(PWD)/../config/easypilot_master
LSQFLAG += -I$(LIBOPENCM3_INCLUDE_PATH)
LSQFLAG += -I$(OS_INCLUDE_PATH)
LSQFLAG += -DSTM32F4

SRC_DIR = $(PWD)
ifdef TESTDEF
	foo = 1
else
	foo = 2
endif
#######################################################
CFLAGS		+= -Os -g
CFLAGS		+= -Wextra -Wshadow -Wimplicit-function-declaration
CFLAGS		+= -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes
CFLAGS		+= -fno-common -ffunction-sections -fdata-sections $(LSQFLAG) -L$(SRC_DIR)
#######################################################
all : $(OS_LIB).a  $(OS_LIB).so
	@echo "Going to make all ${foo}"
$(OS_LIB).a : $(OBJS)
	@echo "Going to main $(OBJS)"
	$(AR) rcs  $@ $^
	mv $@ $(OS_LIB_PATH)
	@echo "Finish main"
$(OS_LIB).so : $(OBJS)
	@echo "Going to main $(OBJS)"
	$(CC) $(TGT_CFLAGS)  -shared -fPIC -o $@ $^
	mv $@ $(OS_LIB_PATH)
	@echo "Finish main"
%.o : $(OS_SRC_PATH)%.c
	@echo  "  CC     $(*).c  $(foo)\n"
	##$(Q)$(CC) $(CFLAGS) $(ARCH_FLAGS)  -o $(*).o -c $(*).c
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS)   -o $*.o -c $(OS_SRC_PATH)$*.c
clean :	
	@echo "Going to clear all"
	-rm $(OS_LIB_PATH)/*.a $(OS_LIB_PATH)/*.so ./*.o
	@echo "Finish clear"

