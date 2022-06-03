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
    StackUsingArray()
    {
        data = new int[4];
        nextIndex = 0; // initialized to 0,since 1st element should go to 0th index
        capacity = 5;
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
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;  // deallocating the previous array
            data = newData; // making the old array point to the new array
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
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl; //50

    cout << s.pop() << endl; //50
    cout << s.pop() << endl; //40
    cout << s.pop() << endl; //30

    cout << s.size() << endl; //2

    cout << s.isEmpty() << endl; //false,so 0

    return 0;
}