//NOTE: To avoid shallow copy,create your own copy constructor

//1. We create an array(named datd) of size 5.
//2. If nextIndex == capacity, that means we've filled elements in data array
//3. Now we create a new dynamic array of double size(capacity)
//4. Copy all elements uptil now in the new array
//5. Delete the old array.
//6. We realize that the scope of new array is local so we won't be able to access it
// data --> array[](deleted, now random garbage)
// newarr --> array[double capacity]
//7. Therefore,we need the arrow of data array to point towards new array
//8. Capacity *= 2 => gets doubled as well
#include <iostream>
using namespace std;

class DynamicArray
{
    int *data; // dyanmically created array
    int nextIndex;
    int capacity; // total size

public:
    DynamicArray()
    {
        data = new int[5]; // let us say that the address of data array is 800
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(DynamicArray const &d)
    {
        // this->data = d.data; shallow copy

        //deep copy
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void operator=(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void add(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity]; // let's say the address of newData array is 900
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData; // now address of data is 900 as well
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int getElement(int i) const
    {
        if (i < nextIndex) // if array is size 3 and someone requires data[5],therefore it's a check for that
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }

    void add(int i, int element) // goin at particular index and place element at that index
    {
        if (i < nextIndex)
        {
            data[i] = element;
        }
        else if (i == nextIndex)
        {
            add(element);
        }
        else
        {
            return;
        }
    }

    void print() const
    { // ideally we should go upto nextIndex since we don't know whether our data array's capacity will be filled or not
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    DynamicArray d2(d1); // our own copy constructor

    DynamicArray d3;

    d3 = d1;

    d1.add(0, 100);

    d2.print();
    d3.print();

    return 0;
}