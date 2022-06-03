#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // strings are classes. The difference between character arrays and strings is that,
    // issues like taking input for each char individually and taking care of null character, is already taken care by strings.
    // strings can be treated exactly as arrays
    string *sp = new string;
    *sp = "abcde";

    cout << sp << endl;
    cout << *sp << endl;

    string k = "fgh";

    cout << k.length() << endl;

    string l = k + *sp;

    cout << l << endl;
    cout << l[3] << endl;

    cout << l.substr(4) << endl;
    cout << l.substr(3, 3) << endl; // (start,length)

    cout << l.size() << endl;
    cout << l.find("abc") << endl;

    return 0;
}