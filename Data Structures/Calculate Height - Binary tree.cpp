/*  Finding height of the Binary tree
    Height of a tree is defined as Maximum Length of the path from root node to leaves.
    Time Complexity : O(n)
 */

#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* root = nullptr;
node* GetnewNode(int data);
node* Insert(node* root, int data);
int height(node* root);

int main(){
    // inserting sample nodes in tree to calculate height
    // this can be taken as an input from user as well
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,17);
    root = Insert(root,25);
    root = Insert(root,11);
    root = Insert(root,9);

    cout<<height(root);
    return 0;
}

node* GetnewNode(int data){
    node* newNode = new node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return  newNode;
}

node* Insert(node* root_ptr, int data){
    if(root_ptr == nullptr){
        root_ptr = GetnewNode(data);
    }
    else if(root_ptr->data<data){
        root_ptr->right = Insert(root_ptr->right,data);
    }
    else if(root_ptr->data>=data){
        root_ptr->left = Insert(root_ptr->left,data);
    }
    return root_ptr;
}

int height(node* root_ptr){
    if(root_ptr == nullptr){
        return -1;
    }
    else{
        return max(height(root_ptr->left),height(root_ptr->right)) + 1;
    }
}
