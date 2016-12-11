#include<iostream>
#include<cstdio>
#include "pca.h"
#include "k_means.h"
using namespace std;
double input_matrix[data_num][feature_num];
int main()
{
	if(!freopen("input.txt", "r", stdin)) {
		cerr<<"Bad file location."<<endl;
		cerr<<"Open failed."<<endl;
		cerr<<"Exiting...."<<endl;
	}
	for(int i = 0; i != feature_num; ++i) {
		for(int j = 0; j != data_num; ++j) {
			cin>>input_matrix[j][i];
		}
	}

	//pca
	cout<<"pca starting..."<<endl;
	PCA(input_matrix);
	//Now PCAed data was stored in final_untransposed[data_num][RESERVED]
	k_means();

	cout<<"k_means finished."<<endl;

	for(int i = 0; i != data_num; ++i) {
		cout<<cluster[i]<<' ';
	}
	cout<<endl;
	return 0;
}
