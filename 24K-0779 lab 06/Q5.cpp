#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

class PrefixEval {
    stack<int> st;
    
public:
    void push(int val) {
        st.push(val);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int top = st.top();
        st.pop();
        return top;
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
    
    int evaluate(string exp) {
        for(int i = exp.length()-1; i >= 0; i--) {
            char c = exp[i];
            
            if(isdigit(c)) {
                st.push(c - '0');
            }
            else {
                int a = pop();
                int b = pop();
                
                switch(c) {
                    case '+': st.push(a + b); break;
                    case '-': st.push(a - b); break;
                    case '*': st.push(a * b); break;
                    case '/': st.push(a / b); break;
                    case '^': st.push(pow(a, b)); break;
                }
            }
        }
        
        int result = pop();
        if(!empty()) return -1;
        return result;
    }
};

int main() {
    PrefixEval p;
    string exp;
    
    cout << "Enter prefix expression: ";
    cin >> exp;
    
    int result = p.evaluate(exp);
    if(result == -1) {
        cout << "Invalid" << endl;
    } else {
        cout << "Result: " << result << endl;
    }
    
    return 0;
}
