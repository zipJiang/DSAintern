#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
double data[10][2016];
double center_1[2016];
double center_2[2016];
int result[10] = {};
int prev_result[10] = {};
bool e(int *a, int *b) {
	bool flag = true;
	for(int i = 0; i != 10; ++i) {
		if(a[i] != b[i])
			flag = false;
	}
	return flag;
}
double dist(int no, double *center) {
	double distance = 0;
	for(int i = 0; i != 2016; ++i) {
		distance += (data[no][i] - center[i]) * (data[no][i] - center[i]);
	}
	distance = sqrt(distance);
	return distance;
}
void calc_center() {
	int g_count[2] = {0, 0};
	memset(center_1, 0, sizeof(center_1));
	memset(center_2, 0, sizeof(center_2));
	for(int i = 0; i != 10; ++i) {
		++g_count[result[i] - 1];
		switch(result[i]) {
			case 1:
				for(int j = 0; j != 2016; ++j) {
					center_1[j] += data[i][j];
				}
				break;
			case 2:
				for(int j = 0; j != 2016; ++j) {
					center_2[j] += data[i][j];
				}
				break;
		}
	}
	for(int i = 0; i != 2016; ++i) {
		center_1[i] /= g_count[0];
		center_2[i] /= g_count[1];
	}
	return ;
}
int main()
{
	freopen("input.txt", "r", stdin);
	for(int i = 0; i != 2016; ++i) {
		for(int j = 0; j != 10; ++j) {
			cin>>data[j][i];
		}
	}
	//preprocessing
	for(int i = 0; i != 10; ++i) {
		double temp = 0;
		for(int j = 0; j != 2016; ++j) {
			temp += data[i][j];
		}
		temp /= 2016;
		for(int j = 0; j != 2016; ++j) {
			data[i][j] -= temp;
		}
	}
	for(int i = 0; i != 2016; ++i) {
		center_1[i] = data[0][i];
		center_2[i] = data[1][i];
	}
	//initialization
	for(int i = 0; i != 10; ++i) {
		if(dist(i, center_1) <= dist(i, center_2))
			result[i] = 1;
		else result[i] = 2;
	}
	while(!e(result, prev_result)) {
		for(int i = 0; i != 10; ++i)
			prev_result[i] = result[i];
		calc_center();
		for(int i = 0; i != 10; ++i) {
			if(dist(i, center_1) <= dist(i, center_2))
				result[i] = 1;
			else result[i] = 2;
		}
	}

	for(int i = 0; i != 10; ++i)
		cout<<result[i]<<' ';
	cout<<endl;
	return 0;
}
