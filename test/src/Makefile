CXX = g++
CXXFLAGS = -g -L/usr/local/lib -lgtest -lgtest_main -lpthread
INCS = -I./ -I../../src -I/usr/local/include/gtest
OBJS = ../../src/Addition.o Addition_Test.o ../../src/Multiply.o Multiply_Test.o

testAll: $(OBJS)
		$(CXX) $(CXXFLAGS) $(INCS) -o testAll  Main_TestAll.cpp $(OBJS)

.cpp.o:
		$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
		rm testAll *.o testAll.xml
