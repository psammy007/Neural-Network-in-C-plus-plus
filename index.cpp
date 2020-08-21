#include<iostream>
#include<vector>
#include "sigmoid.h"

using namespace std;

int main(){
	//vector<vector<long double>> v= {{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
	vector<vector<long double>> v = {{1,2,3},{1,2,3}};
	cout.precision(20);
	v = Sigmoid::sigmoidDerivative(v);
	for(auto y: v){
		for(auto x:y)
			cout<<x<<endl;
		cout<<endl;
	}
	vector<vector<int>> v = {{1,2,3},{4,5,6}};
	int arr[6];
	arr = &(v[0]);
	for(int i = 0; i < 6; i++)
		cout<<arr[i] << " ";
	cout<<endl;
}
