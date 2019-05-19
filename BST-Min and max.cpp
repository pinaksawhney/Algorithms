// Iterative and Recursive solutions for finding Max and Min nodes in BST.
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
int min_i(node* root);
int max_i(node* root);
int min_r(node* root);
int max_r(node* root);

int main(){
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,17);
    root = Insert(root,25);
    cout<<min_r(root)<<endl;
    cout<<max_r(root)<<endl;
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

// Iterative approach

int min_i(node* root_ptr){
    if(root_ptr == nullptr){
        cout << "Error: Tree Empty"<<endl;
        return -1;
    }
    while(root_ptr->left != nullptr){
        root_ptr = root_ptr->left;
    }
    return root_ptr->data;
}

int max_i(node* root_ptr){
    if(root_ptr == nullptr){
        cout << "Error: Tree Empty"<<endl;
        return -1;
    }
    while(root_ptr->right != nullptr){
        root_ptr = root_ptr->right;
    }
    return root_ptr->data;
}

// Recursive Approach

int min_r(node* root_ptr){
    if(root_ptr == nullptr){
        cout << "Error: Tree Empty"<<endl;
        return -1;}
    else if(root_ptr->left == nullptr){
        return root_ptr->data;
    }
    else{
        return min_r(root_ptr->left);
    }
}
int max_r(node* root_ptr){
    if(root_ptr == nullptr){
        cout << "Error: Tree Empty"<<endl;
        return -1;
    }
    else if(root_ptr->right == nullptr){
        return root_ptr->data;
    }
    else{
        return max_r(root_ptr->right);
    }
}