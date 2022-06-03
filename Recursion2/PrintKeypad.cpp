#include <iostream>
#include <string>
using namespace std;

void printKeypad(int num, string output)
{
    string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (num == 0 || num == 1)
    {
        cout << output << endl;
        return;
    }

    string k = map[num % 10];

    for (int i = 0; i < k.size(); i++)
    {
        printKeypad(num / 10, k[i] + output);
    }
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num, "");

    return 0;
}