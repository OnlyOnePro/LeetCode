#include <vector>

class KidsWithTheGreatestNumberOfCandies
{
    public:
    // can't think of a better way to improve it
    // leetcode gives me a 0ms runtime with 12.37mb consumption.
	static std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> results_vector;
        auto kidWithTheMostCandies = *std::max_element(candies.begin(), candies.end());

        for (int i = 0; i <= candies.size() - 1; i++)
        {
            auto currentKidAmount = candies[i] + extraCandies;

            results_vector.push_back(currentKidAmount >= kidWithTheMostCandies);
        }

        results_vector.shrink_to_fit();

        return results_vector;
    }
};
