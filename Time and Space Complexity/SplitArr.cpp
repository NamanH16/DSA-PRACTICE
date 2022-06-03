/*Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.*/
#include <bits/stdc++.h>
using namespace std;

// Recursive function that returns true if the array
// can be divided into two sub-arrays
// satisfying the given condition
bool helper(int *arr, int n, int start, int lsum, int rsum)
{

    // If reached the end
    if (start == n)
        return lsum == rsum;

    // If divisible by 5 then add to the left sum
    if (arr[start] % 5 == 0)
        lsum += arr[start];

    // If divisible by 3 but not by 5
    // then add to the right sum
    else if (arr[start] % 3 == 0)
        rsum += arr[start];

    // Else it can be added to any of the sub-arrays
    else

        // Try adding in both the sub-arrays (one by one)
        // and check whether the condition satisfies
        return helper(arr, n, start + 1, lsum + arr[start], rsum) || helper(arr, n, start + 1, lsum, rsum + arr[start]);

    // For cases when element is multiple of 3 or 5.
    return helper(arr, n, start + 1, lsum, rsum);
}

// Function to start the recursive calls
bool splitArray(int *arr, int n)
{
    // Initially start, lsum and rsum will all be 0
    return helper(arr, n, 0, 0, 0);
}

// Driver code
int main()
{
    int arr[] = {1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (splitArray(arr, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}