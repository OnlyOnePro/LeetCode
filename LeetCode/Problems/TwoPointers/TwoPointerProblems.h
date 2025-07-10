#pragma once
#include <string>
#include <vector>

class TwoPointerProblems {

public:
	void moveZeroes(std::vector<int>& nums);

	bool isSubsequence(std::string s, std::string t);

	/// <summary>
	/// I did this one as a exploratory phase using a std::vector<tuple<int, int, int> with a typedef to check if my thesis on exploring the area was correct.
	/// </summary>
	/// <param name="height"></param>
	/// <returns></returns>
	int maxArea(std::vector<int>& height);

	/// <summary>
	/// After the first attempt, i removed the need for tuples and vectors all together to improve in both speed and memory consumption.
	/// </summary>
	/// <param name="height"></param>
	/// <returns></returns>
	int maxAreaV2(std::vector<int>& height);

	/// <summary>
	/// On my first attempt I hitted a constant time exceeded error, so i thought of sorting the array and doing
	/// a + - sum kinda like sorted two-sum or the product of the array except self where u have a guarantee of ordering to do cursor increment/decrements
	/// </summary>
	/// <param name="nums"></param>
	/// <param name="k"></param>
	/// <returns></returns>
	int maxOperations(std::vector<int>& nums, int k);
};

