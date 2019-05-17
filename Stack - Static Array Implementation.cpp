#include <iostream>
#define MAX_SIZE 101

using namespace std;

class Stack{
private:
    int top;
    int A[MAX_SIZE];
public:
    Stack(){
        top = -1;
    }

    void push(int data){
        if (top == MAX_SIZE-1){
            cout << "Error: Stack Overflow"<<endl;
        }
        else{
            A[++top] = data;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Error: Stack Empty"<<endl;
        }
        else{
            top-=1;
        }
    }

    int Top(){
        return A[top];
    }

    bool is_empty(){
        cout<<boolalpha;
        return top==-1;
    }

    void Print(){
        for(int i=top;i>=0;i--){
            cout << A[i]<<endl;
        }
    }
};

int main() {

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