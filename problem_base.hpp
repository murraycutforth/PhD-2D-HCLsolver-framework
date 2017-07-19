/*
 *	DESCRIPTION:	Class definition for the abstract base "problem"
 * 			class. This defines how the grid is updated and
 * 			how time steps are calculated.
 * 
 * 	AUTHOR:		Murray Cutforth
 * 	DATE:		19/07/2017
 */

#include "typedefs.hpp"
#include "settings_file.hpp"

class problem_base {
	
	public:
	
	virtual gridtype& set_ICs (settings_file SF) =0;
	
	virtual void output (const gridtype& grid, const sim_info& params, int n, double t) =0;
	
	virtual double compute_dt (const gridtype& grid, const sim_info& params, double t) =0;
	
	virtual void pre_sweep (gridtype& grid, const sim_info& params) =0;
	
	virtual void update_row (gridtype& grid, gridtype& future_grid, const sim_info& params, int i, double dt, double t) =0;
	
	virtual void post_sweep (gridtype& grid, const sim_info& params) =0;
	
};
