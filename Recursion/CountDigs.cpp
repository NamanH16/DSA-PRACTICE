#include <iostream>
using namespace std;

int count(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        int smallans = count(n / 10);
        return smallans += 1;
    }
}

int main()
{
    int n;
    cin >> n;

    cout << count(n) << endl;

    return 0;
}