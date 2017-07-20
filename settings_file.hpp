/*
 * 	DESCRIPTION:	Class definition for a settings_file object
 * 			which stores all information needed to define
 * 			an initial-value problem for some set of 
 * 			hyperbolic conservation laws.
 * 
 * 	AUTHOR:		Murray Cutforth
 * 	DATE:		19/07/2017
 */

#ifndef SETTINGS_FILE_H
#define SETTINGS_FILE_H

#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

class settings_file {
	
	public:
	
	int Nx;
	int Ny;
	double CFL;
	std::string splitting_scheme;
	std::string test_case;
	int output;
	std::string outputpath;
	std::string basename;
	
	void read_settings_file (std::string filename)
	{
		std::ifstream infile(filename);
		std::string line;
	
		while (std::getline(infile, line))
		{
			std::istringstream iss(line);
			std::string inputname;
	
			iss >> inputname;
			
			if (inputname == "Nx") iss >> Nx;
			
			else if (inputname == "Ny") iss >> Ny;
			
			else if (inputname == "CFL") iss >> CFL;
			
			else if (inputname == "splitting_scheme") iss >> splitting_scheme;
			
			else if (inputname == "test_case") iss >> test_case;
			
			else if (inputname == "output") iss >> output;
			
			else if (inputname == "outputpath") iss >> outputpath;
			
			else
			{
				assert(!"Invalid line in settings file");
			}
		}
			
		basename = outputpath + test_case + "-" + std::to_string(Nx) + "-" + std::to_string(Ny) + ".dat";
		infile.close();
			
	}
};

#endif
