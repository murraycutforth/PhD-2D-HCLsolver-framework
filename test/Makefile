# A simple makefile to compile the test code for the HCL framework. The
# only external dependency is the Eigen library. This is a header-only
# library - just download from eigen.tuxfamily.org and set the value of
# the EIGEN variable below to the directory of the headers.

EIGEN := -I/home/raid/mcc74/Libraries/eigen-v3.3.4

test: main.o testproblem.o
	g++ -fopenmp -O3 -o test main.o testproblem.o

main.o: main.cpp ./../settings_file.hpp testproblem.hpp ./../simulation.hpp ./../splitting_scheme.hpp
	g++ -Wall -std=c++11 $(EIGEN) -fopenmp -O3 -c main.cpp

testproblem.o: testproblem.hpp testproblem.cpp ./../settings_file.hpp ./../typedefs.hpp ./../problem_base.hpp
	g++ -Wall -std=c++11 $(EIGEN) -fopenmp -O3 -c testproblem.cpp

clean:
	rm *.o test
