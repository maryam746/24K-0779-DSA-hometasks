#include <iostream>
using namespace std;

class Node {
public:
    string item;
    int price;
    Node* next;

    Node(string i, int p) : item(i), price(p), next(nullptr) {}
};

class Shoppingcart {
private:
    Node* head;

public:
    Shoppingcart() : head(nullptr) {}

    void additematfront(string i, int p) {
        Node* newnode = new Node(i, p);
        newnode->next = head;
        head = newnode;
    }

    void additematend(string i, int p) {
        Node* newnode = new Node(i, p);
        if (!head) {
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void additematpos(string afteritem, string i, int p) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->item == afteritem) {
                Node* newnode = new Node(i, p);
                newnode->next = temp->next;
                temp->next = newnode;
                return;
            }
            temp = temp->next;
        }
    }

    void search(string i) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->item == i) {
                cout << "Item found: " << temp->item << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->item << " - $" << temp->price << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Shoppingcart cart;
    cart.additematend("Laptop", 1000);
    cart.additematend("Phone", 700);
    cart.additematend("Tablet", 400);
    cart.additematend("Headphones", 150);

    cart.additematfront("Smartwatch", 200);
    cart.additematend("Keyboard", 80);
    cart.additematpos("Phone", "Monitor", 300);

    cart.search("Tablet");

    cout << "Cart: " << endl;
    cart.display();

    return 0;
}
