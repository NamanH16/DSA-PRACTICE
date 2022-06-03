/*Suppose you have a string, S, made up of only 'a's and 'b's. 
Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'.

This question basically states that the string should start with 'a' and 'abb' should come in the string to become true*/
#include <iostream>
using namespace std;

bool checkAB(char input[])
{
    if (input[0] == '\0')
    {
        return true;
    }

    int st = 0;
    if (input[st] == 'a')
    {
        if (input[st + 1] == 'b' && input[st + 2] == 'b')
        {
            return checkAB(input + 3);
        }
        checkAB(input + 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    char input[1000];
    cin >> input;
    bool ans;
    ans = checkAB(input);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}