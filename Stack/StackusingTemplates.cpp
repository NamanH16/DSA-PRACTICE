// Array can be modified to make it act as a stack
#include <iostream>
#include <limits.h>
using namespace std;

template <typename T>

class StackUsingArray
{
private:
    T *data; // we do not know the size of the array. Therefore, we have dynamically allocated our array{int *data = new int[n]}
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new T[4];
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
            T *newData = new T[2 * capacity];
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
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // returns the topmost element
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    StackUsingArray<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;

    return 0;
}