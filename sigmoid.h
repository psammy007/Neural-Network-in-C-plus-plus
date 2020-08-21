class Sigmoid{
	public:
	static long double sigmoid(long double s);
	static std::vector<long double> sigmoid(std::vector<long double> s);
	static std::vector<std::vector<long double>> sigmoid(std::vector<std::vector<long double>> s);
	
	static long double sigmoidDerivative(long double s);
	static std::vector<long double> sigmoidDerivative(std::vector<long double> s);
	static std::vector<std::vector<long double>> sigmoidDerivative(std::vector<std::vector<long double>> s);
};
