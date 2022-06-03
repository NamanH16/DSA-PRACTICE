#include <iostream>
using namespace std;

int partition(int input[], int si, int ei) // pivot as the first element
{
    int i = si + 1;
    int pivot = input[si];
    for (int j = si + 1; j <= ei; j++)
    {
        if (input[j] < pivot)
        {
            swap(input[i], input[j]);
            i++;
        }
    }
    swap(input[si], input[i - 1]);
    return i - 1;
}

/*
int partition(int arr[],int si,int ei)  // pivot as the last element
{
    int pivot = arr[ei];
    int i = ei - 1;
    
    for(int j = ei;j >= si;j--)
    {
        if(arr[j] > pivot)
        {
            swap(arr[i],arr[j]);
            i--;
        }
        
    }
    swap(arr[ei],arr[i+1]);
    return i+1;
}

*/
void quickSort(int input[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int c = partition(input, si, ei);
    quickSort(input, si, c - 1);
    quickSort(input, c + 1, ei);
}

void quickSort(int input[], int size)
{
    quickSort(input, 0, size - 1);
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

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}