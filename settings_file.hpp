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

class settings_file {
	
	public:
	
	int Nx;
	int Ny;
	std::string splitting_scheme;
	std::string test_case;
	
	void read_settings_file (std::string filename)
	{
		// TODO: Implement read-in from file
	}
};

#endif
