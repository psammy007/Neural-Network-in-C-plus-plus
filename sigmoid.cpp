#include<bits/stdc++.h>
#include "sigmoid.h"

long double Sigmoid::sigmoid(long double s){
		s = (long double)1/(1+exp(-s));
		return s;
}

std::vector<long double> Sigmoid::sigmoid(std::vector<long double> s){
	int l = s.size();
	for(int i = 0; i < l; i++)
		s[i] = (long double)1/(1+exp(-s[i]));
	return s;
}

std::vector<std::vector<long double>> Sigmoid::sigmoid(std::vector<std::vector<long double>> s){
	int r = s.size();
	for(int i = 0; i < r; i++){
		int c = s[i].size();
		for(int j = 0; j < c; j++)
			s[i][j] = (long double)1/(1+exp(-s[i][j]));
	}
	return s;
}


long double Sigmoid::sigmoidDerivative(long double s){
		s = sigmoid(s);
		long double ds = s * (1 - s);
		return s;
}

std::vector<long double> Sigmoid::sigmoidDerivative(std::vector<long double> s){
	s = sigmoid(s);
	int l = s.size();
	for(int i = 0; i < l; i++)
		s[i] = s[i] * (1 - s[i]);
	return s;
}

std::vector<std::vector<long double>> Sigmoid::sigmoidDerivative(std::vector<std::vector<long double>> s){
	s = sigmoid(s);
	int r = s.size();
	for(int i = 0; i < r; i++){
		int c = s[i].size();
		for(int j = 0; j < c; j++)
			s[i][j] = s[i][j] * (1 - s[i][j]);
	}
	return s;
}

