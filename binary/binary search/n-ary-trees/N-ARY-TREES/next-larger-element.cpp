#include <bits/stdc++.h>
using namespace std;
 

struct Node {
    int val;
    vector<Node*> child;
};
 
// Utility function to create a new tree node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->val = val;
    return temp;
}
 
void nextLargerElementUtil(Node* root, int x, Node** res)
{
    if (root == NULL)
        return;
 
    
    if (root->val > x)
        if (!(*res) || (*res)->val > root->val)
            *res = root;   
 
    
    int numChildren = root->child.size();
 
    for (int i = 0; i < numChildren; i++)
        nextLargerElementUtil(root->child[i], x, res);
 
    return;
}
 
Node* nextLargerElement(Node* root, int x)
{
    Node* res = NULL;
    nextLargerElementUtil(root, x, &res);
 
    return res;
}
 
// Driver program
int main()
{
   
 
    Node* root = newNode(6);
    (root->child).push_back(newNode(1));
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(3));
    (root->child[0]->child).push_back(newNode(56));
    (root->child[1]->child).push_back(newNode(5));
    (root->child[1]->child).push_back(newNode(6));
    (root->child[2]->child).push_back(newNode(9));
 
    int y = 5;
    
 
    cout << "The required Next larger element of " << y << " is ";
    cout << nextLargerElement(root, y)->val << endl;
 
    return 0;
}