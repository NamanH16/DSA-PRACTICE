/*You are given an array of unique integers that contain numbers in random order. 
You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. 
If the length of the longest possible sequence is one, then the output array must contain only single element.

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    // Your Code goes here
    unordered_map<int, bool> m;
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) // special handle for duplicates
    {
        m[arr[i]] = true;
        if (index.count(arr[i]) == 0)
            index[arr[i]] = i;
    }

    int start = -1;
    int size = 0;

    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] == false) // if already visted continue;
            continue;

        int nsize = 0, nstart = arr[i];
        int j = arr[i];

        while (m.count(j) > 0 && m[j] == true) //forward  (if present and not visited)
        {
            nsize += 1;
            m[j] = false;
            j++;
        }
        // cout<<nsize<<" "<< nstart << " ";
        j = arr[i] - 1;

        while (m.count(j) > 0 && m[j] == true) //backward   (if present and not visited)
        {
            nstart = j;
            nsize += 1;
            m[j] = false;
            j--;
        }
        // cout<< nsize<<" " <<size<<" "<<start<<" " << nstart<<endl;
        if (nsize >= size) //update
        {
            if (size == nsize) // the starting point comes first in input array.
            {
                if (index[start] > index[nstart])
                    start = nstart;
            }
            else
                start = nstart;

            size = nsize;
        }
        // cout<< nsize<<" " <<size<<" "<<start<<" " << nstart<<endl;
    }
    vector<int> v;
    for (int i = 0; i < size; i++)
        v.push_back(start), start++;

    return v;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1)
    {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}