# Makefile for Esterel v6.1 programs
# 
# Author: Jan Lukoschus
#
# 2002-06-10 jlu - first version
# 2002-06-12 jlu - remove intermediate files for xes
# 2002-06-17 jlu - EFLAGS4X added
# 2002-06-18 jlu - export ESTEREL
# 2002-06-20 jlu - disable some implicit rules
# 2002-06-20 jlu - keep some intermediate with .PRECIOUS
# 2002-06-20 jlu - link with -lpthread
# 2003-03-24 jlu - v5_92
# 2004-01-22 jlu - create empty .h _data.c
# 2005-02-02 jlu - ctype.c: fix for XES with glibc-2.3.3
# 2005-02-02 jlu - use 32-bit build on x86_64
# 2023-05-26 - Updated for testing with Esterel v6.1

default:
	@echo "Usage:"
	@echo "  'make cruiseControl.c'    - Compile Esterel code 'cruiseControl.strl' into C Code in 'cruiseControl.c'"
	@echo "  'make cruiseControl'      - Compile and link Esterel code in 'cruiseControl.strl' with C code"
	@echo "                     in 'cruiseControl_data.c' and build executable 'cruiseControl'"
	@echo "  'make cruiseControl.xes'  - Compile and link Esterel code in 'cruiseControl.strl' with xes debugger"
	@echo "                     and build executable 'cruiseControl.exe' and shell wrapper 'cruiseControl.xes'"
	@echo "  'make test_cruise_control' - Compile and run the test suite for the CruiseControl system"

# Force 32-bit build on Athlon64/Opteron systems
ifeq ($(shell uname -p), x86_64)
  GCC32=-m32 
endif

export ESTEREL=/opt/esterelv6_01

CC       = gcc
CFLAGS   = $(GCC32) -Wall -L$(ESTEREL)/lib -I$(ESTEREL)/include
LDFLAGS  = $(GCC32) -L$(ESTEREL)/lib -I$(ESTEREL)/include -lrt -lpthread

ESTEREL2C= $(ESTEREL)/bin/esterel
EFLAGS   =
EFLAGS4X = -simul -I

XES      = $(ESTEREL)/bin/xes
XESFLAGS = -cc "$(CC)" $(foreach t,$(GCC32),-Xcomp $(t))

XEVE     = $(ESTEREL)/bin/xeve

# Fix for XES on a Linux system with glibc-2.3.3:
#    ": undefined reference to `__ctype_b'"
# see: http://newweb.ices.utexas.edu/misc/ctype.c
#
ifeq ($(shell uname -s), Linux)
  XESCTYPEFIX=ctype.o
endif

# intermediate files to keep after compiling
.PRECIOUS: %.c %.o %_data.o

# disable some implicit rules 
%.o: %.c
%:   %.c
%:   %.o

ctype.o: ctype.c
