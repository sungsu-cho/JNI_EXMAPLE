OS_NAME := $(shell uname -s | tr A-Z a-z | sed 's/-.*//g' )

CC = g++

ifeq ($(OS_NAME),darwin)
JAVA_HOME = $$(/usr/libexec/java_home)
JAVA_INC = -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/darwin"
LIB_TAIL = dylib
else
JAVA_HOME ?= $(readlink -e "$$(dirname "$$(readlink -e "$$(which javac)")")"/..)
JAVA_INC = -I"$(JAVA_HOME)/include" -I"$(JAVA_HOME)/include/linux"
LIB_TAIL = so
endif

INCS  = $(JAVA_INC) 

CFLAGS = -fPIC
LDFLAGS += -shared 

JNI_LIB_NAME = ../bin/libJNIHashtable.$(LIB_TAIL)

SRCS = JNIHashtable.cpp
JAVA_SRCS = JNIHashtable.java

OBJS = $(SRCS:.cpp=.o)
JAVA_OBJS = $(JAVA_SRCS:.java=.class)

all: $(JNI_LIB_NAME) 
	javac -d ../bin $(JAVA_SRCS)

.cpp.o:
	$(CC) -c $(CFLAGS) $(INCS) $<

$(JNI_LIB_NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
	rm -rf $(OBJS)

clean:
	rm -rf *.o 
	rm -rf bin/*.class
	rm -rf $(JNI_LIB_NAME)