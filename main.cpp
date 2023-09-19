#include <iostream>
#include <vector>
#include "dp1.h"
#include "dp2.h"
#include "dp3.h"

//TC: O(n)
//SC: O(n)

using namespace std;

int f(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return f(n - 1);
}

void dp1()
{
	using namespace dp_basic;
	map<int, int64_t> memo;
	cout << Fibonacci_memo(50,memo) << endl;

	cout << FindWay(2, 3) << endl;
}

void dp2()
{
	using namespace memoizaion;
	std::vector<int> number = { 2,3,5 };
	int sum1 = 8;

	std::vector<int> number2 = { 3, 5 };
	int sum2 = 7;
	
	std::cout << std::boolalpha;
	std::cout << CanAccumulate(number, sum1);

	std::map<int, bool> memo2;

	std::cout << CanAccumulate(number, sum1, memo2);

	memo2.clear();

	std::cout << CanAccumulate(number2, sum2, memo2);
	

	
	std::map<int, result> memo3;
	std::cout << HowAccumulate(number, sum1, memo3).get() << std::endl;

	memo3.clear();

	std::cout << HowAccumulate(number2, sum2, memo3).get() << std::endl;

	memo3.clear();
	std::cout << OptimizeAccumulate(number, sum1, memo3).get() << std::endl;

	memo3.clear();
	std::cout << OptimizeAccumulate(number2, sum2, memo3).get() << std::endl;
	

	
	std::vector<std::string> strings = { "ab", "abc", "cd", "def", "abcd" };
	auto target = "abcdef";
	std::cout << std::boolalpha;
	std::cout << CanGenerate({ "ab", "abc", "cd", "def", "abcd" }, "abcdef") << std::endl;

	std::map<std::string, bool> memo4;
	std::cout << CanGenerate(strings, target, memo4) << std::endl;

	std::cout << HowManyGenerate(strings, target) << std::endl;

	std::map<std::string, int> memo5;
	std::cout << HowManyGenerate(strings, target, memo5) << std::endl;


	std::vector<std::string> string2 = { "ab", "abc", "cd", "def", "abcd","c","ef" };
	std::cout << AllCombination(string2, target) << std::endl;
	
}
int main()
{
	using namespace tabulation;
	cout << Fibonacci(50) << endl;
	
}