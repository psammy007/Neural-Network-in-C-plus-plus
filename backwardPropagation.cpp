#include<vector>
#include<iostream>
#include "vmath.h"
#include "backwardPropagation.h"

void BackwardPropagation::backpropagate(std::vector<std::vector<std::vector<long double>>> &par,std::vector<std::vector<long double>> &b,std::vector<std::vector<std::vector<long double>>> &res,std::vector<std::vector<long double>> &X, std::vector<long double> &Y,std::vector<std::vector<std::vector<long double>>> &grad){
	std::vector<std::vector<long double>> w1 = par[0], w2 = par[1],dw1,dw2,XT,w2t,dz2,dz1,db1,db2;
	std::vector<std::vector<long double>> A1 = res[1], A2 = res[3],A1T,A2T,temp1,temp2,temp3;
	std::vector<long double> temp;
	int size = A2[0].size(),m = X[0].size();
	for(int i = 0; i < size; i++)
		temp.push_back(A2[0][i]-Y[i]);
	dz2.push_back(temp);
	temp.clear();
	/*std::cout<<"dz2"<<std::endl;
	for(auto x:dz2){
		for(auto y:x)
			std::cout<<y<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;*/
	Vmath::transpose(A1,A1T);
	dw2 = Vmath::dot(dz2,A1T);
	int r = dw2.size(), c = dw2[0].size();
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			dw2[i][j] /= m;
	}
	/*std::cout<<"dw2"<<std::endl;
	for(auto x:dw2){
		for(auto y:x)
			std::cout<<y<<" ";
		std::cout<<std::endl;
	}*/
	Vmath::rowSum(dz2,db2,m);
	/*std::cout<<"db2"<<std::endl;
	for(auto x:db2){
		for(auto y:x)
			std::cout<<y<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<std::endl;*/
	Vmath::transpose(w2,w2t);
	temp1 = Vmath::dot(w2t,dz2);
	r = A1.size();
	c = A1[0].size();
	Vmath::power(A1,2);
	for(int i = 0; i < r; i++){
		std::vector<long double> f;
		for(int j = 0; j < c; j++){
			f.push_back(1-A1[i][j]);
		}
		temp2.push_back(f);
	}
	Vmath::multiply(temp1,temp2,dz1);
	/*std::cout<<"dz1"<<std::endl;
	for(auto x:dz1){
		for(auto y:x)
			std::cout<<y<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;*/
	Vmath::transpose(X,XT);
	dw1 = Vmath::dot(dz1,XT);
	r = dw1.size();
	c = dw1[0].size();
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			dw1[i][j] /= m;
	}
	/*std::cout<<"dw1"<<std::endl;
	for(auto x:dw1){
		for(auto y:x)
			std::cout<<y<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;*/
	Vmath::rowSum(dz1,db1,m);
	/*std::cout<<"db1"<<std::endl;
	for(auto x:db1){
		for(auto y:x)
			std::cout<<y<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;*/
	grad.push_back(dw1);
	grad.push_back(db1);
	grad.push_back(dw2);
	grad.push_back(db2);
}

