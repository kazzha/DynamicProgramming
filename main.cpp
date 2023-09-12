#include <iostream>
#include "dp1.h"

using namespace std;

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

	cout << FindWay(2, 3) << endl;
}