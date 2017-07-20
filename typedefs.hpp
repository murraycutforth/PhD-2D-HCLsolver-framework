/*
 *	DESCRIPTION:	All typedefs are defined here for clarity.
 * 
 * 	AUTHOR:		Murray Cutforth
 * 	DATE:		19/07/2017
 */
 
#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include <Eigen/Dense>

typedef Eigen::VectorXd vectype;
typedef std::vector<vectype> rowtype;
typedef std::vector<rowtype> gridtype;

#endif
