#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<list>
#include<vector>
#include<stack>

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
        struct TreeNode* addNode(uint32_t val,struct TreeNode* left , struct TreeNode* right);
        void setRoot(struct TreeNode*);
        void InOrder();
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

void Tree::InOrder()
{
    stack<struct TreeNode> st;
    
    struct TreeNode* current = root;

    while(!(current == NULL && st.empty()))
    {
        if(current)
        {
            while(current->left != NULL)
            {
                st.push(*current);
                current = current->left;
            }

            st.push(*current); //push the element for which current->left is false
        }
        
        struct TreeNode temp = st.top();
        st.pop();
        
        cout << temp.data << " ";

        current = temp.right;
    }
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
   
    tr.InOrder();
     
    printf("\n");
    Tree tr1;
    struct TreeNode* n11 = tr1.addNode(4,NULL,NULL);
    struct TreeNode* n22 = tr1.addNode(5,NULL,NULL);
    struct TreeNode* n33 = tr1.addNode(2,n11,n22);
    struct TreeNode* n44 = tr1.addNode(3,NULL,NULL);
    struct TreeNode* n55 = tr1.addNode(1,n33,n44);
    tr1.setRoot(n55);

    tr1.InOrder();
    printf("\n");
    return 0;
}
