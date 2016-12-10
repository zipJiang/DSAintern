//This is a trail clustering algorithm
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
double data[700][2016];
double d[700][700];
double mind[700];
int density[700] = {};
int group[700] = {};
int center_1 = -1;
int center_2 = -1;
int N = 0;

double dist(int a, int b) {
	double dis = 0;
	for(int i = 0; i != 2016; ++i) {
		dis += (data[a][i] - data[b][i]) * (data[a][i] - data[b][i]);
	}
	dis = sqrt(dis);
	cout<<"distance from:"<<a<<"to"<<b<<" is "<<dis<<endl;
	return dis;
}
double r_determiner(double m) {
	double left = 0;
	double right = m;
	double mid = (left + right) / 2;
	double ave = 0;
	while((ave < 3 || ave > double(N) / 35) && ((mid - left) > 0.001)) {
		cout<<"left = "<<left<<" "<<"right = "<<right<<" "<<"ad = "<<ave<<endl;
		memset(density, 0, N * sizeof(int));
		for(int i = 0; i != N; ++i) {
			for(int j = 0; j != N; ++j) {
				if(i == j)
					continue;
				if(d[i][j] < mid)
					++density[i];
			}
			ave += density[i];
		}
		ave /= N;
		if(ave < 3)
			left = mid;
		else if(ave > double(N) / 35)
			right = mid;
		mid = (left + right) / 2;
	}
	cout<<"left = "<<left<<" "<<"right = "<<right<<" "<<"ad = "<<ave<<endl;
	return mid;
}

void cluster(int no) {
	if(group[no] == center_1 || group[no] == center_2)
		return ;
	cluster(group[no]);
	group[no] = group[group[no]];
	return ;
}
int main()
{
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	string in;
	//data input
	for(int i = 0; i != 2016; ++i) {
		getline(cin, in);
		istringstream is(in);
		double t = 0;
		int number = 0;
		while(is>>t) {
			data[number++][i] = t;
		}
		N = number;

		//amplify data with disturbance.
		for(int k = N; k != 25 * N; ++k) {
			data[k][i] = data[k % N][i] + rand() % 101 - 50;
		}
	}
	N *= 25;
	//Normalization
	for(int i = 0; i != N; ++i) {
		double a = 0;
		for(int j = 0; j != 2016; ++j) {
			a += data[i][j];
		}
		a /= N;
		for(int j = 0; j != 2016; ++j) {
			data[i][j] -= a;
		}
	}
	double max_dist = 0;
	//calculate d matrix
	for(int i = 0; i != N; ++i) {
		for(int j = i; j != N; ++j) {
			d[i][j] = dist(i, j);
			d[j][i] = d[i][j];
			if(d[i][j] > max_dist)
				max_dist = d[i][j];
		}
	}
	//also density array is set during the procession.
	double radix = r_determiner(max_dist);
	double max_minimum = 0;
	//cout<<"density is set."<<endl;
	for(int i = 0; i != N; ++i) {
		int minimum = max_dist;
		for(int j = 0; j != N; ++j) {
			if(j == i)
				continue;
			if(density[j] <= density[i])
				continue;
			if(d[i][j] < minimum) {
				minimum = d[i][j];
				group[i] = j;
			}
		}
		mind[i] = minimum;
		if(minimum > max_minimum)
			max_minimum = minimum;
	}
	for(int i = 0; i != N; ++i) {
		if(mind[i])
			continue;
		mind[i] = max_minimum;
	}

	//First Version: write to output.txt for matplotlib to plot a graph testing.
	//fstream fs;
	//fs.open("output.txt", ios::out);
	//for(int i = 0; i != N; ++i) {
		//fs<<density[i]<<' '<<mind[i]<<endl;
	//}
	
	//Second Version: set centers.
	int max_density = 0;
	int max_density_no = 0;
	for(int i = 0; i != N; ++i) {
		if(max_density < density[i]) {
			max_density = density[i];
			max_density_no = i;
		}
	}
	center_1 = max_density_no;
	int second_no = 0;
	int max_product = 0;
	for(int i = 0; i != N; ++i) {
		if(center_1 == i)
			continue;
		int p = density[i] / (double)density[center_1] * mind[i] / mind[center_1];
		if(p > max_product) {
			max_product = p;
			second_no = i;
		}
		
	}
	center_2 = second_no;
	
	//clustering
	for(int i = 0; i != N; ++i) {
		if(group[i] == center_1 || group[i] == center_2) {
			continue;
		}
		cluster(i);
	}

	//output
	for(int i = 0; i < N / 25; ++i) {
		cout<<group[i]<<' ';
	}
	cout<<endl;
	return 0;
}
