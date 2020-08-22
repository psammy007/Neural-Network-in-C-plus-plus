#include<vector>
#include<iostream>
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
	} else{
		std::cout<<"error"<<std::endl;
	}
	return pr;
}

/*void Vmath::add(std::vector<std::vector<long double>> &Z1,std::vector<long double> &b){
	int size = Z1.size();
	
}*/
