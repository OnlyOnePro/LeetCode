// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class CanPlaceFlowers {

public:
    static bool canPlaceFlowers(const std::vector<int>& flowerbed, int n) {
        std::vector<int> flowerbedWorkspace = flowerbed;
        int amountOfFlowersThatCanBePlaced = 0;

        for (int i = 0; i <= flowerbedWorkspace.size() - 1; i++)
        {
            int currentPlotState = flowerbedWorkspace[i];
            bool isNextPlotFull = false;
            bool isPreviousPlotFull = false;
            int nextElementIndex = i + 1;
            int previousElementIndex = i - 1;

            if (nextElementIndex <= flowerbedWorkspace.size() - 1)
            {
                int adjecentPlotState = flowerbedWorkspace[nextElementIndex];

                isNextPlotFull = adjecentPlotState == 1;
            }

            if (previousElementIndex >= 0)
            {
                int previousPlotState = flowerbedWorkspace[previousElementIndex];

                isPreviousPlotFull = previousPlotState == 1;
            }

            if (currentPlotState == 0 && !isNextPlotFull && !isPreviousPlotFull)
            {
                amountOfFlowersThatCanBePlaced++;
                flowerbedWorkspace[i] = 1;
            }
        }

        return amountOfFlowersThatCanBePlaced >= n;
    }
};

int main() {
    int testElement[] = { 1,0,0,0,0,1 };
    int n = std::size(testElement);

    std::vector<int> testVector(testElement, testElement + n);

    CanPlaceFlowers* m = new CanPlaceFlowers();
    m->canPlaceFlowers(testVector, 2);
	std::cout << "Hello World!\n";
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
