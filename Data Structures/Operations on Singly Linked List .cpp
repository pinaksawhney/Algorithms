#include <iostream>

using  namespace std;

struct node{
    int data{};
    node* next{nullptr};
};
node* head = nullptr;
void Insert(int);
void Print();
void Insert_at_n(int data, int n);
void delete_node(int position);
void reverse_list();
void Fprint(node* p);
void Rprint(node* p);
void Reverse_r(node* p);

int main() {
    int option{}; int data{};int pos{};
    while(option != 9)
    {   cout << "(1) To Add position wise (2) To add at the beginning (3) To Print current List (4) Delete node "
                "(5) Reverse List (6) Forward Print using Recursion (7) Reverse Print using Recursion "
                "(8) Reversing list using Recursion (9) Quit"<<endl;
        cin>>option;
        if (option == 1){
            cout << "Enter position: "<<endl;
            cin>>pos;
            cout << "Enter data: "<<endl;
            cin>>data;
            Insert_at_n(data,pos);
        }
        else if(option == 2){
            cout << "Enter data: "<<endl;
            cin>>data;
            Insert(data);
        }
        else if(option == 3 ){
            cout << "Current List: "<<endl;
            Print();
        }
        else if(option == 4){
            cout << "Enter the position to delete the node from: "<<endl;
            cin>>data;
            delete_node(data);
        }
        else if(option == 5){
            cout << "Reversing List... : "<<endl;
            reverse_list();
        }
        else if(option == 6){
            cout << "Forward List : "<<endl;
            Fprint(head);
        }
        else if(option == 7){
            cout << "Reverse List : "<<endl;
            Rprint(head);
        }
        else if(option == 8){
            cout << "Reversing List... "<<endl;
            Reverse_r(head);
        }
    }
    return 0;
}

void Insert(int data){
    node* temp = new node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void Print(){
    node* temp = head;
    cout << temp->data<<" ";
    while(temp->next != nullptr){
        temp = temp->next;
        cout << temp->data<<" ";
    }
}

void Insert_at_n(int data, int n) {
    node *temp1 = head;
    node *temp = new node();
        if (n == 0) {
            temp->data = data;
            temp->next = head;
            head = temp;
            return;
        } else {
            for (int i = 0; i < n - 1; i++) {
                temp1 = temp1->next;
            }
            temp->data = data;
            temp->next = temp1->next;
            temp1->next = temp;
        }
    }

void delete_node(int position){
    node* temp = head;
    if(position == 0){
        head = head->next;
        delete temp;
    }
    else{
        for(int i=0;i<position-1;i++){
            temp = temp->next;
        }
        node* temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
    }
}

void reverse_list(){
    node* previous = nullptr;
    node* current = head;
    node* next = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

// Traversing a linked list and printing elements in forward and reverse order using recursion

void Fprint(node* p){
    if(p == nullptr){
        return;
    }
    else{
        cout << p->data<<" ";
        Fprint(p->next);
    }
}
void Rprint(node* p){
    if(p== nullptr){
        return;
    }
    else{
        Rprint(p->next);
        cout<<p->data<<" ";
    }
}

// Reverse the list using recursive approach

void Reverse_r(node* p){
    if(p->next==nullptr){
        head = p;
        return;
    }
    Reverse_r(p->next);
    //statement to reverse a node
    node* q = p->next;
    q->next = p;
    p->next = nullptr;
}