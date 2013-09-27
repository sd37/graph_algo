#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<list>
#include<vector>
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
        void InOrder(struct TreeNode*,vector<struct TreeNode> &v_list);
        bool isSorted(vector<struct TreeNode>&);    
    public:
        Tree();
        bool isBst();
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

void Tree::InOrder(struct TreeNode* root,vector<struct TreeNode> &v_list)
{
    if(root)
    {
        InOrder(root->left,v_list);
        v_list.push_back(*root);
        InOrder(root->right,v_list);
    }

}

bool Tree::isBst()
{
    vector<struct TreeNode> inorder_traversal;
    this->InOrder(this->root,inorder_traversal);
    return isSorted(inorder_traversal);
}

bool Tree::isSorted(vector<struct TreeNode>& v_list)
{
    for(unsigned int i = 1; i < v_list.size() ; i++)
    {
        if(v_list[i-1].data > v_list[i].data)
            return false;
    }

    return true;
}

int main()
{
    fflush(stdout);

    Tree tr;
    struct TreeNode* n1 = tr.addNode(6,NULL,NULL);
    struct TreeNode* n2 = tr.addNode(9,NULL,NULL);
    struct TreeNode* n3 = tr.addNode(13,NULL,NULL);
    struct TreeNode* n4 = tr.addNode(8,n1,n2);
    struct TreeNode* n5 = tr.addNode(12,NULL,n3);
    struct TreeNode* n6 = tr.addNode(10,n4,n5);
    tr.setRoot(n6);
    
    if(tr.isBst())    
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    
    printf("\n");
    return 0;
}
