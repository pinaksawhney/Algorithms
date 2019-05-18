// Linked List implementation of Queue
#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* front = nullptr;
node* rear = nullptr;

bool is_Empty();
void Enqueue(int data);
void Dequeue();
int Front();

int main(){
    int option{}; int data{};
    while (option != 5) {
        cout << "(1) Enqueue (2) Dequeue (3) Find Front (4) Is Queue Empty ? (5) Exit ";
        cin>>option;
        cout<<endl;
        if (option == 1) {
            cout << "Enter the data: "<<endl;
            cin >> data;
            Enqueue(data);
        } else if (option == 2) {
            cout << "Deleting from queue..."<<endl;
            Dequeue();
        } else if (option == 3) {
            cout<<Front();
            cout<<endl;
        } else if (option == 4) {
            cout<<is_Empty()<<endl;
        }
    }
    return 0;
}

bool is_Empty(){
    cout << boolalpha;
    if(front== nullptr){
        return true;
    }
    return false;
}

void Enqueue(int data){
    node* temp = new node();
    temp->next = nullptr;
    temp->data = data;
    if(is_Empty()){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

void Dequeue(){
    if(is_Empty()){
       cout << "Error: Queue Empty"<<endl;
    }
    else{
        node* temp = front;
        front = front->next;
        delete temp;
    }
}

int Front(){
    if(is_Empty()){
        return -1;}
    return front->data;
}
