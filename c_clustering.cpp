#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include "pca.h"
#include "k_means.h"
using namespace std;
int data_num = 0;
double input_matrix[20][feature_num];
int main()
{
	if(!freopen("input.txt", "r", stdin)) {
		cerr<<"Bad file location."<<endl;
		cerr<<"Open failed."<<endl;
		cerr<<"Exiting...."<<endl;
	}
	/*
	 *for(int i = 0; i != feature_num; ++i) {
	 *    for(int j = 0; j != data_num; ++j) {
	 *        cin>>input_matrix[j][i];
	 *    }
	 *}
	 */
	string line;
	int i = 0;
	while(getline(cin, line)) {
		istringstream is(line);
		for(int j = 0; j != feature_num; ++j) {
			is>>input_matrix[i][j];
		}
		++i;
	}

	//pca
	cout<<"pca starting..."<<endl;
	PCA(input_matrix);
	//Now PCAed data was stored in final_untransposed[data_num][RESERVED]
	k_means();

	cout<<"k_means finished."<<endl;
	int grp[2][20];
	int g[2] ={};
	fstream fs("out.txt", fstream::out);
	for(int i = 0; i != data_num; ++i) {
		grp[cluster[i]][g[cluster[i]]++] = i;
	}
	for(int i = 0; i != 2; ++i) {
		cout<<"group #"<<i<<":";
		fs<<"group #"<<i<<":";
		for(int j = 0; j != g[i]; ++j) {
			cout<<grp[i][j]<<' ';
			fs<<grp[i][j]<<' ';
		}
		cout<<endl;
		fs<<endl;
	}
	fs.close();
	return 0;
}
