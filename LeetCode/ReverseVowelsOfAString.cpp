#include <string>
#include <vector>

class ReverseVowelsOfAString {
	public:

	std::string reverseVowels(std::string s) {
		std::vector<char> s_characters(s.begin(), s.end());

		for (int i = 0, j = s_characters.size() - 1; i <= s_characters.size() - 1; i++)
		{
			char leftmostChar = s_characters[i];
			char rightmostChar = s_characters[j];

			if (j < i)
			{
				break;
			}

			if (isCharAVowel(leftmostChar))
			{
				while (!isCharAVowel(rightmostChar) && j > 0)
				{
					j--;
					rightmostChar = s[j];
				}

				if (isCharAVowel(rightmostChar) && j != 0)
				{
					s_characters[i] = rightmostChar;
					s_characters[j] = leftmostChar;
					j--;
				}
			}
		}

		return std::string(s_characters.begin(), s_characters.end());
	}

	bool isCharAVowel(char character) {
		return (character == 'a' || character == 'e' || character == 'i' || character == 'o'
			|| character == 'u' || character == 'A' || character == 'E' || character == 'I'
			|| character == 'O' || character == 'U');
	}
};