// Array implementation of Circular Queue
#include <iostream>
#define MAX_SIZE 9
using namespace std;

class Queue{
private:
    int A[MAX_SIZE];
    int front;
    int rear;
    bool is_Full(){
        if (front == (rear+1)%MAX_SIZE){
            cout << "Error: Queue is full"<<endl;
            return true;
        }
        return false;
    }
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    bool is_Empty(){
        cout << boolalpha;
        if (front==-1 && rear==-1)
            return true;
        else
            return false;
    }
    void enqueue(int data){
        if(is_Empty()){
            front = 0;
            rear = 0;}
        else if(is_Full()){
            return;}
        else{
            rear=(rear+1)%MAX_SIZE;}
        A[rear] = data;
    }
    void dequeue(){
        if(is_Empty()){
            cout << "Error: Queue Empty"<<endl;
            return;
        }
        else if(front==rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1)%MAX_SIZE;
        }
    }
    int Front(){
        if(front != -1) {
            return A[front];
        }
    }
};

int main(){
    Queue q;
    int option{}; int data{};
    while (option != 5) {
        cout << "(1) Enqueue (2) Dequeue (3) Find Front (4) Is Queue Empty ? (5) Exit ";
        cin>>option;
        cout<<endl;
        if (option == 1) {
            cout << "Enter the data: "<<endl;
            cin >> data;
            q.enqueue(data);
        } else if (option == 2) {
            cout << "Deleting from queue..."<<endl;
            q.dequeue();
        } else if (option == 3) {
            cout<<q.Front();
            cout<<endl;
        } else if (option == 4) {
            cout<<q.is_Empty()<<endl;
        }
    }
    return 0;
}