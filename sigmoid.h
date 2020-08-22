class Sigmoid{
	public:
	static void sigmoid(long double *s);
	static void sigmoid(std::vector<long double> &s);
	static void sigmoid(std::vector<std::vector<long double>> &s);
	
	static void sigmoidDerivative(long double *s);
	static void sigmoidDerivative(std::vector<long double> &s);
	static void sigmoidDerivative(std::vector<std::vector<long double>> &s);
};
