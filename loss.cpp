#include<vector>
#include "loss.h"

long double Loss::abs(std::vector<long double> &a, std::vector<long double> &b){
	long double error = 0,temp;
	int size = a.size();
	for(int i = 0; i < size; i++){
		temp = a[i] - b[i];
		error += (temp>0) ? temp:(temp * (-1));
	}
	return error;
}

long double Loss::sqrd(std::vector<long double> &a, std::vector<long double> &b){
	long double error = 0,temp;
	int size = a.size();
	for(int i = 0; i < size; i++){
		error += ((a[i] - b[i])*(a[i] - b[i]));
	}
	return error;
}
