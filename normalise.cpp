#include<math.h>
#include<vector>
#include "normalise.h"

void Normalise::normalise(long double s){
	
}

void Normalise::normalise(std::vector<long double> &s){
	long double sum = 0;
	int r = s.size();
	for(int i = 0; i < r; i++)
		sum += (s[i]*s[i]);
	sum = sqrt(sum);
	for(int i = 0; i < r; i++)
		s[i] = (long double)s[i]/sum;
}

void Normalise::normalise(std::vector<std::vector<long double>> &s){
	long double sum;
	int r = s.size(), c = s[0].size();
	for(int i = 0; i < r; i++){
		sum = 0;
		for(int j = 0; j < c; j++)
			sum += (s[i][j]*s[i][j]);
		sum = sqrt(sum);
		for(int j = 0; j < c; j++)
			s[i][j] = s[i][j]/sum;
	}
}
