#include <iostream>
#include <string.h>
using namespace std;

void RemoveX(char str[])
{
    int n = strlen(str);
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] != 'x')
    {
        RemoveX(str + 1);
    }
    else
    {
        for (int i = 1; str[i] != '\0'; i++) // Here,we 're shifting array towards the left(when u wanna shift right,start with i = n-1)
        {
            str[i - 1] = str[i];
        }
        str[n - 1] = '\0';
        RemoveX(str);
    }
}

int main()
{
    char str[1000];
    cin.getline(str, 1000);
    RemoveX(str);
    cout << str << endl;

    return 0;
}