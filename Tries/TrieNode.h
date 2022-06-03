#include <iostream>
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
        //since there're 26 letters, therefore each node can have upto a max of 26 children
        children = new TrieNode *[26]; // creating an array to store the values of addresses of children
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};