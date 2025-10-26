#include <iostream>
#include <stack>
#include <string>
using namespace std;

class PostfixEval {
    stack<int> st;
    
public:
    void push(int val) {
        st.push(val);
    }
    
    int pop() {
        if(st.empty()) {
            cout << "Error" << endl;
            return -1;
        }
        int top = st.top();
        st.pop();
        return top;
    }
    
    int top() {
        if(st.empty()) {
            cout << "Error" << endl;
            return -1;
        }
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
    
    int evaluate(string exp) {
        for(int i = 0; i < exp.length(); i++) {
            char c = exp[i];
            
            if(c == ' ') continue;
            
            if(isdigit(c)) {
                int num = 0;
                while(isdigit(exp[i])) {
                    num = num * 10 + (exp[i] - '0');
                    i++;
                }
                i--;
                push(num);
            }
            else {
                int b = pop();
                int a = pop();
                
                switch(c) {
                    case '+': push(a + b); break;
                    case '-': push(a - b); break;
                    case '*': push(a * b); break;
                    case '/': push(a / b); break;
                }
            }
        }
        
        int result = pop();
        if(!empty()) {
            cout << "Invalid expression" << endl;
            return -1;
        }
        return result;
    }
};

int main() {
    PostfixEval p;
    string exp;
    
    cout << "Enter postfix expression: ";
    getline(cin, exp);
    
    int result = p.evaluate(exp);
    if(result != -1) {
        cout << "Result: " << result << endl;
    }
    
    return 0;
}
