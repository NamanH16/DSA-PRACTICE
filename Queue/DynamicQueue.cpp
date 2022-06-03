#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray
{
    T *data;
    int nextIndex;  // at which index should the next element be inserted
    int firstIndex; // gives the value of the topmost element
    int size;
    int capacity;

public:
    QueueUsingArray(int totalSize)
    {
        data = new T[5];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 5;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    //insert element
    void enqueue(T element)
    {
        if (size == capacity)
        {
            int k = 0;
            T *newData = new T[2 * capacity];
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[k] = data[i];
                k++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[k] = data[i];
                k++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0) // when queue gets empty, reset them back
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main()
{
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;

    cout << q.isEmpty() << endl;

    return 0;
}