#include "TwoPointerProblems.h"

#include <shared_mutex>

void TwoPointerProblems::moveZeroes(std::vector<int>& nums)
{
	for (int non_zero_index = 0, i = 0; i <= nums.size() - 1; i++)
	{
		if (nums[i] != 0)
		{
			std::swap(nums[non_zero_index++], nums[i]);
		}
	}
}

bool TwoPointerProblems::isSubsequence(std::string s, std::string t)
{
	int i = 0;
	int j = 0;

	while (i < s.size() && j < t.size())
	{
		if (s[i] == t[j])
		{
			++i;
		}

		++j;
	}

	return i == s.size();
}

