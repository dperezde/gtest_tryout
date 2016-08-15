# nº of cores used during compiling
export MAKEFLAGS="-j $(grep -c ^processor /proc/cpuinfo)"
#
# # version 
 VERSION=0.1
#
# # compiler
CC=g++
#

EXECUTABLE=testAll

# binary folder
EXECDIR=../bin/

# headers include
INCLIB= -I./ -I/usr/local/include/gtest

#-I../../_src 
# dist dir 
DIST_DIR=../dist/

LDFLAGS= -g -L/usr/local/lib -lgtest -lgtest_main -lpthread

SRC=$(wildcard *.cpp)

OBJECTS= $(SRC:.cpp=.o)

HEADERS= $(wildcard *.hpp)


testAll: ${EXECUTABLE}

$(EXECUTABLE): $(OBJECTS) $(HEADERS) 

		$(CC) $(OBJECTS) -o $(EXECDIR)$(EXECUTABLE) $(LDFLAGS)
		


clean:
	@echo "Cleaning up.."
	rm -f *.o *~
