// Breadth First Traversal of Binary Tree
// BFS is done using queue as an auxillary data structure
#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* root = nullptr;
node* GetnewNode(int data);
node* Insert(node* root, int data);
void Breadth_first(node* root);

int main(){
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,12);
    root = Insert(root,17);
    root = Insert(root,25);
    root = Insert(root,11);
    root = Insert(root,9);
    Breadth_first(root);
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

void Breadth_first(node* root_ptr){
    queue<node*> q;
    if (root_ptr==nullptr){
        return;
    }
    else{
        q.push(root_ptr);
        while(!q.empty()){
            node* parent  = q.front();
            if(parent->left != nullptr) q.push(parent->left);
            if(parent->right != nullptr) q.push(parent->right);
            cout<<q.front()->data<<" ";
            q.pop();
        }
    }
}