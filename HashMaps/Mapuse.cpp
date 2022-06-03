#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    // Note: Unordered Map is inbuilt as a template, its data type needs to be specified
    unordered_map<string, int> ourMap;

    /*insert .... (key, value)*/
    // Method 1
    pair<string, int> p("abc", 1); // making pair of a string "abc" and int 1
    ourMap.insert(p);              // mapping string "abc" to 1

    // Method 2
    ourMap["def"] = 2;

    /*find or access*/
    cout << ourMap["abc"] << endl;    // output = 1;
    cout << ourMap.at("def") << endl; // output = 2;

    cout << "size : " << ourMap.size() << endl;

    /*Difference between 'at' keyword and []*/
    //cout << ourMap.at("ghi") << endl;   Not Allowed, it will give an "uncaught exception"
    cout << ourMap["ghi"] << endl; // in this case, if string is not there, compiler will insert "ghi" at 0 integer by default;output=0

    cout << "size : " << ourMap.size() << endl;

    /*Check presence*/
    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "Doesn't exist" << endl;
    }

    /*Erase*/
    ourMap.erase("ghi");

    cout << "size : " << ourMap.size() << endl;

    if (ourMap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }
    else
    {
        cout << "Doesn't exist" << endl;
    }

    return 0;
}