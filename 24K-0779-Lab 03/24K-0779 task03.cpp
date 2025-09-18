#include <iostream>
using namespace std;

class Node {
public:
    string item;
    int id;
    int price;
    Node *next;
    Node *prev;

    Node(string i, int p, int id) : item(i), id(id), price(p), next(nullptr), prev(nullptr) {}
};

class Ecommercestore {
private:
    Node *head;

public:
    Ecommercestore() : head(nullptr) {}

    void additematfront(string i, int p, int id) {
        Node *newnode = new Node(i, p, id);
        newnode->next = head;
        if (head != nullptr) {
            head->prev = newnode;
        }
        head = newnode;
    }

    void additematend(string i, int p, int id) {
        Node *newnode = new Node(i, p, id);
        if (!head) {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }

    void delfront() {
        if (!head) return;
        Node *temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void delend() {
        if (!head) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    void searchbyid(int id) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << temp->item << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found" << endl;
    }

    void updatepricebyid(int id, int np) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                temp->price = np;
                return;
            }
            temp = temp->next;
        }
    }

    void displayfront() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->item << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void displayend() {
        Node *temp = head;
        if (!temp) return;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << temp->item << " - $" << temp->price << endl;
            temp = temp->prev;
        }
    }

    void countitems() {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total items: " << count << endl;
    }

    void expensiveit() {
        if (!head) return;
        Node *temp = head;
        Node *expensive = head;
        while (temp != nullptr) {
            if (temp->price > expensive->price) {
                expensive = temp;
            }
            temp = temp->next;
        }
        cout << "Most expensive item: " << expensive->item << " - $" << expensive->price << endl;
    }
};

int main() {
    Ecommercestore cart;

    cart.additematend("Laptop", 1000, 1);
    cart.additematend("Phone", 700, 2);
    cart.additematfront("Headphones", 150, 3);
    cart.additematend("Tablet", 400, 4);

    cout << "Cart (front to end):" << endl;
    cart.displayfront();

    cout << endl << "Cart (end to front):" << endl;
    cart.displayend();

    cout << endl;
    cart.searchbyid(2);

    cart.updatepricebyid(2, 750);
    cout << "After price update:" << endl;
    cart.displayfront();

    cart.delfront();
    cout << endl << "After deleting front:" << endl;
    cart.displayfront();

    cart.delend();
    cout << endl << "After deleting end:" << endl;
    cart.displayfront();

    cart.countitems();
    cart.expensiveit();

    return 0;
}
