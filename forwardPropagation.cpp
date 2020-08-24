#include<vector>
#include "forwardPropagation.h"
#include "vmath.h"
#include "tanh.h"
#include "sigmoid.h"
#include<iostream>

void ForwardPropagation::forwardpropagate(std::vector<std::vector<std::vector<long double>>> &res,std::vector<std::vector<long double>> &X,std::vector<std::vector<std::vector<long double>>> &par,std::vector<std::vector<long double>> &b){
	std::vector<std::vector<long double>> Z1,A1,Z2,A2;
	std::vector<long double> b1 = b[0], b2 = b[1];
	Z1 = Vmath::dot(par[0],X);
	int r = Z1.size();
	int c = Z1[0].size();
	/*std::cout<<Z1.size()<<" "<<b1.size()<<std::endl;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			Z1[i][j] += b1[i];
	}*/
	res.push_back(Z1);
	Tanh::tanh(Z1);
	res.push_back(Z1);
	Z2 = Vmath::dot(par[1],Z1);
	r = Z2.size();
	c = Z2[0].size();
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			Z2[i][j] += b2[i];
	}
	res.push_back(Z2);
	Sigmoid::sigmoid(Z2);
	res.push_back(Z2);
}
