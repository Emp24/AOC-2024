
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <numeric>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

int process_expression(string expression)
{
    string number = "";
    vector<int> numbers;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == ',')
        {
            numbers.push_back(std::stoi(number));
            number = "";
        }

        if (isdigit(expression[i]))
        {
            number += expression[i];
        }
    }
    numbers.push_back(std::stoi(number));

    return numbers[0] * numbers[1];
}

int main()
{
    std::ifstream file("input.txt"); // Replace "example.txt" with your file path

    if (!file)
    {
        std::cerr << "Error: Cannot open file!" << std::endl;
        return 1;
    }

    // Read the entire file into a string
    std::ostringstream buffer;
    buffer << file.rdbuf(); // Read the stream buffer into the stringstream

    std::string txt = buffer.str();
    std::regex pattern(R"(\mul\(\d+,\d+\))");
    std::smatch matches;

    auto begin = std::sregex_iterator(txt.begin(), txt.end(), pattern);
    auto end = std::sregex_iterator();
    int result = 0;
    for (auto it = begin; it != end; it++)
    {
        cout << it->str() << endl;
        process_expression(it->str());
        cout << process_expression(it->str()) << endl;
        result += process_expression(it->str());
    }
    cout << result << endl;
    system("pause");
    return 0;
}