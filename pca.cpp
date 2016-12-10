/*
 * This is the pca.cpp file which instantiate pca related functions.
 */
#include "pca.h"

double average[feature_num];
double covar[feature_num][feature_num];
void subtract_average(matrix origin) {
	for(int i = 0; i != feature_num; ++i) {
		double ave = 0;
		for(int j = 0; j != data_num; ++j) {
			ave += origin[j][i];
		}
		ave /= data_num;
		average[i] = ave;
		for(int j = 0; j != data_num; ++j) {
			origin[j][i] -= ave;
		}
	}
	return ;
}

void covar_calc(matrix subtracted) {
	//generate half of the matrix and copy it reversedly.
	for(int i = 0; i != feature_num; ++i) {
		for(int k = i; k != feature_num; ++k) {
			double cov = 0;
			for(int j = 0; j != data_num; ++j) {
				cov += (subtracted[j][i] - average[i]) * (subtracted[j][k] - average[k]);
			}
			cov /= data_num;
			//write-back
			covar[i][k] = cov;
		}
	}
	//copy
	for(int i = 0; i != feature_num; ++i) {
		for(int j = 0; j != i; ++j) {
			covar[i][j] = covar[j][i];
		}
	}
	return ;
}

void PCA(matrix origin) {
	subtract_average(origin);
	covar_calc(origin);
	return ;
}
