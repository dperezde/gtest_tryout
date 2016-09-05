# Por linea de comandos esto funciona:
# g++ -I/usr/local/include -L/usr/local/lib my.cpp my_tests.cpp -lgtest
# -lpthread
#  Sin embargo make me da error

# nº of cores used during compiling
export MAKEFLAGS="-j $(grep -c ^processor /proc/cpuinfo)"

#version
VERSION=0.1

EXECUTABLE=my_test_${VERSION}

#binary folder
EXECDIR=../bin/
#headers include
INCLIB=/usr/local/include

#################
# GCC Flags     #
#################
CPPFLAGS= -std=c++11 -Wall -O3 -I$(INCLIB) $(LDFLAGS) $(LIBFLAGS)

#################
# Library Flags #
#################
LDFLAGS=-L/usr/local/lib
LIBFLAGS= -lgtest -lpthread

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

	$(CC) $(OBJECTS) $(LDFLAGS) -o $(EXECDIR)$(EXECUTABLE) $(LIBFLAGS)

clean:
	@echo "Cleaning up...)"
	rm -f *.o *~



run: $(EXE)
	@echo "Running " $(EXE) "..."
	@./$(EXECDIR)/$< $(EXE_OPTS)
