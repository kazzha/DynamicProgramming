#pragma once

// dynamicProgramming ����

#include <iostream>
#include <map>
#include <string>

// TC: �� ����� ���� 2^n
// SC: ����

namespace dp_basic {
	int64_t Fibonacci(int n)
	{
		if (n <= 2)
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

		memo[n] = Fibonacci_memo(n - 1, memo) + Fibonacci_memo(n - 2, memo);
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

	// TC: O(n) / O(m * n)
	// SC: O(m+n)

	int FindWay(int m, int n, std::map<std::string, int>& memo)
	{
		std::string key = std::to_string(m) + "," + std::to_string(n);

		if (memo.count(key) == 1)
		{
			return memo[key];
		}

		std::string rkey = std::to_string(n) + "," + std::to_string(m);
		if (memo.count(rkey) == 1)
		{
			return memo[rkey];
		}

		if (m == 1 && n == 1)
		{
			return 1;
		}
		if (m == 0 || n == 0)
		{
			return 0;
		}
		memo[key] = FindWay(m - 1, n, memo) + FindWay(n - 1, m, memo);
		return memo[key];
	}
}
