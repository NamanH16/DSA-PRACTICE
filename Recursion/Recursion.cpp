#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0) // base case
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1); // we need base case because
                                     //if not then, factorial function will go even below 0 and start going in negatives
    }                                // until computer runs outta memory(Segmentation fault)
}

int main()
{
    int n;
    cin >> n;
    int output = factorial(n);
    cout << output << endl;

    return 0;
}