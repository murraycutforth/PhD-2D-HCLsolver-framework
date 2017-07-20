# A simple makefile to compile the test code for the HCL framework. The
# only external dependency is the Eigen library. This is a header-only
# library - just download from eigen.tuxfamily.org and set the value of
# the EIGEN variable below to the directory of the headers.

EIGEN := -I/home/raid/mcc74/Libraries/eigen-v3.3.4

test: main.o testproblem.o
	g++ -fopenmp -o test main.o testproblem.o

main.o: main.cpp ./../settings_file.hpp testproblem.hpp ./../simulation.hpp
	g++ -g -Wall -std=c++11 $(EIGEN) -c main.cpp

testproblem.o: testproblem.hpp testproblem.cpp ./../settings_file.hpp ./../typedefs.hpp ./../problem_base.hpp
	g++ -g -Wall -std=c++11 $(EIGEN) -c testproblem.cpp

clean:
	rm *.o test
