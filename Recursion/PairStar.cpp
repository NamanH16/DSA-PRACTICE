#include <iostream>
using namespace std;

void PairStar(char input[])
{
    int n = 0;
    while (input[n])
    { //size of character array
        n++;
    }

    if (n == 0)
    {
        return;
    }

    int st = 0;
    if (input[st] == input[st + 1])
    {
        for (int i = n - 1; i >= st + 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[st + 1] = '*';
        input[n + 1] = '\0';
        PairStar(input + 2);
    }
    PairStar(input + 1);
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    PairStar(input);
    cout << input << endl;
}