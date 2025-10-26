#include <iostream>
#include <stack>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) : url(u), next(nullptr) {}
};

class Browser {
    Node* head;
    stack<string> st;
    
public:
    Browser() : head(nullptr) {}
    
    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
        st.push(url);
    }
    
    void back() {
        if(head == nullptr || st.empty()) {
            cout << "Cannot go back" << endl;
            return;
        }
        
        string backUrl = st.top();
        st.pop();
        
        Node* temp = head;
        head = head->next;
        delete temp;
        
        cout << "Back to: " << (head ? head->url : "home") << endl;
    }
    
    void showHistory() {
        cout << "Current history: ";
        Node* curr = head;
        while(curr) {
            cout << curr->url << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    void showStack() {
        stack<string> temp = st;
        cout << "Stack: ";
        while(!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Browser b;
    
    b.visit("Google");
    b.visit("Facebook");
    b.visit("Twitter");
    b.visit("LinkedIn");
    b.visit("Instagram");
    
    cout << "visiting all sites:" << endl;
    b.showHistory();
    b.showStack();
    
    cout << "\nClicking back button twice:" << endl;
    b.back();
    b.back();
    
    cout << "\nFinal state:" << endl;
    b.showHistory();
    b.showStack();
    
    return 0;
}
