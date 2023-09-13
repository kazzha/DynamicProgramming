#pragma once

// memoization 심화

#include <vector>
#include <map>
#include <memory>

// Brute Force
// TC: m-sum이고 n이 numbers의 크기일때 O( n ^ m ) ( 1이면 sum이 8일때 8번 수행)
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
			return true; // 하나라도 참이면 멈춤. 빨라짐
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
			return true; // 하나라도 참이면 멈춤. 빨라짐
		}
	}

	memo[sum] = false;
	return false;
}

//Memorization
// TC: O( m * n )
// SC:O( m ^ 2),
//    O( m ) - 입출력을 복잡도에서 제외

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
		
		return std::make_shared<std::vector<int>>(); // {} (정답)
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


// 최소의 크기

