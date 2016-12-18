#include "k_means.h"

int cluster[2 * 20] = {};
int prev_result[2 * 20] = {};
double center[2][RESERVED];
double dist_matrix[20][20];
double max_dist = 0;
int max_dist_pt[2] = {};

double dist_calc(int a, int b) {
	double distance = 0;
	for(int i = 0; i != RESERVED; ++i) {
		int t = (final_untransposed[a][i] - final_untransposed[b][i]) *
			(final_untransposed[a][i] - final_untransposed[b][i]);
		if(max_dist < t) {
			max_dist = t;
			max_dist_pt[0] = a;
			max_dist_pt[1] = b;
		}
	}
	return sqrt(distance);
}

double dist(int centernum, int a) {
	double distance = 0;
	for(int i = 0; i != RESERVED; ++i) {
		distance += (center[centernum][i] - final_untransposed[a][i]) *
			(center[centernum][i] - final_untransposed[a][i]);
	}
	return distance;
}

bool e(int *a, int *b) {
	for(int i = 0; i != data_num; ++i) {
		if(a[i] != b[i])
			return false;
	}
	return true;
}
void k_means() {
	//original data in final_untransposed
	for(int i = 0; i != data_num; ++i) {
		for(int j = 0; j != data_num; ++j) {
			dist_matrix[j][i] = 
				dist_matrix[i][j] = dist_calc(i, j);
		}
	}
	//initialize center
	for(int i = 0; i != RESERVED; ++i) {
		center[0][i] = final_untransposed[max_dist_pt[0]][i];
		center[1][i] = final_untransposed[max_dist_pt[1]][i];
	}

	//k_means iteration
	cluster[0] = 1;
	bool already_conv = false;
	while(!e(cluster, prev_result) || !already_conv) {
		//while loop enterred.
		if(e(cluster, prev_result))
				already_conv = true;
		for(int i = 0; i != data_num; ++i)
			prev_result[i] = cluster[i];
		for(int i = 0; i != data_num; ++i) {
			if(dist(0, i) <= dist(1, i))
				cluster[i] = 0;
			else cluster[i] = 1;
		}
		for(int i = 0; i != 2; ++i) {
			for(int j = 0; j != RESERVED; ++j) {
				center[i][j] = 0;
			}
		}
		//generating new center!
		int cnt[0] = {};
		for(int i = 0; i != RESERVED; ++i) {
			for(int j = 0; j != data_num; ++j) {
				center[cluster[j]][i] += final_untransposed[j][i];
				++cnt[cluster[j]];
			}
		}
		for(int i = 0; i != RESERVED; ++i) {
			center[0][i] /= cnt[0];
			center[1][i] /= cnt[1];
		}
	}
}
