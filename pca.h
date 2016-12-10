/*
 * This is the header for doing specific principle component analysis.
 * Instantiations of pca related functions are in pca.cpp
 */
#define data_num 10
#define feature_num 2016

typedef double matrix[][2016];

void subtract_average(matrix origin);
void PCA(matrix origin);
