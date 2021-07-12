// SYMMETRIC BINARY TREE
//leetcode qs

#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int data;
    Node* left;
    Node* right;
 
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
 

bool isSymmetric(struct Node* root)
{
    Node *cur1 = root, *cur2 = root;
 
    
    while (cur1 != NULL
           && cur2 != NULL) {
 
        if (cur1->left == NULL
            && cur2->right == NULL) {
 
            if (cur1->data != cur2->data)
                return false;
 
            cur1 = cur1->right;
            cur2 = cur2->left;
        }
 
        else if (cur1->left != NULL
                 && cur2->right != NULL) {
 
            Node* pre1 = cur1->left;
            Node* pre2 = cur2->right;
 
            while (pre1->right != NULL
                   && pre1->right != cur1
                   && pre2->left != NULL
                   && pre2->left != cur2) {
                pre1 = pre1->right;
                pre2 = pre2->left;
            }
 
            if (pre1->right == NULL
                && pre2->left == NULL) {
 
                
                pre1->right = cur1;
                pre2->left = cur2;
                cur1 = cur1->left;
                cur2 = cur2->right;
            }
 
            else if (pre1->right == cur1
                     && pre2->left == cur2) {
 
                // Unthreading the nodes
                pre1->right = NULL;
                pre2->left = NULL;
 
                if (cur1->data != cur2->data)
                    return false;
                cur1 = cur1->right;
                cur2 = cur2->left;
            }
            else
                return false;
        }
        else
            return false;
    }
 
    if (cur1 != cur2)
        return false;
 
    return true;
}
 
// Driver Code
int main()
{
    
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->right->left = new Node(9);
    root->right->right = new Node(8);
 
    if (isSymmetric(root))
        cout << "Symmetric tree";
    else
        cout << "Not Symmetric tree";
    return 0;
}