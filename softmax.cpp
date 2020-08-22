#include<vector>
#include<bits/stdc++.h>
#include "softmax.h"

void Softmax::softmax(long double *s){
	*s = 1;
}

void Softmax::softmax(std::vector<long double> &s){
	long double sum = 0;
	int size = s.size();
	for(int i = 0; i < size; i++)
		sum += exp(s[i]);
	for(int i = 0; i < size; i++)
		s[i] = exp(s[i])/sum;
}

void Softmax::softmax(std::vector<std::vector<long double>> &s){
	int r = s.size();
	for(int i = 0; i < r; i++)
		softmax(s[i]);
}
