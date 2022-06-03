#include <iostream>
using namespace std;

int main()
{
    int *p = new int;
    delete p;
    // pointer isn't being deleted,just the memory it is pointing to
    p = new int;
    delete p; //single element deletion

    p = new int[500];
    delete[] p; //deleting an array from heap

    return 0;
}