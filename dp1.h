#pragma once

#include <iostream>
#include <map>

// TC: �� ����� ���� 2^n
// SC: ����

int64_t Fibonacci(int n)
{
	if(n<=2)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//Optimize - �ߺ���� ����
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

// m x n ũ���� �簢�� ������ �־����� ��, �»�ܿ��� ����Ͽ� ���ϴ�����
// �̵��ϴ� ����� ���� ���ϼ���. ��, �̵������� ������ Ȥ�� �Ʒ������θ� �̵� ����
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