#include<vector>
#include<bits/stdc++.h>
#include "computeCast.h"

void ComputeCast::computecast(std::vector<std::vector<long double>> &A2,std::vector<long double> &Y,long double *cost){
	std::vector<long double> t,u;
	for(auto x:A2){
		for(auto y:x){
			t.push_back(log(y));
			u.push_back(log(1-y));
		}
	}
	int size = Y.size();
	long double c = 0;
	for(int i = 0; i < size; i++){
		c += (Y[i]*t[i])+((1-Y[i])*(u[i]));
	}
	*cost = (long double)((-1)*c)/size;
}
