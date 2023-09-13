#pragma once

// memoization ��ȭ

#include <vector>
#include <map>
#include <memory>

// Brute Force
// TC: m-sum�̰� n�� numbers�� ũ���϶� O( n ^ m ) ( 1�̸� sum�� 8�϶� 8�� ����)
// SC: O( m )

bool CanAccumulate(const std::vector<int>& numbers, int sum)
{
	//base case
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	//recursive
	for (auto e : numbers)
	{
	    
		if(CanAccumulate(numbers, sum - e));
		{
			return true; // �ϳ��� ���̸� ����. ������
		}
	}

	return false;
}

// Memoization

bool CanAccumulate(const std::vector<int>& numbers, int sum, std::map<int, bool>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}

	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	
	//recursive
	for (auto e : numbers)
	{
		if (CanAccumulate(numbers, sum - e, memo))
		{
			memo[sum] = true;
			return true; // �ϳ��� ���̸� ����. ������
		}
	}

	memo[sum] = false;
	return false;
}

//Memorization
// TC: O( m * n )
// SC:O( m ^ 2),
//    O( m ) - ������� ���⵵���� ����

using result = std::shared_ptr<std::vector<int>>;

result HowAccumulate(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
{
	if (memo.count(sum) == 1)
	{
		return memo[sum];
	}

	// base case
	if (sum == 0)
	{
		
		return std::make_shared<std::vector<int>>(); // {} (����)
	}
	if (sum < 0)
	{
		return nullptr;
	}

	// recursive case;
	for (const auto e : numbers)
	{
		auto r = HowAccumulate(numbers, sum - e, memo);
		if (r != nullptr)
		{
			r->push_back(e);
			memo[sum] = r;
			return r;
		}
	}

	memo[sum] = nullptr;
	return memo[sum];
}


// �ּ��� ũ��

