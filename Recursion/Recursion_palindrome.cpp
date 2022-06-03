//check palindrome with recursion
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

bool helper(char str[], int start, int end)
{
    if (start == end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }

    bool smallans = helper(str, start + 1, end - 1);
    if (start < end + 1)
    {
        return smallans;
    }
}

bool checkPalindrome(char str[])
{
    int n = strlen(str);
    if (n == 0)
    {
        return true;
    }

    return helper(str, 0, n - 1);
}

int main()
{
    char str[] = "namal";

    if (checkPalindrome(str))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}