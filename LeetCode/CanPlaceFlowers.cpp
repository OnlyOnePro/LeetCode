#include <vector>

class CanPlaceFlowers {

    public:

    // can be improved by using boolean logic to do the comparissons,
    // skip calc time by checking so many ifs
    // save on memory by avoiding so many allocs on the local code

    //its 12am im tired :V
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
