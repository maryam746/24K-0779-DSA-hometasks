#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;
    
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += c;
        }
        else if(c == '(') {
            st.push('(');
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prec(c) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << exp << endl;
    cout << "Postfix: " << infixToPostfix(exp) << endl;
    return 0;
}
