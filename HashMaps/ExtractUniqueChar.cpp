/*Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once.
 The respective order of characters should remain same, as in the input string.
Sample Input 1 :
ababacd

Sample Output 1 :
abcd

Sample Input 2 :
abcde
Sample Output 2 :
abcde*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string uniqueChar(string str)
{
    unordered_map<char, bool> unique;
    int i = 0;
    string ans;
    while (str[i] != '\0')
    {
        if (unique.count(str[i]) > 0)
        {
            i++;
            continue;
        }
        unique[str[i]] = true;
        ans += str[i];
        i++;
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}