#include <iostream>
#include <stack>
using namespace std;

class Call {
public:
    string name;
    string number;
    int duration;
};

class CallStack {
    stack<Call> st;
    
public:
    void push() {
        Call c;
        cout << "Enter name: ";
        cin >> c.name;
        cout << "Enter number: ";
        cin >> c.number;
        cout << "Enter duration: ";
        cin >> c.duration;
        st.push(c);
        show();
    }
    
    void pop() {
        if(st.empty()) {
            cout << "Stack empty" << endl;
            return;
        }
        st.pop();
        show();
    }
    
    void top() {
        if(st.empty()) {
            cout << "Stack empty" << endl;
            return;
        }
        Call c = st.top();
        cout << "Last call name: " << c.name << ", Number: " << c.number << ", Duration: " << c.duration << endl;
    }
    
    void empty() {
        if(st.empty())
            cout << "Call history is empty" << endl;
        else
            cout << "History is not empty" << endl;
    }
    
    void show() {
        if(st.empty()) {
            cout << "No calls" << endl;
            return;
        }
        
        stack<Call> temp = st;
        cout << "Call log:" << endl;
        while(!temp.empty()) {
            Call c = temp.top();
            cout << c.name << " " << c.number << " " << c.duration << endl;
            temp.pop();
        }
    }
};

int main() {
    CallStack cs;
    int choice;
    
    do {
        cout << "1.push 2.pop 3.top 4.empty 5.show 6.exit: ";
        cin >> choice;
        
        switch(choice) {
            case 1: cs.push(); break;
            case 2: cs.pop(); break;
            case 3: cs.top(); break;
            case 4: cs.empty(); break;
            case 5: cs.show(); break;
        }
    } while(choice != 6);
    
    return 0;
}
