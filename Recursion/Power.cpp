#include <iostream>
using namespace std;

int power(int x, int m)
{
    if (m == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, m - 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << power(n, m);
}
