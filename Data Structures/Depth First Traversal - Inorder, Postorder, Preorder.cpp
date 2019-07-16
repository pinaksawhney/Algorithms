/* Depth First Traversal - Preorder, Post order and Inorder Traversal
 Time Complexity - O(n)
 Space Complexity -  O(h) Best case h=log(n) Worst case h=n

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
void Preorder(node* root_ptr);
void Inorder(node* root_ptr);
void Postorder(node* root_ptr);

int main(){
    // sample insertions to form a tree
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,17);
    root = Insert(root,25);
    root = Insert(root,11);
    root = Insert(root,9);
    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);
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

void Preorder(node* root_ptr){
    if(root_ptr == nullptr)return;
    else{
        cout<<root_ptr->data<<" ";
        Preorder(root_ptr->left);
        Preorder(root_ptr->right);
    }
}

void Inorder(node* root_ptr){
    if(root_ptr == nullptr)return;
    else{
        Inorder(root_ptr->left);
        cout<<root_ptr->data<<" ";
        Inorder(root_ptr->right);
    }
}

void Postorder(node* root_ptr){
    if(root_ptr == nullptr)return;
    else{
        Postorder(root_ptr->left);
        Postorder(root_ptr->right);
        cout<<root_ptr->data<<" ";

    }
}