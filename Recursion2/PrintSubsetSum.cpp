#include <iostream>
using namespace std;

void helper(int input[], int size, int output[], int k, int outputSize = 0)
{
    if (size == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < outputSize; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    helper(input + 1, size - 1, output, k, outputSize); // 0th element not included
    int smallOutput[1000];

    int si = 0;
    if (k > 0)
    {
        int i;
        for (i = 0; i < outputSize; i++)
        {
            smallOutput[i] = output[i];
        }

        smallOutput[i] = input[si];

        helper(input + 1, size - 1, smallOutput, k - input[si], outputSize + 1); // 0th element included
    }
}

void printSubsetSumToK(int input[], int size, int k)
{
    int output[1000];
    helper(input, size, output, k);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
