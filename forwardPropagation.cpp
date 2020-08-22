#include<vector>
#include "forwardPropagation.h"
#include "vmath.h"
#include "tanh.h"
#include "sigmoid.h"

void ForwardPropagation::forwardpropagate(std::vector<std::vector<std::vector<long double>>> &res,std::vector<std::vector<long double>> &X,std::vector<std::vector<std::vector<long double>>> &par){
	std::vector<std::vector<long double>> Z1,A1,Z2,A2;
	Z1 = Vmath::dot(par[0],X);
	res.push_back(Z1);
	Tanh::tanh(Z1);
	res.push_back(Z1);
	Z2 = Vmath::dot(par[1],Z1);
	res.push_back(Z2);
	Sigmoid::sigmoid(Z2);
	res.push_back(Z2);
}
