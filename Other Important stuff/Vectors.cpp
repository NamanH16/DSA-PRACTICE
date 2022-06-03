#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //vector<int> *dv = new vector<int>();
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(90);
    v.push_back(170);

    v[1] = 100;

    cout << v[0] << " " << v[1] << " " << v[2] << endl;

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    cout << v.at(0) << " " << v.at(2) << endl;

    v.pop_back();

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}