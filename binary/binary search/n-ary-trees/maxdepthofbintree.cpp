//To find the maximum depth of a binary tree
//leetcode qs

#include <bits/stdc++.h>
using namespace std;
 
 

class node
{
    public:
    int data;
    node* left;
    node* right;
};
 

int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
     
//driver code
int main()
{
    node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->left->right = newNode(7);
    root->left->left->left = newNode(29);
     
    cout << "Maximum depth of the given binary tree is " << maxDepth(root);
    return 0;
}