#include <iostream>
using namespace std;

int getLen(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    else
    {
        return 1 + getLen(str + 1);
    }
}

int main()
{
    char str[10000];
    cin.getline(str, 10000);

    cout << getLen(str) << endl;

    return 0;
}