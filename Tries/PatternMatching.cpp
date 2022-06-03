/*Given a list of n words and a pattern p that we want to search.
Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.

Sample Input 1 :
4
abc def ghi cba
de
Sample Output 1 :
true

Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true

Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
            return true;
        else if (word.size() == 0)
            return false;

        int index = word[0] - 'a';

        if (root->children[index] != NULL)
            return search(root->children[index], word.substr(1));
        else
            return false;
    }

    bool search(string word)
    {
        // Write your code here
        return search(root, word);
    }

    bool patternMatching(vector<string> vect, string pattern)
    {
        // Write your code here
        for (int i = 0; i < vect.size(); i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
                insertWord(vect[i].substr(j));
            if (search(pattern))
                return true;
        }
        return false;
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}