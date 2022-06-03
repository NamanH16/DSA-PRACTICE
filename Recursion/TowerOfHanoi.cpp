#include <bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, char a, char b, char c)
{
    if (n > 0)
    {
        TowerOfHanoi(n - 1, a, c, b);
        cout << a << " " << c << endl;
        TowerOfHanoi(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    cin >> n;

    TowerOfHanoi(n, 'a', 'b', 'c');

    return 0;
}