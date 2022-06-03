#include <iostream>
using namespace std;

void merge(int input[], int si, int mid, int ei)
{
    int i, j, k, nl, nr;
    //size of left and right sub-arrays
    nl = mid - si + 1;
    nr = ei - mid;
    int larr[nl], rarr[nr];
    //fill left and right sub-arrays
    for (i = 0; i < nl; i++)
    {
        larr[i] = input[si + i];
    }
    for (j = 0; j < nr; j++)
    {
        rarr[j] = input[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = si;
    //merge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            input[k] = larr[i];
            i++;
        }
        else
        {
            input[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    { //extra element in left array
        input[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    { //extra element in right array
        input[k] = rarr[j];
        j++;
        k++;
    }
}

void helper(int input[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = (si + ei) / 2;

    helper(input, si, mid);
    helper(input, mid + 1, ei);
    merge(input, si, mid, ei);
}

void mergeSort(int input[], int size)
{
    // Write your code here
    helper(input, 0, size - 1);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}