/*
 * 	DESCRIPTION:	Functions related to the stiffened gas equation
 * 			of state, defined by the equation:
 * 				
 * 			p = (gamma - 1) * rho * e - gamma * pinf
 * 
 * 			where p, rho, e are pressure, density, and
 * 			specific internal energy respectively, while
 * 			gamma and pinf are material-dependent constants.
 * 
 * 	AUTHOR:		Murray Cutforth
 * 	DATE:		21/07/2017
 */

#ifndef STIFFENEDGASEOS_H
#define STIFFENEDGASEOS_H

#include <cmath>

double pressure (double gamma, double pinf, double e, double rho)
{
	return (gamma - 1.0) * rho * e - gamma * pinf;
}

double specific_ie (double gamma, double pinf, double p, double rho)
{
	return (p + gamma * pinf) / ((gamma - 1.0) * rho);
}

double soundspeed (double gamma, double pinf, double p, double rho)
{
	return sqrt((gamma * (p + pinf)) / rho);
}

double bulkmodulus (double gamma, double pinf, double p, double rho)
{
	double c = soundspeed(gamma, pinf, p, rho);
	return c * c * rho;
}

double isentropic_extrapolation (double gamma, double pinf, double rho_old, double p_old, double p_new)
{
	/* 
	 * Find the density rho_new such that the state (rho_new, p_new)
	 * has the same entropy as the state (rho_old, p_old) using the
	 * isentropic law for stiffened gases.
	 */
	
	return rho_old * pow((p_new + pinf) / (p_old + pinf), 1.0 / gamma);
}

#endif
