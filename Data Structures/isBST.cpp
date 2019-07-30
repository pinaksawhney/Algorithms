#include <iostream>
#include <vector>

using namespace std;

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class node
{
public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int isBSTUtil(node* node, int min, int max);

int isBST(node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}


int isBSTUtil(node* node, int min, int max) {
    if (node == nullptr)
        return 1;

    if (node->data < min || node->data > max)
        return 0;

    return isBSTUtil(node->left, min, node->data - 1) && isBSTUtil(node->right, node->data, max);
}

int main(){
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    cout<<isBST(root);
    return 0;
}