#include <numeric>
#include <vector>

class ProductOfArrayExceptSelf
{
public:
	// so i first created this one to kinda visualize the problem better and do it in a more verbose way.
	// problem was it hitted runtime max time on a very long solution
	std::vector<int> productExceptSelf(std::vector<int>& nums) {
	std::vector<int> resultVector;

	for (int i = 0; i <= nums.size() - 1; i++)
	{
		std::vector<int> leftValues(nums.begin(), nums.begin() + i);
		std::vector<int> rightValues(nums.begin() + i + 1, nums.end());

		auto left_side_multiplication = std::accumulate(std::begin(leftValues), end(leftValues), 1.0, std::multiplies<int>());
		auto right_side_multiplication = std::accumulate(std::begin(rightValues), std::end(rightValues), 1.0, std::multiplies<int>());

		resultVector.push_back(static_cast<int>(left_side_multiplication * right_side_multiplication));
	}

	return resultVector;
}

	// so i decided to compress my for and my hidden for loops (nums.begin/end and std::accumulate are for loops under the hood)
	// and just straight up optimize it now that my math was ok and i could visualize the problem
	std::vector<int> productExceptSelfV2(std::vector<int>& nums) {
		std::vector<int> resultVector(nums.size(), 1);
		std::vector<int> leftProducts(nums.size(), 1);
		std::vector<int> rightProducts(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++)
		{
			leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
		}

		for (int i = nums.size() - 2; i >= 0; --i)
		{
			rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			resultVector[i] = leftProducts[i] * rightProducts[i];
		}

		return resultVector;
	}
};
