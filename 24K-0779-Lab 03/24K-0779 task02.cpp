#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int price;
    Node *next;
    Node(string n, int p) : name(n), price(p), next(nullptr) {}
};

class ShoppingCart {
private:
    Node *head;

public:
    ShoppingCart() : head(nullptr) {}

    void additemattail(string n, int p) {
        Node *newnode = new Node(n, p);
        if (!head) {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void deletefromfront() {
        if (!head) return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void searchbyname(string n) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->name == n) {
                cout << temp->name << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found" << endl;
    }

    void searchbypos(int pos) {
        Node *temp = head;
        int count = 1;
        while (temp != nullptr) {
            if (count == pos) {
                cout << temp->name << " - $" << temp->price << endl;
                return;
            }
            count++;
            temp = temp->next;
        }
        cout << "Invalid position" << endl;
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->name << " - $" << temp->price << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.additemattail("Laptop", 1000);
    cart.additemattail("Phone", 700);
    cart.additemattail("Tablet", 400);
    cart.additemattail("Headphones", 150);

    cart.display();
    cart.deletefromfront();
    cart.display();
    cart.searchbyname("Tablet");
    cart.searchbypos(2);
}
