#include <stdio.h>
#include <stdlib.h>

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node * minValue(struct node* node); 

struct node * inOrderSuccessor(struct node *root, struct node *n)
{
    if(n->right!=NULL)
        return minValue(n->right);
    else
    {
        //then we have to look at the first ancestor travelling up from which we entered into the left subtree.
        //in other words we traverse up and return the parent of a node for which the following condition holds true.
        //i.e n == p->left
    
        struct node* p = n->parent;

        while(p!=NULL)
        {
            if(n == p->left)
                break;
            n = p;
            p = p->parent;
        }
        
        return p;
    }
}

struct node* inOrderSuccessorwoparent(struct node*root,struct node *n)
{
    if(n->right != NULL)
        return minValue(n->right);
    
    else
    {
        //search from the root. Keep track of the last time you entered a left subtree.
        struct node* succ = NULL;
        
        while(root)
        {
            if(root->data > n->data)
            {
                succ = root; //update last succ seen 
                root = root->left;
            }
            else if(root->data < n->data)
            {
                root = root->right;
            }
            else
            {
                break;
            }
        }
        
        return succ;
    }

}

/* Given a non-empty binary search tree, return the minimum data  
    value found in that tree. Note that the entire tree does not need
    to be searched. */
struct node * minValue(struct node* root) 
{
    struct node* temp = root;

    if(temp == NULL)
        return NULL;
    
    while(temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

/* Helper function that allocates a new node with the given data and 
    NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;

  return(node);
}

/* Give a binary search tree and a number, inserts a new node with    
    the given number in the correct place in the tree. Returns the new
    root pointer which the caller should then use (the standard trick to 
    avoid using reference parameters). */
struct node* insert(struct node* node, int data)
{
/* 1. If the tree is empty, return a new,
      single node */
if (node == NULL)
    return(newNode(data));
  else
  {
    struct node *temp; 

    /* 2. Otherwise, recur down the tree */
    if (data <= node->data)
    { 
         temp = insert(node->left, data);
         node->left = temp;
         temp->parent= node;
    }
    else
    {
    temp = insert(node->right, data);
        node->right = temp;
        temp->parent = node;
    } 
    
    /* return the (unchanged) node pointer */
    return node;
  }
} 

/* Driver program to test above functions*/
int main()
{
struct node* root = NULL, *temp, *succ;

//creating the tree given in the above diagram
 root = insert(root, 20);
 root = insert(root, 8);
 root = insert(root, 22);
 root = insert(root, 4);
 root = insert(root, 12);
 root = insert(root, 10); 
 root = insert(root, 14);
 temp = root->left->right->right;

 //succ = inOrderSuccessor(root, temp);
 succ = inOrderSuccessorwoparent(root,temp);
 if(succ != NULL)
  printf("\n Inorder Successor of %d is %d ", temp->data, succ->data);
 else
  printf("\n Inorder Successor doesn't exit");

 getchar();
 return 0;
}
