class Vmath{
	public:
	static std::vector<std::vector<long double>> dot(std::vector<std::vector<long double>> &a, std::vector<std::vector<long double>> &b);
	static void transpose(std::vector<std::vector<long double>> &A,std::vector<std::vector<long double>> &T);
	static void power(std::vector<std::vector<long double>> &A, int n);
	static void rowSum(std::vector<std::vector<long double>> &A,std::vector<std::vector<long double>> &b,int m);
	static void multiply(std::vector<std::vector<long double>> &a,std::vector<std::vector<long double>> &b,std::vector<std::vector<long double>> &r);
};
