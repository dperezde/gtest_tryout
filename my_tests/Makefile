# Por linea de comandos esto funciona:
# g++ -I/usr/local/include -L/usr/local/lib my.cpp my_tests.cpp -lgtest
# -lpthread
# Y ahora el Makefile tambien 

# nº of cores used during compiling
export MAKEFLAGS="-j $(grep -c ^processor /proc/cpuinfo)"


# Define Compiler #
CC=g++
#version
VERSION=0.1

EXECUTABLE=my_test_${VERSION}

#binary folder
EXECDIR=./
#headers include
INCLIB=/usr/local/include/gtest

#################
# GCC Flags     #
#################
CPPFLAGS= -std=c++14 -Wall -O3 -I$(INCLIB) 

#################
# Library Flags #
#################
LDFLAGS=-L/usr/local/lib -lgtest -lpthread

######################
# Sources definition #
######################
SRC= $(wildcard *.cpp)

######################
# Objects Definition #
######################
OBJECTS= $(SRC:.cpp=.o)

######################
# Headers definition #
######################
HEADERS= $(wildcard *.hpp)

all: ${EXECUTABLE}

$(EXECUTABLE): $(OBJECTS) $(HEADERS)

	$(CC) $(OBJECTS)  -o $(EXECDIR)$(EXECUTABLE) $(LDFLAGS)

clean:
	@echo "Cleaning up...)"
	rm -f *.o *~



run: $(EXE)
	@echo "Running " $(EXE) "..."
	@./$(EXECDIR)/$< $(EXE_OPTS)
