#include <iostream>
using namespace std;
// Keep in mind that default arguments don't come in the middle or starting
// Examples of invalid default arguments:
// int SUM(int a[], int si = 0,int size)
// int SUM(int si = 0,int a[], int size)
// But,in case of more than one default arguments,we can start them only from the end
// Eg, int SUM(int a[], int size, int si = 0,int en = 0)

int SUM(int a[], int size, int si = 0) // Here si(starting index) is the default argument
{                                      // even if it's just SUM(a,10), it won't give any error
    int ans = 0;                       // and will simply print the default sum of 10 nums
    for (int i = si; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }

    cout << SUM(a, 10, 5) << endl; // This gives the sum from the 5th index of the array
    cout << SUM(a, 10) << endl;    // This gives the sum of the whole array

    return 0;
}