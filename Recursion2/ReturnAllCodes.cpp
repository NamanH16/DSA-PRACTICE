#include <iostream>
#include <string.h>
using namespace std;

// Eg; 1123
// Here a -> 1,b ->2,c ->3,k -> 11,w -> 23

int GetCodes(string input, string output[1000])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    int num = input[0] - 48;
    char ch = 'a' + num - 1;

    int s1 = GetCodes(input.substr(1), output);

    for (int i = 0; i < s1; i++)
    {
        output[i] = ch + output[i];
    }

    int s2 = 0;
    if (input[0] != '\0')
    {
        num = num * 10 + input[1] - 48;
        ch = 'a' + num - 1;

        if (num >= 10 && num <= 26)
        {
            s2 = GetCodes(input.substr(2), output + s1);

            for (int i = 0; i < s2; i++)
            {
                output[i + s1] = ch + output[i + s1];
            }
        }
    }
    return s1 + s2;
}

int main()
{
    string input;
    cin >> input;
    string output[1000];

    int count = GetCodes(input, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}