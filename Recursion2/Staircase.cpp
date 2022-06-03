/*A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return number of possible ways W.*/
#include <iostream>
using namespace std;

// First thought that should come to mind when thinking of a recursive solution, is to how to break the problem
// How to just solve one thing and make the rest n-1 things happen by recursion.
// Example: n = 10
// Now, when I go 1 step -> I reach 9
// 2 steps -> 8
// 3 steps -> 7
// Now, the remaining 9/8/7 stairs can also be divided in similar three way fashion
// Let's say there're 'x' ways for ascending the remaining 9 steps, 'y' ways for 8 steps,'z' ways for 7 steps
// The solution is -> (x + y + z)

int staircase(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else if (num == 2)
    {
        return 2;
    }
    else if (num == 3)
    {
        return 4;
    }
    else
    {
        return staircase(num - 3) + staircase(num - 2) + staircase(num - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    cout << "No. of ways in which " << n << " stairs can be climbed are: " << staircase(n) << endl;
}