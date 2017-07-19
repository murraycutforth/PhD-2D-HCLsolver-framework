/*
 *	DESCRIPTION:	Class definition for a simulation object. This
 *			is called by another program in order to fully
 *			run a problem as specified in a given settings
 *			file.
 * 
 * 	AUTHOR:		Murray Cutforth
 * 	DATE:		19/07/2017
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <vector>
#include <blitz/array.h>
#include <memory>
#include "sim_info.hpp"
#include "settings_file.hpp"
#include "typedefs.hpp"

class simulation {
	
	public:
	
	settings_file SF;
	std::shared_ptr<problem_base> problem;
	
	simulation (SF, std::shared_ptr<problem_base>)
	:
		SF (SF),
		problem (problem)
	{}
	
	int run_simulation ()
	{
		sim_info params (SF);
		gridtype grid (problem->set_ICs(SF));
		gridtype future_grid (problem->set_ICs(SF));
		std::shared_ptr<splitting_scheme_base> splitting_scheme (set_splitting_scheme(SF));
		
		int n = 0;
		double t = 0.0, dt;
		
		while (t <= params.T)
		{
			problem->output(grid, params, n, t);
			
			dt = problem->compute_dt(grid, params, t);
			
			splitting_scheme->advance_timestep(problem, grid, future_grid, params, dt, t);
			
			t += dt;
			n++;
		}
		
		problem->output(grid, params, n, t);
		return 0;
	}
};

#endif
			
