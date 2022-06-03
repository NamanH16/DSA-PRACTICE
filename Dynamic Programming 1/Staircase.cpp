/*A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count and return all possible ways in which the child can run-up to the stairs.

Sample Input 1:
4
Sample Output 1:
7

Sample Input 2:
10
Sample Output 2:
274
*/
#include <iostream>
using namespace std;

// Approach 1 : Brute Force

int staircase(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }

    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n) << endl;
}