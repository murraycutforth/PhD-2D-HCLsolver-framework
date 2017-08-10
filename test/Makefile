# A simple makefile to compile the test code for the HCL framework. The
# only external dependencies are the Eigen library, and headers from my
# PhD-Common project. Eigen is a header-only library - just download 
# from eigen.tuxfamily.org and set the value of the EIGEN variable below 
# to the directory of the headers.

EIGEN := -I/home/raid/mcc74/Libraries/eigen-v3.3.4
COMMON := -I/home/raid/mcc74/Documents/phd_17/PhD-Common

test: main.o testproblem.o
	g++ -fopenmp -O3 -o test main.o testproblem.o

main.o: main.cpp testproblem.hpp ./../simulation.hpp ./../splitting_scheme.hpp
	g++ -Wall -std=c++11 $(EIGEN) $(COMMON) -fopenmp -O3 -c main.cpp

testproblem.o: testproblem.hpp testproblem.cpp ./../problem_base.hpp
	g++ -Wall -std=c++11 $(EIGEN) $(COMMON) -fopenmp -O3 -c testproblem.cpp

clean:
	rm *.o test
