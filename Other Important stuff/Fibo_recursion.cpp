/*
#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 1;
    int c;

    int n;
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    cout << c << endl;

    return 0;
}*/
#include <iostream>
using namespace std;

//fibonacci sequence
// 0 1 1 2 3 5 8 13 21 34 55.....
// where 0 is the 0th term and 1 is the 1st term

int fibonacci(int n)
{
    if (n == 0 || n == 1) //lines 33 - 36
    {                     //if(n==0) return 0;
        return n;         //if(n==1) return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2); //since there're 2 function calls, we'll also need 2 base classes(line 33)
    }
}
int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}
