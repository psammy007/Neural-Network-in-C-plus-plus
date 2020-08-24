#include<iostream>
#include<vector>
#include<string>
#include "loss.h"
#include "vmath.h"
#include "dataset.h"
#include "sigmoid.h"
#include "softmax.h"
#include "normalise.h"
#include <graphics.h> 
#include "initializeParameters.h"
#include "forwardPropagation.h"
#include "tanh.h"
#include<iomanip>
#include "computeCast.h"
#include "backwardPropagation.h"
#include "updateParameter.h"
#define W  15

using namespace std;

/*class Model{
	private:
	string name;
	int noOfIteration;
	long double cost,alpha;
	std::vector<std::vector<long double>> Xdata,bias;
	std::vector<long double> label;
	std::vector<int> layers;
	std::vector<std::vector<std::vector<long double>>> parameters,gradients,cache;
	public:
	Model(){}
	
	void setName(string name){
		this->name = name;
	}
	void setIterations(int iterations){
		this->noOfIteration = iterations;
	}
	
	void setAlpha(long double alpha){
		this->alpha = alpha;
	}
	
	void addLayers(std::vector<int> layers){
		for(auto layer:layers){
			this->layers.push_back(layer);
		}
	}
	
	void modelName(){
		std::cout<<this->name<<std::endl;
	}
	
	void loadDataset(){
		this->Xdata = Data::loadX();
		this->label = Data::loadY();
	}
	
	void initializeParameters(){
		std::cout<<"Initializing..."<<std::endl;
		InitializeParameter::initialize_parameters(this->layers,this->parameters);
		InitializeParameter::initialize_bias(this->layers,this->bias);
		cout<<this->parameters.size()<<endl;
	}
	
	void printParameters(){
	std::cout<<"Printing parameters"<<std::endl;
		for(auto x:this->parameters){
			for(auto y:x){
				for(auto z:y)
					std::cout<<std::left<<std::setw(15)<<z;
				std::cout<<std::endl;
			}
		}
	}
	
	void train(){
		for(int i = 0; i < this->noOfIteration; i++){
			ForwardPropagation::forwardpropagate(this->cache,this->Xdata,this->parameters,this->bias);
			std::vector<std::vector<long double>> A2 = this->cache.back();
			ComputeCast::computecast(A2,this->label, &(this->cost));
			BackwardPropagation::backpropagate(this->parameters,this->bias,this->cache,this->Xdata,this->label,this->gradients);
			UpdateParameter::updateparameter(this->parameters,this->gradients,this->alpha);
			if(i%1000==0){
				printParameters();
				std::cout<<"Cost  :"<<this->cost<<std::endl;
			}
		}
	}
};*/

