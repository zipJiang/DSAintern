#include<iostream>
#include<cstdio>
#include "pca.h"
using namespace std;
double input_matrix[10][2016];
int main()
{
	if(!freopen("input.txt", "r", stdin)) {
		cerr<<"Bad file location."<<endl;
		cerr<<"Open failed."<<endl;
		cerr<<"Exiting...."<<endl;
	}
	for(int i = 0; i != 2016; ++i) {
		for(int j = 0; j != 10; ++j) {
			cin>>input_matrix[j][i];
		}
	}

	PCA(input_matrix);
	//Reading Test.
	for(int i = 0; i != 2016; ++i) {
		for(int j = 0; j != 10; ++j) {
			cout<<input_matrix[j][i]<<' ';
		}
		cout<<endl;
	}
	
	//pca
	return 0;
}
