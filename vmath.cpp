#include<vector>
#include "vmath.h"

std::vector<std::vector<long double>>  Vmath::dot(std::vector<std::vector<long double>> &a, std::vector<std::vector<long double>> &b){
	std::vector<std::vector<long double>> pr;
	if(a[0].size() == b.size()){
		int r = a.size(), c = b[0].size();
		for(int i = 0; i < r; i++){
			std::vector<long double> row;
			for(int j = 0; j < c; j++){
				long double sum = 0;
				for(int k = 0; k < a[0].size(); k++)
					sum += a[i][k] * b[k][j];
				row.push_back(sum);
			}
			pr.push_back(row);
		}
		return pr;
	}
	return pr;
}

void Vmath::transpose(std::vector<std::vector<long double>> &A,std::vector<std::vector<long double>> &T){
	int r = A.size(),c = A[0].size();
	for(int j = 0; j < c; j++){
		std::vector<long double> t;
		for(int i = 0; i < r; i++)
			t.push_back(A[i][j]);
		T.push_back(t);
	}
}

void Vmath::multiply(std::vector<std::vector<long double>> &a,std::vector<std::vector<long double>> &b,std::vector<std::vector<long double>> &re){
	int r = a.size(), c = a[0].size();
	for(int i = 0; i < r; i++){
		std::vector<long double> t;
		for(int j = 0; j < c; j++)
			t.push_back(a[i][j]*b[i][j]);
		re.push_back(t);
	}
}

void Vmath::power(std::vector<std::vector<long double>> &A, int n){
	int r = A.size();
	int c = A[0].size();
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			A[i][j] = A[i][j]*A[i][j];
	}
}

void Vmath::rowSum(std::vector<std::vector<long double>> &A,std::vector<std::vector<long double>> &b,int m){
	int r = A.size(), c = A[0].size();
	std::vector<long double> t;
	for(int i = 0; i < r; i++){
		long double sum = 0;
		for(int j = 0; j < c; j++)
			sum += A[i][j];
		t.push_back(sum/m);
	}
	b.push_back(t);
}
