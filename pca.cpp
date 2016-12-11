/*
 * This is the pca.cpp file which instantiate pca related functions.
 */
#include "pca.h"

double average[feature_num];
double covar[feature_num * feature_num];
double eigenvector[feature_num][feature_num];
double final_untransposed[data_num][RESERVED];

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
	static creal_T V[feature_num * feature_num];
	static creal_T D[feature_num * feature_num];
	
	for(int i = 0; i != feature_num; ++i) {
		for(int k = i; k != feature_num; ++k) {
			double cov = 0;
			for(int j = 0; j != data_num; ++j) {
				cov += subtracted[j][i] * subtracted[j][k];
			}
			cov /= data_num;
			//write-back
			covar[i * feature_num + k] = cov;
		}
	}
	//copy
	for(int i = 0; i != feature_num; ++i) {
		for(int j = 0; j != i; ++j) {
			covar[i * feature_num + j] = covar[j * feature_num + i];
		}
	}
	//eigenvector decomposition
	std::cout<<"starting eignevector decomposition, calling matlab-generated function."<<std::endl;
	eigen(covar, V, D);
	std::cout<<"decomposition finished. back to normal control flow."<<std::endl;
	//START WORKING FROM HERE AFTERNOON, copy eignevector V back from the static array of typdef struct.
	for(int i = 0; i != feature_num; ++i) {
		for(int j = 0; j != feature_num; ++j) {
			if(j < RESERVED)
				eigenvector[i][j] = V[i * feature_num + j].re;
			else
				eigenvector[i][j] = 0;
		}
	}
	//Sort the vectors to get the largest eigenvalues.
	for(int i = 0; i != RESERVED; ++i) {
		for(int j = feature_num - 1; j != i; --j) {
			if(std::abs(D[j * feature_num + j].re) > std::abs(D[(j - 1) * feature_num + j - 1].re)) {
				//exchange j and j - 1. both in vectors and D
				double temp = D[j * feature_num + j].re;
				D[j * feature_num + j].re = D[(j - 1) * feature_num + j - 1].re;
				D[(j - 1) * feature_num + j - 1].re = temp;
				for(int k = 0; k != feature_num; ++k) {
					temp = eigenvector[k][j];
					eigenvector[k][j] = eigenvector[k][j - 1];
					eigenvector[k][j - 1] = temp;
				}
			}
		}
	}
	//multiplication
	for(int i = 0; i != data_num; ++i) {
		for(int j = 0; j != RESERVED; ++j) {
			for(int k = 0; k != feature_num; ++k) {
				final_untransposed[i][j] += subtracted[i][k] * eigenvector[k][j];
			}
		}
	}
}

void PCA(matrix origin) {
	subtract_average(origin);
	std::cout<<"normalization success, continuing...."<<std::endl;
	covar_calc(origin);
	std::cout<<"covar calculated successfully, pca terminating...."<<std::endl;
	return ;
}
