#pragma once

#include <iostream>
#include <map>

// TC: 총 노드의 개수 2^n
// SC: 높이

int64_t Fibonacci(int n)
{
	if(n<=2)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//Optimize - 중복계산 제거
// TC-O(n) SC-O(n)

int64_t Fibonacci_memo(int n, std::map<int, int64_t>& memo)
{
	if (memo.count(n) == 1)
	{
		return memo[n];
	}

	if (n <= 2)
	{
		return 1;
	}

	memo[n]= Fibonacci_memo(n - 1, memo) + Fibonacci_memo(n - 2,memo);
	return memo[n];
}

// m x n 크기의 사각형 영역이 주어졌을 때, 좌상단에서 출발하여 우하단으로
// 이동하는 경우의 수를 구하세요. 단, 이동방향은 오른쪽 혹은 아래쪽으로만 이동 가능
// TC: O(2^(m+n))
// SC: O(m+n)

int FindWay(int m, int n)
{
	if (m == 1 && n == 1)
	{
		return 1;
	}
	if (m == 0 || n == 0)
	{
		return 0;
	}

	return FindWay(m - 1, n) + FindWay(n - 1, m);
}