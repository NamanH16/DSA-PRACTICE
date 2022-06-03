#include <iostream>
using namespace std;

void helper(int input[], int inputSize, int output[], int outputSize = 0)
{
    if (inputSize == 0)
    {
        for (int i = 0; i < outputSize; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    helper(input + 1, inputSize - 1, output, outputSize);

    int other[1000];
    int i;
    for (i = 0; i < outputSize; i++)
    {
        other[i] = output[i];
    }
    other[i] = input[0];

    helper(input + 1, inputSize - 1, other, outputSize + 1);
}

void PrintSubsetsOfArray(int input[], int size)
{
    int output[1000];
    helper(input, size, output);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    PrintSubsetsOfArray(input, n);

    delete[] input;

    return 0;
}