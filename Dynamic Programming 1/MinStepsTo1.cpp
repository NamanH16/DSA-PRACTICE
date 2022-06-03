/*Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. 
You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ). 
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 

Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Approach 1: Brute Force -> Time Complexity O(2^n)
int countMinStepsToOne(int n)
{
    //Write your code here
    if (n <= 1)
    {
        return 0;
    }

    int ans1 = countMinStepsToOne(n - 1);

    int ans2 = INT_MAX, ans3 = INT_MAX; //if not initialized to INT_MAX, there will be random garbage in ans2 and ans3 and
                                        //we would get worng answers for min(ans2,ans3)
    if (n % 2 == 0)
        ans2 = countMinStepsToOne(n / 2);

    if (n % 3 == 0)
        ans3 = countMinStepsToOne(n / 3);

    return min(ans1, min(ans2, ans3)) + 1;
}

/*------------------------------------------------------------------------------------*/

// Approach 2: Memoization -> Time Complexity O(n)
int minStepsHelper(int n, int *ans)
{
    // Base Case
    if (n <= 1)
    {
        return 0;
    }

    // Check if output already exists
    if (ans[n] != -1)
    {
        return ans[n];
    }

    // Calculate Output
    int x = minStepsHelper(n - 1, ans);

    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
        y = minStepsHelper(n / 2, ans);

    if (n % 3 == 0)
        z = minStepsHelper(n / 3, ans);

    int output = min(x, min(y, z)) + 1;

    ans[n] = output; // saving answer for future use

    return output;
}

int countMinStepsToOne_2(int n)
{
    int *ans = new int[n + 1]; //for recursion on any integer n, the recuresive calls can only be made on integers from 0 to n
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minStepsHelper(n, ans);
}

/*------------------------------------------------------------------------------------*/

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n) << endl;
    cout << countMinStepsToOne_2(n) << endl;
}
