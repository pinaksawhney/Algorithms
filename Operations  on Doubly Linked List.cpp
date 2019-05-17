#include <iostream>

using  namespace std;
struct node{
    int data;
    node* prev;
    node* next;
};
node* head{nullptr};

void InsertAtHead(int data);
node* GetNewNode(int data);
void Print();
void Reverse_Print();
void InsertAtTail(int data);
int main(){
    int option{};
    int data{};
    while(option != 5) {
        cout << "(1) Insert node at head (2) Insert node at Tail (3) Forward Print (4) Reverse Print (5) Exit ";
        cin >> option;
        if (option == 1) {
            cout << endl<<"Enter data: ";
            cin >> data;
            InsertAtHead(data);
        } else if (option == 2) {
            cout << endl<<"Enter data: ";
            cin >> data;
            InsertAtTail(data);
        }
        if (option == 3) {
            Print();
            cout<<endl;
        }
        if (option == 4) {
            Reverse_Print();
            cout<<endl;
        }
    }
    return 0;
}

void InsertAtHead(int data){
    node* newNode = GetNewNode(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

node* GetNewNode(int data){
    node* temp = new node();
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void Print(){
    node* temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void Reverse_Print(){
    struct node* temp = head;
    while(temp == nullptr){
        return;
    }
    while(temp->next != nullptr){
        temp = temp->next;
    }
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}

void InsertAtTail(int data){
    node* temp = head;
    node* newNode = GetNewNode(data);
    if(head== nullptr){
        head = newNode;
        return;
    }
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}