int main(int argc, char *argv[]){
	int one;
	long double two = stod(argv[2]);
	sscanf(argv[1],"%d",&one);
	cout<<one<<","<<two<<endl;
	/*std::vector<std::vector<std::vector<long double>>> parameters,res;
	std::vector<std::vector<long double>> b;
	std::vector<int> l = {2,4,1};
	InitializeParameter::initialize_parameters(l,parameters);
	InitializeParameter::initialize_bias(l,b);
	cout<<"parameters"<<endl;
	for(auto x:parameters){
		for(auto y:x){
			for(auto z:y)
				cout<<std::left<<std::setw(W)<<z;
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<"bias"<<endl;
	for(auto x:b){
		for(auto y:x)
			cout<<std::left<<std::setw(W)<<y;
		cout<<endl;
	}
	cout<<endl;
	std::vector<std::vector<long double>> X = {{1,2,3},{4,5,6}};
	ForwardPropagation::forwardpropagate(res,X,parameters,b);
	for(auto x:res){
		for(auto y:x){
			for(auto z:y)
				cout<<std::left<<std::setw(W)<<z;
			cout<<endl;
		}
		cout<<endl;
	}
	std::vector<std::vector<long double>> d = res.back();
	for(auto x:d){
		for(auto y:x)
			cout<<std::left<<std::setw(W)<<y;
		cout<<endl;
	}*/
	//std::vector<std::vector<long double>> v = {{1,2,3},{4,5,6}};
	/*std::vector<long double> v = {1,2,3};
	Tanh::tanh(v);
	for(auto y:v){
		cout<<y<<" ";
	cout<<endl;
	}*/
	//std::vector<std::vector<long double>> A2 = {{0.5002307 ,  0.49985831,  0.50023963}},a1;
	/*std::vector<long double> Y = {1,0,0};
	long double cost;
	ComputeCast::computecast(A2,Y, &cost);
	cout.precision(16);
	cout<<"Cost:"<<cost<<endl;*/
	//Vmath::transpose(v,a1);
	/*for(auto x:a1){
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}*/
	
	
	//backwardPropagation testing
	/*std::vector<std::vector<std::vector<long double>>> grad,par = {{{-0.00416758, -0.00056267},{-0.02136196,  0.01640271},{-0.01793436, -0.00841747},{0.00502881, -0.01245288}},
	{{-0.01057952, -0.00909008,  0.00551454,  0.02292208}}};
	std::vector<std::vector<std::vector<long double>>> res = {{{-0.00616586,  0.0020626 ,  0.0034962 },{-0.05229879,  0.02726335, -0.02646869},{-0.02009991,  0.00368692,  0.02884556},{0.02153007, -0.01385322,  0.02600471}},{{-0.00616578,  0.0020626 ,  0.00349619},{-0.05225116,  0.02725659, -0.02646251},{-0.02009721,  0.0036869 ,  0.02883756},{0.02152675, -0.01385234,  0.02599885}},{{0.00092281, -0.00056678,  0.00095853}},{{0.5002307 ,  0.49985831,  0.50023963}}};
		std::vector<std::vector<long double>> x = {{1.62434536, -0.61175641, -0.52817175},{-1.07296862,  0.86540763, -2.3015387}};
		std::vector<std::vector<long double>> b = {{0,0,0,0},{0}};
		std::vector<long double> y = {1,0,1};
		BackwardPropagation::backpropagate(par,b,res,x,y,grad);
		for(auto x:grad){
			for(auto y:x){
				for(auto z:y)
					cout<<std::left<<std::setw(15)<<z;
				cout<<endl;
			}
			cout<<endl;
		}*/
		
		//parameter update test
		/*std::vector<std::vector<std::vector<long double>>> par = {{{-0.00615039,  0.0169021},
        {-0.02311792,  0.03137121},
        {-0.0169217 , -0.01752545},
        { 0.00935436, -0.05018221}},{{-0.0104319} , {-0.04019007},  {0.01607211},  {0.04440255}}},
        grad = {{{ 0.00023322, -0.00205423},
        { 0.00082222, -0.00700776},
        {-0.00031831,  0.0028636 },
        {-0.00092857,  0.00809933}},{{  1.05570087e-07,
         -3.81814487e-06,
         -1.90155145e-07,
          5.46467802e-07}},{{ -1.75740039e-05},   {3.70231337e-03},  {-1.25683095e-03},
          {-2.55715317e-03}},{{-1.08923140e-05}}};
        std::vector<std::vector<long double>> bias = {{-8.97523455e-07,
          8.15562092e-06,
          6.04810633e-07,
         -2.54560700e-06},{9.14954378e-05}};
		UpdateParameter::updateparameter(par,grad,bias,1.2);
		cout<<"w parameters"<<endl;
		for(auto x:par){
			for(auto y:x){
				for(auto z:y){
					cout<<z<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		cout<<"bias"<<endl;
		for(auto x:bias){
			for(auto y:x){
				cout<<y<<" ";
			}
			cout<<endl;
		}*/
		
		/*Model model;
		model.setName("Mark II");
		model.modelName();
		model.setAlpha(1.2);
		model.setIterations(10000);
		model.loadDataset();
		model.initializeParameters();
		model.printParameters();*/
		
		
		
		
		//final model
		int noOfIteration = 20000;
			sscanf(argv[1],"%d",&noOfIteration);
		long double cost,alpha = 1.2;
		alpha = stod(argv[2]);
		std::vector<std::vector<long double>> Xdata,bias = {{0,0,0,0},{0}},yhat;
		std::vector<long double> label;
		std::vector<int> layers = {2,4,1};
		std::vector<std::vector<std::vector<long double>>> parameters = {{{-0.00416758, -0.00056267},
       {-0.02136196,  0.01640271},
       {-0.01793436, -0.00841747},
       { 0.00502881, -0.01245288}},{{-0.01057952, -0.00909008,  0.00551454,  0.02292208}}},gradients,cache,result;
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
				std::cout<<"Cost  "<<right<<setw(6)<<i<<": "<<right<<setw(15)<<cost<<std::endl;
			//}
			/*for(auto x:gradients){
				for(auto y:x){
					for(auto z:y)
						cout<<z<<" ";
					cout<<endl;
				}
			}*/
			cache.clear();
			gradients.clear();
		}
		cout<<endl<<"W1"<<endl;
		for(auto x:parameters[0]){
			for(auto z:x)
				cout<<right<<setw(15)<<z;
			cout<<endl;
		}
		cout<<endl<<"B1"<<endl;
		for(auto x:bias[0]){
			cout<<right<<setw(15)<<x;
		}
		cout<<endl;
		cout<<endl<<"W2"<<endl;
		for(auto x:parameters[1]){
			for(auto z:x)
				cout<<right<<setw(15)<<z;
			cout<<endl;
		}
		cout<<endl<<"B2"<<endl;
		for(auto x:bias[1]){
			cout<<right<<setw(15)<<x;
		}
		ForwardPropagation::forwardpropagate(result,Xdata,parameters,bias);
		yhat = result.back();
		cout<<yhat.size()<<","<<yhat[0].size()<<endl;
		cout<<label.size()<<endl;
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







