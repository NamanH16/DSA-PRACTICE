/*Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false*/
#include <iostream>
#include <string>
using namespace std;

#include <stack>
bool isBalanced(string expression)
{
    stack<char> s;

    int len = expression.length();

    for (int i = 0; i < len; i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if (s.empty())
            {
                return false;
            }

            char ch = s.top();
            s.pop();
            if (expression[i] == ')' && ch == '(')
            {
                continue;
            }
            else if (expression[i] == ']' && ch == '[')
            {
                continue;
            }
            else if (expression[i] == '}' && ch == '{')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}