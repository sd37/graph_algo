#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<list>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    uint32_t data;
    struct TreeNode* left;
    struct TreeNode* right;
};


class Tree
{
        unsigned int V;
        struct TreeNode* root;
    public:
        Tree();
        void levelOrderRec();
        void levelOrderQueue();
        struct TreeNode* addNode(uint32_t val,struct TreeNode* left , struct TreeNode* right);
        void setRoot(struct TreeNode*);
};

Tree::Tree()
{
    this->V = 0;
    this->root = NULL;
}

void Tree::setRoot(struct TreeNode* root)
{
    this->root = root;
}

struct TreeNode* Tree::addNode(uint32_t val,struct TreeNode* left , struct TreeNode* right)
{
    //returns the node just added
    struct TreeNode* new_node = new TreeNode;
    
    if(new_node == NULL)
    {
        perror("memory allocation failure\n");
    }
    new_node->data = val;
    new_node->left = left;
    new_node->right = right;
    this->V++;
    return new_node;
}

void Tree::levelOrderQueue()
{
       queue<struct TreeNode> q;

       q.push(*root);

       while(!q.empty())
       {
            struct TreeNode tmp = q.front();
            q.pop();
            
            cout << tmp.data << " ";

            if(tmp.left)
                q.push(*(tmp.left));
            
            if(tmp.right)
                q.push(*(tmp.right));
            
       }

}


int main()
{
    fflush(stdout);
    
    /*
                    10
                    / \
                   8  12
                 /  \  \  
                 6  9  13
     */
    Tree tr;
    struct TreeNode* n1 = tr.addNode(6,NULL,NULL);
    struct TreeNode* n2 = tr.addNode(9,NULL,NULL);
    struct TreeNode* n3 = tr.addNode(13,NULL,NULL);
    struct TreeNode* n4 = tr.addNode(8,n1,n2);
    struct TreeNode* n5 = tr.addNode(12,NULL,n3);
    struct TreeNode* n6 = tr.addNode(10,n4,n5);
    tr.setRoot(n6);
    
    tr.levelOrderQueue(); 
    printf("\n");
    return 0;
}
