/*
 * This is the header for doing specific principle component analysis.
 * Instantiations of pca related functions are in pca.cpp
 */
#ifndef _PCA_GUARD
#define _PCA_GUARD
#define data_num 10
#define feature_num 2016
#define RESERVED 2

#include <cmath>
#include <iostream>
#include <fstream>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "eigen/rt_nonfinite.h"
#include "eigen/rtwtypes.h"
#include "eigen/eigen_types.h"
#include "eigen/rt_nonfinite.h"
#include "eigen/eigen.h"
#include "eigen/eigen_terminate.h"
#include "eigen/eigen_initialize.h"


#endif

extern double average[feature_num];
extern double covar[feature_num * feature_num];
extern double eigenvector[feature_num][feature_num];
extern double final_untransposed[data_num][RESERVED];
typedef double matrix[][feature_num];
void subtract_average(matrix origin);
void covar_calc(matrix subtracted);
void PCA(matrix origin);
