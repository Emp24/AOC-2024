#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <numeric>
#include <fstream>
#include <sstream>
using namespace std;
/*TODD: 1. Read the input file
    2. Parse the input files
   3. Check the numbers increasing and decreasing
*/

bool IsSafe(vector<int> numbers)
{
    // bool isSafe = true;
    bool isIncreasing = numbers[0] < numbers[1];

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        int diff = abs(numbers[i] - numbers[i + 1]);

        if (diff > 3 || diff < 1)
        {
            return false;
        }

        if (numbers[i] < numbers[i + 1] != isIncreasing)
        {
            // std::cout << "Not safe" << endl;
            return false;
        }
        if (numbers[i] > numbers[i + 1] != !isIncreasing)
        {
            return false;
        }
    }

    return true;
}

int CountSafeSets(vector<vector<int>> set)
{
    int safeSets = 0;
    for (int i = 0; i < set.size(); i++)
    {
        if (IsSafe(set[i]))
        {
            cout << "Set" + to_string(i) + " is safe" << endl;
            safeSets++;
        }
        else
        {
            int n = set[i].size();
            for (int j = 0; j < n; ++j)
            {
                vector<int> newNumbers = set[i];
                newNumbers.erase(newNumbers.begin() + j);
                if (IsSafe(newNumbers))
                {
                    safeSets++;
                    break;
                }
            }
        }
    }

    return safeSets;
}
int main()
{
    std::vector<std::vector<int>> numbers;
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }
    string line;
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::vector<int> row;
        int number;

        // Extract numbers from the line
        while (ss >> number)
        {
            row.push_back(number);
        }

        // Add the row to the main vector
        numbers.push_back(row);
    }

    cout << CountSafeSets(numbers) << endl;
    system("pause");
    return 0;
}