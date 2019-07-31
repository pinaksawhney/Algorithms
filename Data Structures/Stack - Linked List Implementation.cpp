#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class Stack{
private:
    node* top;
public:
    Stack(){
        top = nullptr;
    }
    void push(int data){
        node* newNode = new node();
        if(top == nullptr){
            newNode->data = data;
            top = newNode;
        }
        else{
            newNode->data = data;
            newNode->next = top;
            top = newNode;
        }
    }

    void Print(){
        node* temp = top;
        while(temp != nullptr){
            cout << temp->data<<" ";
            temp = temp->next;
        }
    }

    void pop(){
        node* temp = top;
        if(temp != nullptr){
            top = temp->next;
            delete temp;
        }
        else{
            cout << "Error: Stack Empty"<<endl;
        }
    }

    int Top(){
        return top->data;
    }

    bool is_empty(){
        cout<<boolalpha;
        return top==nullptr;
    }
};


int main(){
    Stack st;
    int option{};
    int data{};
    while (option != 6) {
        cout << "(1) Push (2) Pop (3) Find Top Element (4) Print the stack (5) Is Stack Empty ? (6) Exit ";
        cin>>option;
        cout<<endl;
        if (option == 1) {
            cout << "Enter the data: "<<endl;
            cin >> data;
            st.push(data);
        } else if (option == 2) {
            cout << "Popping..."<<endl;
            st.pop();
        } else if (option == 3) {
            cout<<st.Top();
            cout<<endl;
        } else if (option == 4) {
            st.Print();
        } else if (option == 5) {
            cout<<st.is_empty();
            cout<<endl;
        }
    }
}