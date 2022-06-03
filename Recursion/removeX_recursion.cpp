#include <bits/stdc++.h>
using namespace std;
/* Non recursive solution
void helper(char* s, char c)
{
    
    int len = 0;
    while(s[len]){
        len++;
    }
    int j = 0;
    int n = len;
    for(int i = j = 0;i < n; i++){
        if(s[i] != c){
            s[j++] = s[i];
        }
    }
    
    s[j] = '\0';
    
}
*/
string remX(char str[], char a)
{
    int len = strlen(str);
    if (len == 0)
    {
        return " ";
    }
    if (str[0] == a)
    {
        return remX(str + 1, a);
    }

    return str[0] + remX(str + 1, a);
}

int main()
{
    char str[100];
    cin >> str;

    cout << remX(str, 'x');

    return 0;
}