#include<vector>
#include<iostream>
#include "updateParameter.h"

void UpdateParameter::updateparameter(std::vector<std::vector<std::vector<long double>>> &par,std::vector<std::vector<std::vector<long double>>> &grad, std::vector<std::vector<long double>> &bias, long double alpha){
	int r = par[0].size(), c = par[0][0].size();
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			par[0][i][j] -= (alpha*grad[0][i][j]);
	}
	//std::cout<<"w1 done"<<std::endl;
	r = par[1].size();
	c = par[1][0].size();
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			par[1][i][j] -= (alpha*grad[2][i][j]);
	}
	/*std::cout<<"w2 done"<<std::endl;
	std::cout<<bias.size()<<","<<bias[0].size()<<std::endl;
	std::cout<<grad[1].size()<<","<<grad[1][0].size()<<std::endl;*/
	r = bias[0].size();
	for(int i = 0; i < r; i++){
		//std::cout<<bias[0][i]<<" "<<grad[1][0][i]<<std::endl;
		bias[0][i] -= (alpha*grad[1][0][i]);
	}
	//std::cout<<"b1 done"<<std::endl;
	r = bias[1].size();
	for(int i = 0; i < r; i++){
		bias[1][i] -= (alpha*grad[3][0][i]);
	}
	//std::cout<<"b2 done"<<std::endl;
}
