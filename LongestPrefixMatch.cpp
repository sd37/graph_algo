#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define CHAR_TO_INDEX(c) c - 'a' 
#define AS 26

struct TrieNode
{
    int val;
    struct TrieNode* child[26];
};

class Trie
{
    int K;
    struct TrieNode* root; // root is the dummy node
    struct TrieNode* createNode(int val);
public:
    Trie();
    void insert(string s);
    string getLongestMatch(string s);
};

Trie::Trie()
{
   this->K = 0;
   this->root = createNode(-1);
}

void Trie::insert(string s)
{
    this->K++;
    struct TrieNode* temp = root;

    int len = s.length();
    
    for(int i = 0; i < len; i++)
    {
        int ci = CHAR_TO_INDEX(s[i]);
        
        if(temp->child[ci] == NULL)
        {
            temp->child[ci] = createNode(0);    
        }

        temp = temp->child[ci];
    }

    temp->val = K;
}

string Trie::getLongestMatch(string s)
{
    int len  = s.length();
    
    struct TrieNode* temp = root;
    pair<int,string> ansp;
    int count = 0;
    for(int i = 0; i < len; i++)
    {
       int ci = CHAR_TO_INDEX(s[i]); 
       temp = temp->child[ci];
       count++;
       if(temp == NULL)
           break;
       if(temp->val != 0 )
       {
           ansp.first = count;
           ansp.second = s.substr(0,i + 1);
       }
    }
    
    return ansp.second;
}

struct TrieNode* Trie::createNode(int val)
{
    struct TrieNode* temp = new struct TrieNode;
    
    temp->val = val;
    
    for(int i = 0; i < AS; i++)
    {
        temp->child[i] = NULL;
    }

return temp;
}

class SolnLongestPrefixMatch
{
    Trie dict;

public:
    SolnLongestPrefixMatch(vector<string> &ls);
    string ans(string s);
};

SolnLongestPrefixMatch::SolnLongestPrefixMatch(vector<string> &ls)
{
    for(int i = 0; i < ls.size(); i++)
    {
        dict.insert(ls[i]);
    }
}

string SolnLongestPrefixMatch::ans(string s)
{
    return dict.getLongestMatch(s);
}

int main()
{
    vector<string> v({"are","area","base","cat","cater","basement"});
    SolnLongestPrefixMatch slpm(v);
    cout << slpm.ans("caterer") << endl;
    cout << slpm.ans("basement") << endl;
    cout << slpm.ans("are") << endl;
    cout << slpm.ans("arex") << endl;
    cout << slpm.ans("basemexz") << endl;
    cout << slpm.ans("xyz");
    return 0;
}
