#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void PrintSubsequences(string input, string output)
{
    if (input.empty())
    { // Base Case: The decision has been made for every char of string. Now,it only needs to be printed.
        cout << output << endl;
        return;
    }

    PrintSubsequences(input.substr(1), output);
    PrintSubsequences(input.substr(1), output + input[0]);
}

int main()
{
    string input;
    cin >> input;
    string output = ""; // an empty output string needs to be passed
    PrintSubsequences(input, output);

    return 0;
}
