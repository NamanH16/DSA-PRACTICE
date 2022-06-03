// Array can be modified to make it act as a stack
#include <iostream>
#include <limits.h>
using namespace std;

class StackUsingArray
{
private:
    int *data; // we do not know the size of the array. Therefore, we have dynamically allocated our array{int *data = new int[n]}
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0; // initialized to 0,since 1st element should go to 0th index
        capacity = totalSize;
    }

    // return the number of elements present in my stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        /*
        if (nextIndex == 0)
        {
            return true;
        }
        else
        {
            return false;
        }*/
        return nextIndex == 0; // shorter version of the if-else above
    }

    //insert element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack is full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // delete element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // returns the topmost element
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    StackUsingArray s1(4);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << s1.top() << endl; //40

    cout << s1.pop() << endl; //40
    cout << s1.pop() << endl; //30
    cout << s1.pop() << endl; //20

    cout << s1.size() << endl; //1

    cout << s1.isEmpty() << endl; //false,so 0

    return 0;
}