//second largest element in n-ary-tree


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    vector<Node*> child;
};

Node * newNode(int value)
{
    Node* temp = new Node;
    temp->value = value;
    return temp;
}

void secondlargestUtil(Node* root, Node**first, Node** second)
{
    if (root == NULL)
        return;
    if(!(*first))
        *first = root;

    else if (root->value>(*first)->value){
        *second = *first;
        *first = root;
    }

    else if (!(*second))
    {
        if (root -> value < (*first) ->value)
        {
            *second = root;
        }
    }

    else if (root->value < (*first)->value && root->value > (*second) ->value)
    {
        *second = root;
    }

    int childnum = root -> child.size();

    for( int i=0;i<childnum;i++)
    {
        secondlargestUtil(root->child[i], first, second);
    }

}

Node * secondlargest(Node * root)
{
    Node* second = NULL;
    Node* first = NULL;
    secondlargestUtil(root, &first, &second);

    if(second == NULL)
    {
        return NULL;
    }
    return second;
}

int main()
{
    Node* root = newNode(10);
    (root ->child).push_back(newNode(5));
    (root ->child).push_back(newNode(8));
    (root ->child).push_back(newNode(12));
    (root->child[0]->child).push_back(newNode(20));
    (root->child[1]->child).push_back(newNode(30));
    (root->child[1]->child).push_back(newNode(14));
    (root->child[2]->child).push_back(newNode(6));

    if (secondlargest(root) != NULL){
        cout<<" Second largest element in the tree is:"<<secondlargest(root)->value <<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}