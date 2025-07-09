// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

#include "Problems/TwoPointers/TwoPointerProblems.h"

//class StringCompression {
//	public:
//	static int compress(std::vector<char>& chars) {
//		std::string s;
//
//		char current_character = chars[0];
//		int current_character_amounts = 0;
//
//		for (int i = 0; i <= chars.size() - 1; i++)
//		{
//			if (chars[i] == current_character)
//			{
//				++current_character_amounts;
//			}
//			else
//			{
//				if (current_character_amounts > 1)
//				{
//					s += current_character;
//					s += std::to_string(current_character_amounts);
//				}
//				else
//				{
//					s += current_character;
//				}
//
//
//				current_character = chars[i];
//				current_character_amounts = 1;
//			}
//		}
//
//		s += current_character;
//
//		if (current_character_amounts > 1)
//		{
//			s += std::to_string(current_character_amounts);
//		}
//
//		chars.clear();
//
//		for (const char& character : s)
//		{
//			chars.push_back(character);
//		}
//
//		return chars.size();
//	}
//};

int main() {
    int testElement[] = { 0,0,1 };
    int n = std::size(testElement);

    std::vector<int> testVector(testElement, testElement + n);

    TwoPointerProblems* pp = new TwoPointerProblems();
    pp->isSubsequence("acb", "ahbgdc");

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
