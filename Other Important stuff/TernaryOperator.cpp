#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int c = (a > b) ? a : b; //max of two
    int d = (a > b) ? b : a; //min of two

    /*    if (a > b)
    {
        c = a;
    }
    else
    {
        c = b;
    }
*/

    // But tbh ,we do take atleast a sec to actually understand what's going on in lines 9 and 10. Thus,they might not be the best way
    // to write code efficiently
    // To improve this, we can actually create a function
    // Eg: int Max(int a,int b){
    //    return(a > b)?a:b;
    //  }
    return 0;
}