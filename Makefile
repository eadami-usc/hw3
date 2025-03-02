CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.h llrec.cpp llrec-test.cpp
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.cpp -o $@

clean:
	rm -f *.o llrec-test *~

.PHONY: clean 