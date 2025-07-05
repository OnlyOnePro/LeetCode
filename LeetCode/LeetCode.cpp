// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numeric>
#include <vector>

class ProductOfArrayExceptSelf {

	public:
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

int main() {
    int testElement[] = { 1, 2, 3 ,4};
    int n = std::size(testElement);

    std::vector<int> testVector(testElement, testElement + n);

    ProductOfArrayExceptSelf* m = new ProductOfArrayExceptSelf();
    m->productExceptSelfV2(testVector);

	//ReverseWordsInAString* r = new ReverseWordsInAString();
	//r->reverseWords("a good   example");
	//std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
