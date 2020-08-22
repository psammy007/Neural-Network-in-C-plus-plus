#include<vector>
#include "tanh.h"
#include<bits/stdc++.h>

void Tanh::tanh(long double *s){
	long double t = (long double) (exp(*s) - exp(-(*s)))/(exp(*s) + exp(-(*s)));
	*s = t;
}

void Tanh::tanh(std::vector<long double> &s){
	int size = s.size();
	for(int i = 0; i < size; i++)
		s[i] = (long double) (exp(s[i]) - exp(-(s[i])))/(exp(s[i]) + exp(-(s[i])));
}

void Tanh::tanh(std::vector<std::vector<long double>> &s){
	int size = s.size();
	for(int i = 0; i < size ; i++){
		int r = s[i].size();
		for(int j = 0; j < r; j++){
			s[i][j] = (long double) (exp(s[i][j]) - exp(-(s[i][j])))/(exp(s[i][j]) + exp(-(s[i][j])));
		}
	}
		//tanh(s[i]);
}
