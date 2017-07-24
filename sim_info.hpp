/*
 *	DESCRIPTION:	Class definition for a sim_info object. This
 * 			contains all information needed to define a 2D
 * 			Cartesian grid, as well as other necessary data.
 * 
 * 	AUTHOR:		Murray Cutforth
 * 	DATE:		19/07/2017
 */

#ifndef SIM_INFO_H
#define SIM_INFO_H

struct sim_info {
	
	int Nx;
	int Ny;
	double x0;
	double y0;
	double dx;
	double dy;
	int numGC;
	std::string BC_T;
	std::string BC_L;
	std::string BC_B;
	std::string BC_R;
	
	double T;
	double CFL;
	std::string outputname;
	
	std::string riemann_solver;
	int stclsize;
	std::string flux_solver;
	
	sim_info ()
	{}
};

#endif
