#pragma once

// memoization ��ȭ

#include <vector>
#include <map>
#include <memory>
#include <list>

namespace memoizaion {

	
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

			if (CanAccumulate(numbers, sum - e))
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
		return memo[sum];
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

	// TC: O( m * n )
	// std::copy �ð� ��� ( m^2 * n)
	// SC:O( m ^ 2),

	result OptimizeAccumulate(const std::vector<int>& numbers, int sum, std::map<int, result>& memo)
	{
		if (memo.count(sum) == 1)
		{
			return memo[sum];
		}
		//base case
		if (sum == 0)
		{
			return std::make_shared<std::vector<int>>();
		}
		if (sum < 0)
		{
			return nullptr;
		}

		// recursive case
		std::shared_ptr<std::vector<int>> optimized = nullptr;

		for (const auto e : numbers)
		{
			auto r = OptimizeAccumulate(numbers, sum - e, memo);

			if (r != nullptr)
			{
				std::shared_ptr<std::vector<int>> v = std::make_shared<std::vector<int>>();
				v->resize(r->size());
				std::copy(r->begin(), r->end(), v->begin());

				v->push_back(e);

				if (optimized == nullptr || v->size() < optimized->size())
				{
					optimized = v;
				}
			}
		}

		memo[sum] = optimized;
		return memo[sum];
	}

	//////////////////////////////////////////////////////////
	// Decision Problem - brute force
	// TC: O( m^2 * n )
	// SC:O( m ^ 2),
	bool CanGenerate(const std::vector<std::string>& strings, std::string target)
	{
		// base case
		if (target == "")
		{
			return true;
		}

		// recursive
		for (auto e : strings)
		{
			if (target.find(e) == 0)
			{
				auto subStr = target.substr(e.size());
				if (CanGenerate(strings, subStr))
				{
					return true;
				}
			}
		}

		return false;
	}

	// Memoization
	// TC: O( m^2 * n )
	// SC:O( m ^ 2)

	bool CanGenerate(const std::vector<std::string>& strings, std::string target
		, std::map<std::string, bool>& memo)
	{
		if (memo.count(target) == 1)
		{
			return memo[target];
		}

		// base case
		if (target == "")
		{
			return true;
		}

		// recursive
		for (auto e : strings)
		{
			if (target.find(e) == 0)
			{
				auto subStr = target.substr(e.size());
				if (CanGenerate(strings, subStr))
				{
					memo[target] = true;
					return memo[target];
				}
			}
		}

		memo[target] = false;
		return memo[target];
	}

	// Combination - brute force
	// TC : O(n^m * m)
	// SC : O(m^2)
	int HowManyGenerate(const std::vector<std::string>& strings, std::string target)
	{
		// base case
		if (target == "")
		{
			return 1;
		}

		// recursive case
		int count{};

		for (auto e : strings)
		{
			if (target.find(e) == 0)
			{
				std::string subs = target.substr(e.size());
				count += HowManyGenerate(strings, subs);
			}
		}
		return count;
	}

	// Combination - Memoization
	// TC : O(n^m * m)
	// SC : O(m^2) �⺻ ��Ʈ���� substr�� ���� �Ǵϱ� m����
	int HowManyGenerate(const std::vector<std::string>& strings, std::string target,
		std::map<std::string, int>& memo)
	{
		if (memo.count(target) == 1)
		{
			return memo[target];
		}
		// base case
		if (target == "")
		{
			return 1;
		}

		// recursive case
		int count{};

		for (auto e : strings)
		{
			if (target.find(e) == 0)
			{
				std::string subs = target.substr(e.size());
				count += HowManyGenerate(strings, subs, memo);
			}
		}
		memo[target] = count;
		return memo[target];
	}

	using string2d = std::list<std::list<std::string>>;

	// TC: O(n^m * M)
	// SC: 
	string2d AllCombination(const std::vector<std::string>& strings, std::string target)
	{
		// base case
		if (target == "")
		{
			return string2d{ {} };

		}

		// recursive case
		string2d v;
		for (auto word : strings)
		{
			if (target.find(word) == 0)
			{
				auto r = AllCombination(strings, target.substr(word.size()));
				for (auto s : r)
				{
					s.push_front(word);
					v.push_front(s);
				}
			}
		}
		return v;
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
}