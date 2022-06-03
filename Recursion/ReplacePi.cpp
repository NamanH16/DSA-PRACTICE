#include <iostream>
using namespace std;

void helper(char input[], int st)
{
    if (input[st] == '\0' || input[st + 1] == '\0')
    {
        return;
    }

    helper(input, st + 1);

    int length = 0;
    while (input[length]) //Or simply, strlen(input)
    {
        length++;
    }

    if (input[st] == 'p' && input[st + 1] == 'i')
    {
        for (int i = length; i >= st + 2; i--)
        {
            input[i + 2] = input[i];
        }
        input[st] = '3';
        input[st + 1] = '.';
        input[st + 2] = '1';
        input[st + 3] = '4';
    }
}

void replacePi(char input[])
{
    // Write your code here
    helper(input, 0);
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
