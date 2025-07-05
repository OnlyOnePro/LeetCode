#include <string>
#include <vector>

class ReverseWordsInAString {
	public:
	// Maybe improve memory consumption by reducing allocs
	// consumes 10.92mb acc to leetcode

	// got 0ms runtime tho :D
	std::string reverseWords(std::string s) {
		const char delimiterChar = ' ';
		std::vector<std::string> wordsInString;
		std::string resultString;

		size_t start = 0;
		size_t end = s.find(delimiterChar);

		// i actually had to lookup how to do a substring in c++ bc i never had to do it.
		// in fucking C# would have been as ez as string.Split(' ');
		while (end != std::string::npos)
		{
			auto possibleWord = s.substr(start, end - start);

			if (!possibleWord.empty())
			{
				wordsInString.push_back(possibleWord);
			}


			start = end + 1;
			end = s.find(delimiterChar, start);
		}

		auto possibleLastWord = s.substr(start, std::min(end, s.size()) - start + 1);

		if (!possibleLastWord.empty())
		{
			wordsInString.push_back(possibleLastWord);
		}

		for (int i = wordsInString.size() - 1; i >= 0; --i)
		{
			resultString += wordsInString[i];

			if (i != 0)
			{
				resultString += ' ';
			}
		}

		return resultString;
	}
};
