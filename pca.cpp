/*
 * This is the pca.cpp file which instantiate pca related functions.
 */
#include "pca.h"

void subtract_average(matrix origin) {
	for(int i = 0; i != feature_num; ++i) {
		double ave = 0;
		for(int j = 0; j != data_num; ++j) {
			ave += origin[j][i];
		}
		ave /= data_num;
		for(int j = 0; j != data_num; ++j) {
			origin[j][i] -= ave;
		}
	}
	return ;
}
void PCA(matrix origin) {
	subtract_average(origin);
	return ;
}
