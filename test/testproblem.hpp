/*
 *	DESCRIPTION:	An example derived class of the problem_base
  *			class for unit testing of the HCL framework.
 * 
 * 	AUTHOR:		Murray Cutforth
 * 	DATE:		20/07/2017
 */


#ifndef TESTPROBLEM_H
#define TESTPROBLEM_H

#include "./../problem_base.hpp"
#include "./../typedefs.hpp"
#include "./../settings_file.hpp"

class testproblem : public problem_base {
	
	public:
	
	std::shared_ptr<gridtype> set_ICs (settings_file SF, sim_info& params);
	
	void output (const gridtype& grid, const sim_info& params, int n, double t);
	
	double compute_dt (const gridtype& grid, const sim_info& params, double t);
	
	void pre_sweep (gridtype& grid, const sim_info& params);
	
	void update_row (const gridtype& grid, gridtype& future_grid, const sim_info& params, int i, double dt, double t);
	
	void update_col (const gridtype& grid, gridtype& future_grid, const sim_info& params, int j, double dt, double t);
	
	void post_sweep (gridtype& grid, gridtype& future_grid, const sim_info& params);
	
};

#endif
