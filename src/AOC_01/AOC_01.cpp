
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <numeric>
#include <fstream>
using namespace std;

int main()
{
    vector<int> firstList;
    vector<int> secondList;
    map<int, int> secondListCount;
    int num1, num2;

    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    while (inputFile >> num1 >> num2)
    {
        firstList.push_back(num1);
        secondList.push_back(num2);
        secondListCount[num2]++;
    }

    /* First part */
    sort(firstList.begin(), firstList.end());
    sort(secondList.begin(), secondList.end());
    int result = 0;
    for (int i = 0; i < firstList.size(); i++)
    {
        result += abs(firstList[i] - secondList[i]);
    }
    cout << "First part answer: " << result << endl;

    /* Second part */
    result = 0;
    for (int i = 0; i < firstList.size(); i++)
    {
        result += firstList[i] * secondListCount[firstList[i]];
    }
    cout << "Second part answer: " << result << endl;
    // Close the file
    inputFile.close();
    system("pause");
    return 0;
}