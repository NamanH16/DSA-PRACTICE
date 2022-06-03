/*You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; 
An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words,
 when there is a common value that exists in both the arrays/lists.
 
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2
3 
4
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 
*/

/*ALGORITHM
1. Build the hashmap for the nums1, that is, count the frequency of each element.
2. Traverse each element of nums2, one by one.
3. If the element is present in the map formed in step 1, reduce the frequency of the element by 1
and print the element, if the frequency becomes 0, remove the element from the map.
4. Repeat step 3 for all elements of nums2.

For more reference:
https://favtutor.com/blogs/intersection-of-two-arrays-using-hashmap
*/
#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int *arr1, int *arr2, int n, int m)
{
    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++)
    {
        myMap[arr1[i]]++;
    }

    for (int j = 0; j < m; j++)
    {
        if (myMap[arr2[j]] > 0)
        {
            myMap[arr2[j]]--;
            cout << arr2[j] << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr1 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int *arr2 = new int[m];

    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}