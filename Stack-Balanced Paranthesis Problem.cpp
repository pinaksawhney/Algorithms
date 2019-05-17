#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool is_paranthseisBalanced(string expr) {
    cout << boolalpha;
    stack<char> st;
    for (char i:expr) {
        if (i == '(' || i == '[' || i == '{') {
            st.push(i);
        } else if (i == ')' || i == ']' || i == '}') {
            if (st.empty()) {
                return false;
            } else {
                if ((i == ')' && st.top() != '(') || (i == ']' && st.top() != '[') || (i == '}' && st.top() != '{')) {
                    return false;
                }
                st.pop();
            }
        }
    }
    return st.empty();
}

int main(){
    cout<< is_paranthseisBalanced("[{)}]");
    return 0;
}