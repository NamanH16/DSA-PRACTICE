#include <iostream>
using namespace std;

int product(int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (m < n)
    {
        return product(n, m);
    }
    else
    {
        return m + product(m, n - 1);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << product(n, m) << endl;

    return 0;
}