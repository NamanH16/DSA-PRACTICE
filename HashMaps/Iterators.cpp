#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> ourMap;
    ourMap["abc"] = 1;
    ourMap["abc1"] = 2;
    ourMap["abc2"] = 3;
    ourMap["abc3"] = 4;
    ourMap["abc4"] = 5;
    ourMap["abc5"] = 6;

    // Since it's an unordered map, the iterator can print in any random order
    unordered_map<string, int>::iterator it = ourMap.begin();
    // 'it' is a pointer hence the'->' is used
    while (it != ourMap.end())
    {
        cout << "Key: " << it->first << " "
             << "Value: " << it->second << endl;
        it++;
    }

    // find function(inbuilt) actually gives out an iterator as output
    unordered_map<string, int>::iterator ki = ourMap.find("abc");

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    vector<int>::iterator it1 = v.begin();

    v.erase(it1, it1 + 3); // positions pointed by it1 will be erased,in this case(it1,it1+1,it1+2) are deleted

    while (it1 != v.end())
    {
        cout << *it1 << endl; // dereferncing since it1 only a pointer pointing to the 1st element
        it1++;
    }

    return 0;
}
