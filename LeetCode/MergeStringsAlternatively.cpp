#include <string>

class MergeStringsAlternatively {
	public:
	// an improvement to this would be:
	// 1- quick return if word1 or word2 are 0 values
	// 2- fetch a total length by verifying who's the longest string, then using push_back on result_string to insert the values from word1[i] to word2[1]
	static std::string mergeAlternatively(std::string word1, std::string word2) {
		bool b_is_first_word_longer = word1.length() > word2.length();
		bool b_is_second_word_longer = word2.length() > word1.length();
		std::string result_string;

		for (int i = 0; i <= word1.length() - 1; i++)
		{
			char currentWord1Char = word1[i];
			result_string += currentWord1Char;

			// If the 2nd word's lenght exceeds the first word's length
			if (i > word2.length() - 1)
			{
				break;
			}

			char currentWord2Char = word2[i];
			result_string += currentWord2Char;
		}


		if (b_is_first_word_longer)
		{
			auto missingFirstWordSplit = word1.substr(word2.length() + 1);
			result_string += missingFirstWordSplit;
		}

		if (b_is_second_word_longer)
		{
			auto missingSecondWordSplit = word2.substr(word1.length());
			result_string += missingSecondWordSplit;
		}

		return result_string;
	}
};
