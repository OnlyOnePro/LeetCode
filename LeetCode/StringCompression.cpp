#include <string>
#include <vector>
#include <iostream>

// got 0ms on runtime and better than 89% of leetcode solutions.
// think for my level of c++ that's good enough
class StringCompression {
	public:
	static int compress(std::vector<char>& chars) {
		std::string s;

		char current_character = chars[0];
		int current_character_amounts = 0;

		for (int i = 0; i <= chars.size() - 1; i++)
		{
			if (chars[i] == current_character)
			{
				++current_character_amounts;
			}
			else
			{
				if (current_character_amounts > 1)
				{
					s += current_character;
					s += std::to_string(current_character_amounts);
				}
				else
				{
					s += current_character;
				}


				current_character = chars[i];
				current_character_amounts = 1;
			}
		}

		s += current_character;

		if (current_character_amounts > 1)
		{
			s += std::to_string(current_character_amounts);
		}

		chars.clear();

		for (const char& character : s)
		{
			chars.push_back(character);
		}

		return chars.size();
	}
};
