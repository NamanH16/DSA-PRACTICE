#include <iostream>
using namespace std;

int knapsack(int *weight, int *value, int n, int maxWeight, int **output)
{
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }

    if (output[n][maxWeight] != -1)
    {
        return output[n][maxWeight];
    }

    int ans;
    if (weight[0] > maxWeight)
    {
        ans = knapsack(weight + 1, value + 1, n - 1, maxWeight, output);
    }
    else
    {
        int x = knapsack(weight + 1, value + 1, n - 1, maxWeight - weight[0], output) + value[0];
        int y = knapsack(weight + 1, value + 1, n - 1, maxWeight, output);

        ans = max(x, y);
    }
    output[n][maxWeight] = ans;
    return ans;
}

int knapsack(int *weight, int *value, int n, int maxWeight)
{
    // Create a 2-D array of "no. of weights" and "capacity"
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = new int[maxWeight + 1];
        for (int j = 0; j < maxWeight + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    return knapsack(weight, value, n, maxWeight, output);
}

int main()
{
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;

    return 0;
}