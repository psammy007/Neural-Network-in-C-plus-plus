#include<bits/stdc++.h>
#include "sigmoid.h"

void Sigmoid::sigmoid(long double *s){
		*s = (long double)1/(1+exp(-(*s)));
}

void Sigmoid::sigmoid(std::vector<long double> &s){
	int l = s.size();
	for(int i = 0; i < l; i++)
		s[i] = (long double)1/(1+exp(-s[i]));
}

void Sigmoid::sigmoid(std::vector<std::vector<long double>> &s){
	int r = s.size();
	for(int i = 0; i < r; i++){
		int c = s[i].size();
		for(int j = 0; j < c; j++)
			s[i][j] = (long double)1/(1+exp(-s[i][j]));
	}
}


void Sigmoid::sigmoidDerivative(long double *s){
		sigmoid(s);
		*s = (*s) * (1 - (*s));
}

void Sigmoid::sigmoidDerivative(std::vector<long double> &s){
	sigmoid(s);
	int l = s.size();
	for(int i = 0; i < l; i++)
		s[i] = s[i] * (1 - s[i]);
}

void Sigmoid::sigmoidDerivative(std::vector<std::vector<long double>> &s){
	sigmoid(s);
	int r = s.size();
	for(int i = 0; i < r; i++){
		int c = s[i].size();
		for(int j = 0; j < c; j++)
			s[i][j] = s[i][j] * (1 - s[i][j]);
	}
}

