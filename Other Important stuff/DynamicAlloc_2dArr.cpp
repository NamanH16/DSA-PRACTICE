/*#include <iostream>
using namespace std;

int main()
{
    // creating 2-d array of 10 rows and 20 columns
    int **arr = new int *[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new int[20];
    }

    return 0;
}*/
#include <iostream>
using namespace std;

int main()
{
    // creating 2-d array of m rows and n columns
    int m, n;
    cin >> m >> n;
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}