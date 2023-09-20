#include <iostream>
#include <vector>
#include "dp1.h"
#include "dp2.h"
#include "dp3.h"

//TC: O(n)
//SC: O(n)

using namespace std;
using string2d = std::list<std::list<std::string>>;

int f(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return f(n - 1);
}

std::ostream& operator << (std::ostream& os, std::vector<int>* v)
{
	if (v == nullptr)
	{
		std::cout << "nullptr";
	}
	else {
		std::cout << "{";
		for (int i = 0; i < v->size(); i++)
		{
			std::cout << (*v)[i];

			if (i < v->size() - 1)
			{
				std::cout << ",";
			}
		}

		std::cout << "}";
	}
	return os;
}

std::ostream& operator << (std::ostream& os, const string2d& v)
{
	std::cout << "{" << std::endl;
	int i{}, j{};

	for (auto e1 : v)
	{
		j = 0;
		std::cout << "    {";
		for (auto e2 : e1)
		{
			std::cout << e2;
			if (j < e1.size() - 1)
			{
				std::cout << ",";
			}
			j++;
		}
		std::cout << "}";

		if (i < v.size() - 1) {
			std::cout << ",";
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << "}" << std::endl;

	return os;
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
	
	
}
int main()
{
	using namespace tabulation;
	cout << Fibonacci(50) << endl;

	vector<int> numbers{ 2,3,5 };
	cout << boolalpha;
	cout << HowAccumulate(numbers, 8).get() << endl;
	
	cout << CanGenerate({ "ab","abc","cd","def","abcd" }, "aecdef") << endl;
	cout << AllGenerate({ "ab","abc","cd","def","abcd" ,"c","d","e" }, "abcdef") << endl;
}