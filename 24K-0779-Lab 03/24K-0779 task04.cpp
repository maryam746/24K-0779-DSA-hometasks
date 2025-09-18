#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string cname;
    string rname;
    Node* next;

    Node(int i, string c, string r) : id(i), cname(c), rname(r), next(nullptr) {}
};

class TicketSystem {
private:
    Node* head;

public:
    TicketSystem() : head(nullptr) {}

    void issuetail(int i, string c, string r) {
        Node* newnode = new Node(i, c, r);
        if (!head) {
            head = newnode;
            newnode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    void issuefront(int i, string c, string r) {
        Node* newnode = new Node(i, c, r);
        if (!head) {
            head = newnode;
            newnode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    void cancelticket(int i) {
        if (!head) return;
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->id == i) {
                if (temp == head) {
                    cancelhead();
                    return;
                }
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }

    void cancelhead() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        Node* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
    }

    void searchticket(int i) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->id == i) {
                cout << "Ticket ID: " << temp->id << ", Customer: " << temp->cname 
                     << ", Ride: " << temp->rname << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Ticket not found" << endl;
    }

    void display() {
        if (!head) {
            cout << "No tickets" << endl;
            return;
        }
        Node* temp = head;
        cout << "Tickets:" << endl;
        do {
            cout << "ID: " << temp->id << ", Customer: " << temp->cname 
                 << ", Ride: " << temp->rname << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void counttickets() {
        if (!head) {
            cout << "Total tickets: 0" << endl;
            return;
        }
        int cnt = 0;
        Node* temp = head;
        do {
            cnt++;
            temp = temp->next;
        } while (temp != head);
        cout << "Total tickets: " << cnt << endl;
    }

    void nextticket(int i) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->id == i) {
                cout << "Next Ticket -> ID: " << temp->next->id << ", Customer: " 
                     << temp->next->cname << ", Ride: " << temp->next->rname << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Ticket not found" << endl;
    }
};

int main() {
    TicketSystem t;

    t.issuetail(1, "Ali", "Roller Coaster");
    t.issuetail(2, "Sara", "Ferris Wheel");
    t.issuefront(3, "VIP Ahmed", "Haunted House");
    t.display();
    cout << endl;

    t.searchticket(2);
    t.nextticket(2);
    cout << endl;

    t.cancelticket(1);
    cout << "After cancelling ID 1:" << endl;
    t.display();
    cout << endl;

    t.cancelhead();
    cout << "After cancelling front:" << endl;
    t.display();
    cout << endl;

    t.counttickets();

    return 0;
}
