#include <iostream>
#include <queue>
using namespace std;

// By default, max priority queue is built in
/*  Old functions made by us --> in Built functions*/
// isEmpty() --> empty()
// getSize() --> size()
// void insert(elem) --> void push(elem)
// getMin() --> T top()[will give the max element]
// T removeMin() --> void pop()

int main()
{
    priority_queue<int> pq;
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "Size: " << pq.size() << endl;
    cout << "Top: " << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}