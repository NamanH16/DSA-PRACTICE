/*Min Heap will arrange array in a decreasing order
Max Heap will arrange array in a increasing order*/
#include <iostream>
using namespace std;

void inPlaceHeapSort(int input[], int n)
{
    // Step 1: Build the heap in input array
    // We assume that 0th element is already sorted
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (input[childIndex] < input[parentIndex])
            {
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    // Step 2: Remove elements(RemoveMin())
    int size = n;

    while (size > 1)
    {
        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;

        size--;

        // Down Heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndx = 2 * parentIndex + 2;

        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (input[minIndex] > input[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndx < size && input[rightChildIndx] < input[minIndex])
            {
                minIndex = rightChildIndx;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndx = 2 * parentIndex + 2;
        }
    }
}

int main()
{
    int input[] = {5, 1, 2, 0, 8};
    inPlaceHeapSort(input, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;

    return 0;
}