#include<iostream>
#include<vector>
#include<string>
#include "dataset.h"
#include "initializeParameters.h"
#include "forwardPropagation.h"
#include<iomanip>
#include "computeCast.h"
#include "backwardPropagation.h"
#include "updateParameter.h"
#define W  15

using namespace std;


int main(int argc, char *argv[]){

		//final model
		int noOfIteration = 20000;
		long double cost,alpha = 1.2;
		std::vector<long double> label;
		std::vector<int> layers = {2,4,1};
		std::vector<std::vector<long double>> Xdata,bias = {{0,0,0,0},{0}},yhat;
		std::vector<std::vector<std::vector<long double>>> parameters = {{
				{-0.00416758, -0.00056267},
       			{-0.02136196,  0.01640271},
       			{-0.01793436, -0.00841747},
       			{ 0.00502881, -0.01245288}},
       			{{-0.01057952, -0.00909008,  0.00551454,  0.02292208}}},gradients,cache,result;
       	if(argc==3){
			sscanf(argv[1],"%d",&noOfIteration);
			alpha = stod(argv[2]);
		}
		Xdata = Data::loadX();
		label = Data::loadY();
		//InitializeParameter::initialize_parameters(layers,parameters);
		//InitializeParameter::initialize_bias(layers,bias);
		for(int i = 0; i < noOfIteration; i++){
			ForwardPropagation::forwardpropagate(cache,Xdata,parameters,bias);
			std::vector<std::vector<long double>> A2 = cache.back();
			ComputeCast::computecast(A2,label, &cost);
			BackwardPropagation::backpropagate(parameters,bias,cache,Xdata,label,gradients);
			UpdateParameter::updateparameter(parameters,gradients,bias,alpha);
			//if(i%1000==0){
				std::cout<<"Cost  "<<right<<setw(6)<<i<<": "<<right<<setw(W)<<cost<<std::endl;
			//}
			cache.clear();
			gradients.clear();
		}
		cout<<endl<<"W1"<<endl;
		for(auto x:parameters[0]){
			for(auto z:x)
				cout<<right<<setw(W)<<z;
			cout<<endl;
		}
		cout<<endl<<"B1"<<endl;
		for(auto x:bias[0]){
			cout<<right<<setw(W)<<x;
		}
		cout<<endl;
		cout<<endl<<"W2"<<endl;
		for(auto x:parameters[1]){
			for(auto z:x)
				cout<<right<<setw(W)<<z;
			cout<<endl;
		}
		cout<<endl<<"B2"<<endl;
		for(auto x:bias[1]){
			cout<<right<<setw(W)<<x;
		}
		ForwardPropagation::forwardpropagate(result,Xdata,parameters,bias);
		yhat = result.back();
		std::vector<int> pred;
		for(int i = 0; i < label.size(); i++){
			if(yhat[0][i]>0.5)
				pred.push_back(1);
			else
				pred.push_back(0);	
		}
		int correct = 0, wrong = 0;
		for(int i = 0; i < label.size(); i++){
			if(pred[i]==label[i])
				++correct;
			else
				++wrong;
		}
		long double accuracy = (long double)correct/label.size();
		accuracy *= 100;
		cout<<"Accuracy :" << accuracy <<" %"<<endl;
}







