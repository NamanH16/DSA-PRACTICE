#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int Subsequence(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    //let the input be "abc"
    string smallString = input.substr(1);                   //smallstring = "bc"
    int smallOutputSize = Subsequence(smallString, output); // calling recursion on rest of the string
    for (int i = 0; i < smallOutputSize; i++)
    {                                                       // copying the recursive answer below and adding first char to it.
        output[i + smallOutputSize] = input[0] + output[i]; //input[0] = "a",output[i] =  ("" ,c, b, bc)
    }
    return 2 * smallOutputSize; //earlier they were 4,but now they've doubled to 8
}

int main()
{
    string input;
    cin >> input;
    int k = input.size();
    int n = pow(2, k);
    string *output = new string[n];
    int count = Subsequence(input, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    delete[] output;

    return 0;
}