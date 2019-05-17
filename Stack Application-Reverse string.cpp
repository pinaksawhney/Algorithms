// Reversing a string using stack
// Space Complexity: O(n)
// Time Complexity: O(n) : n extra space in the form of stack

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void Stack_Reverse(string str){
    stack<char> st;
    for(auto i: str){
        st.push(i);
    }

    for(int i=0;i<str.length();i++){
        str[i] = st.top();
        st.pop();
    }
    cout<<str;
}

// Efficient reversing of string
// Space Complexity: O(1)
// Time Complexity: O(n) : n extra space in the form of stack

void Reverse_efficient(string str){
 char i = 0;
 char j = str.length()-1;
 char temp;
while (i<j){
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
}
cout<<str;
}


int main(){
    Stack_Reverse("East or West");
    cout<<endl;
    Reverse_efficient("This will work too.");
    return 0;
}
