#include <iostream>
#include <string.h>
using namespace std;

int ReturnPermutations(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallOutput[1000];
    int smallans = ReturnPermutations(input.substr(1), smallOutput);
    int k = 0;
    for (int i = 0; i < smallans; i++)
    {
        for (int j = 0; j <= smallOutput[i].length(); j++)
        {
            output[k++] = smallOutput[i].substr(0, j) + input[0] + smallOutput[i].substr(j);
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = ReturnPermutations(input, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}