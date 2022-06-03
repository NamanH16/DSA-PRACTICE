#include <iostream>
#include <string.h>
using namespace std;

void helper(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    int num = input[0] - 48;
    char ch = 'a' + num - 1;

    helper(input.substr(1), output + ch);

    if (input[1] != '\0')
    {
        num = num * 10 + input[1] - 48;
        ch = 'a' + num - 1;

        if (num >= 10 && num <= 26)
        {
            helper(input.substr(2), output + ch);
        }
    }
}

void printAllPossibleCodes(string input)
{
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    helper(input, "");
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
