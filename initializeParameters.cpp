#include<vector>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include "initializeParameters.h"

void InitializeParameter::initialize_parameters(std::vector<int> l, std::vector<std::vector<std::vector<long double>>> &v){
	srand(time(0));
	int size = l.size();
	for(int i = 1; i < size; i++){
		std::vector<std::vector<long double>> s;
		for(int j = 0; j < l[i]; j++){
			std::vector<long double> t;
			for(int k = 0; k < l[i-1]; k++){
				t.push_back((float(rand())* 0.01));
			}
			s.push_back(t);
		}
		v.push_back(s);
	}
}

void InitializeParameter::initialize_bias(std::vector<int> l,std::vector<std::vector<long double>> &v){
	srand(time(0));
	int size = l.size();
	for(int i = 1; i < size; i++){
		std::vector<long double> s;
		for(int j = 0; j < l[i]; j++)
			s.push_back((float(rand()) ));
		v.push_back(s);
	}
}


