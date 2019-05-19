// Binary Search Tree Recursive Implementation
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
bool Search_binary(node* root, int data);

int main(){
    root = Insert(root,5);
    root = Insert(root,3);
    root = Insert(root,10);
    root = Insert(root,15);
    cout<<Search_binary(root,3)<<endl;
    cout<<Search_binary(root,5)<<endl;
    cout<<Search_binary(root,15)<<endl;
    cout<<Search_binary(root,10)<<endl;
    cout<<Search_binary(root,100)<<endl;
    cout<<Search_binary(root,23)<<endl;

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

bool Search_binary(node* root, int data){
    cout << boolalpha;
    if(root== nullptr){
        return false;
    }
    else if(root->data==data){
        return true;
    }
    else if(root->data<data){
        Search_binary(root->right,data);
    }
    else if(root->data>data){
        Search_binary(root->left,data);
    }
}