/*
 * This is the header for doing specific principle component analysis.
 * Instantiations of pca related functions are in pca.cpp
 */
#ifndef _PCA_GUARD
#define _PCA_GUARD
#define data_num 10
#define feature_num 2016
extern double average[feature_num];
extern double covar[feature_num][feature_num];

#endif

typedef double matrix[][2016];
void subtract_average(matrix origin);
void covar_calc(matrix subtracted);
void PCA(matrix origin);
