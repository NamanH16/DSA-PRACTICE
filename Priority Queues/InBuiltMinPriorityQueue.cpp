#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(100);
    pq.push(21);
    pq.push(7);
    pq.push(165);
    pq.push(78);
    pq.push(4);

    cout << "Size: " << pq.size() << endl;
    cout << "Min Element: " << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}