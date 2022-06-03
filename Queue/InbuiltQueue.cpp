#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << q.front() << endl; //10
    q.pop();
    cout << q.front() << endl; //20
    cout << q.size() << endl;  //5
    cout << q.empty() << endl; //0,since it's not empty

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}