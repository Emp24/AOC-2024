
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

int process_expressions(vector<string> expressions)
{
    bool flag = true;
    int result = 0;
    for (int i = 0; i < expressions.size(); i++)
    {
        if (expressions[i] == "don't()")
        {
            flag = false;
        }
        else if (expressions[i] == "do()")
        {
            flag = true;
        }
        else
        {
            if (flag)
            {
                result += process_expression(expressions[i]);
            }
        }
    }

    return result;
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
    // std::string txt = "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))";
    std::regex pattern(R"(mul\(\d+,\d+\)|do\(\)|don't\(\))");
    std::smatch matches;

    // THEY'RE ALREADY IN A LIST I KNOW BUT I DIDN'T NOTICE UNTIL I FINISHED IT AND I'M TOO LAZY TO CHANGE IT
    vector<string> expressions;

    auto begin = std::sregex_iterator(txt.begin(), txt.end(), pattern);
    auto end = std::sregex_iterator();
    for (auto it = begin; it != end; it++)
    {
        cout << it->str() << endl;
        expressions.push_back(it->str());
        // process_expression(it->str());
        // cout << process_expression(it->str()) << endl;
        // result += process_expression(it->str());
    }

    // int result = process_expressions(expressions);
    cout << process_expressions(expressions) << endl;
    system("pause");
    return 0;
}