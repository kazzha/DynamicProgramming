#include <iostream>
#include <vector>
#include "dp1.h"
#include "dp2.h"

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

//TC: O(n)
//SC: O(n)

int f(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	return f(n - 1);
}

int main()
{
	//map<int, int64_t> memo;
	//cout << Fibonacci_memo(50,memo) << endl;

	//cout << FindWay(2, 3) << endl;

	
	std::vector<int> number = { 2,3,5 };
	int sum1 = 8;

	std::vector<int> number2 = { 3, 5 };
	int sum2 = 7;
	/*
	std::cout << std::boolalpha;
	std::cout << CanAccumulate(number, sum1);

	std::map<int, bool> memo;

	std::cout << CanAccumulate(number, sum1, memo);

	memo.clear();

	std::cout << CanAccumulate(number2, sum2, memo);
	*/

	std::map<int, result> memo;
	std::cout << HowAccumulate(number, sum1, memo).get() << std::endl;

	memo.clear();

	std::cout << HowAccumulate(number2, sum2, memo).get() << std::endl;

	

}