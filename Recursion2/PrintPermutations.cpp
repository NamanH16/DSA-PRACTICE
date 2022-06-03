#include <iostream>
#include <string.h>
using namespace std;

void PrintPermutations(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    for (int i = 0; i <= output.length(); i++)
    {
        PrintPermutations(input.substr(1), output.substr(0, i) + input[0] + output.substr(i));
    }
}

int main()
{
    string input;
    cin >> input;
    PrintPermutations(input, "");

    return 0;
}