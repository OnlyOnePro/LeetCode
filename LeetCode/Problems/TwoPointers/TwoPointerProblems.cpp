#include "TwoPointerProblems.h"

#include <algorithm>
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

int TwoPointerProblems::maxArea(std::vector<int>& height)
{
	int i = 0;
	int j = height.size() - 1 ;
	std::tuple<int, int, int> largestKnownArea;


	while (i < height.size() - 1)
	{
		int i_height_value = height[i];
		int j_height_value = height[j];

		int area = std::min(i_height_value, j_height_value) * (j - i);

		if (area > 0 && area > std::get<2>(largestKnownArea))
		{
			largestKnownArea = std::tuple(i, j, area);
		}

		if (i_height_value <= j_height_value)
		{
			++i;
		}
		else if (i_height_value > j_height_value)
		{
			--j;
		}
	}

	return std::get<2>(largestKnownArea);
}

int TwoPointerProblems::maxAreaV2(std::vector<int>& height)
{
	int i = 0;
	int j = height.size() - 1;
	int largest_known_area = 0;


	while (i < height.size() - 1)
	{
		int i_height_value = height[i];
		int j_height_value = height[j];

		int area = std::min(i_height_value, j_height_value) * (j - i);
		largest_known_area = std::max(area, largest_known_area);

		if (i_height_value <= j_height_value)
		{
			++i;
		}
		else if (i_height_value > j_height_value)
		{
			--j;
		}
	}

	return largest_known_area;
}

int TwoPointerProblems::maxOperations(std::vector<int>& nums, int k)
{
	sort(nums.begin(), nums.end());
	int i = 0;
	int j = nums.size() - 1;

	int amount_of_operations = 0;

	while (i < j)
	{
		if (nums.size() == 0)
		{
			break;
		}

		int right_number = nums[i];
		int left_number = nums[j];

		int sum = right_number + left_number;

		if (sum == k)
		{
			amount_of_operations++;

			i++;
			j--;
		}
		else if (sum > k)
		{
			j--;
		}
		else
		{
			i++;
		}
	}

	return amount_of_operations;
}


