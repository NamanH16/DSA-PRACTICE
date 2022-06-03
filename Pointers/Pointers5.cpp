// Pointers and Functions
#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void IncrementPointer(int *p)
{
    p = p + 1;
}

void Increment(int *p)
{
    (*p)++;
}

int main()
{
    int i = 10;
    int *p = &i;

    print(p);

    cout << p << endl;
    IncrementPointer(p);
    cout << p << endl;

    cout << *p << endl;
    Increment(p);
    cout << *p << endl;

    return 0;
}