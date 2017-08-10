/*
 *	DESCRIPTION:	Unit test of the HCL framework which runs a
 *			simulation.
 * 
 * 	AUTHOR:		Murray Cutforth
 * 	DATE:		20/07/2017
 */

#include "settings_file.hpp"
#include "./../problem_base.hpp"
#include "./../simulation.hpp"
#include "testproblem.hpp"
#include <iostream>
#include <memory>
#include <omp.h>

int main()
{
	settings_file SF;
	SF.read_settings_file("./testsettingsfile.txt");
	std::cout << " - Settings file loaded successfully" << std::endl;
	
	std::shared_ptr<problem_base> problem = std::make_shared<testproblem>();
	std::cout << " - Constructed problem successfully" << std::endl;
	
	simulation sim (SF, problem);
	std::cout << " - Constructed simulation object successfully" << std::endl;
	
	double starttime = omp_get_wtime();
	
	int status = sim.run_simulation();
	
	double endtime = omp_get_wtime();
	
	std::cout << " - Simulation exited with status = " << status << std::endl;
	std::cout << " - The runtime was " << endtime - starttime << "s." << std::endl;
	std::cout << " - All tests complete!" << std::endl;
	
	return 0;
}
