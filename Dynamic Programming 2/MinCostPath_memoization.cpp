#include <bits/stdc++.h>
using namespace std;

// Approach 2: Memoization
int minCostPath(int **input, int m, int n, int i, int j, int **output) // i and j represent the starting
{
    // Base Case
    if (i == m - 1 && j == n - 1) // starting and ending points are same
    {
        return input[i][j];
    }

    if (i >= m || j >= n) // to check for invalid recursion calls... eg we are on the edge of the matrix,
    {                     //then we can only call downwards recursion not left or diagonal
        return INT_MAX;
    }

    // Check if ans already exists
    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    // Recursive calls
    int x = minCostPath(input, m, n, i, j + 1, output);
    int y = minCostPath(input, m, n, i + 1, j + 1, output);
    int z = minCostPath(input, m, n, i + 1, j, output);

    // Small Calculation
    int a = min(x, min(y, z)) + input[i][j];

    // Save the ans for future use
    output[i][j] = a;
    return a;
}

int minCostPath(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    //Write your code here
    return minCostPath(input, m, n, 0, 0, output);
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;

    return 0;
}