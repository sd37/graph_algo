//assuming that the count  == 0 in a node represents not a leaf
//  count > 0  value represents a leaf in a trie
//
#include<iostream>
#include<string.h>

#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int) 'a')
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

using namespace std;
struct TrieNode
{
    int val;
    struct TrieNode* child[ALPHABET_SIZE];
};

class Trie
{
    int count;
    struct TrieNode* root;
    struct TrieNode* getNode();
public:
    
    Trie();
    
    struct TrieNode* getRoot()
    {
        return this->root; //root is dummy node
    }

    void insert(char key[]);
    bool search(char key[]);

};

Trie::Trie()
{
    this->root = getNode();
    this->count = 0;
}

void Trie::insert(char key[])
{
    struct TrieNode* pTrieNode = getRoot();
    int level;
    int length = strlen(key);
    
    this->count++;

    for (level = 0; level < length; level++)
    {
        int index = CHAR_TO_INDEX(key[level]);
        
        if(!pTrieNode->child[index])
        {
            pTrieNode->child[index] = getNode();
            pTrieNode = pTrieNode->child[index];
        }
        else
        {
            pTrieNode = pTrieNode->child[index];
        }

    }
    //make last node as the leaf node

    pTrieNode->val = this->count;
}

bool Trie::search(char key[])
{
    struct TrieNode* pTrieNode = this->getRoot();
    
    int length = strlen(key);
    int i;

    for (i = 0; i < length; i++)
    {
        int index = CHAR_TO_INDEX(key[i]);

        if(!pTrieNode->child[index])
        {
            return false;
        }

        pTrieNode = pTrieNode->child[index];

    }

    return (pTrieNode != NULL && pTrieNode->val != 0);
}

struct TrieNode* Trie::getNode()
{
   struct TrieNode* pTrieNode = NULL;
   pTrieNode = new struct TrieNode;

   if(pTrieNode)
   {
       int i; 
       pTrieNode->val = 0;
       
       for(i = 0; i < ALPHABET_SIZE; i++)
       {
           pTrieNode->child[i] = NULL;
       }
   }
   
   return pTrieNode;
}

int main()
{
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    Trie trie;

    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        trie.insert(keys[i]);
    }

    if(trie.search("theis"))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}
