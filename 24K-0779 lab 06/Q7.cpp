#include <iostream>
using namespace std;

class Queue {
    string patrons[100];
    int front, rear, size;
    
public:
    Queue() {
        front = -1;
        rear = -1;
        size = 100;
    }
    
    bool isFull() {
        return rear == size - 1;
    }
    
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    
    void enqueue(string name) {
        if(isFull()) {
            cout << "Queue full" << endl;
            return;
        }
        if(front == -1) front = 0;
        rear++;
        patrons[rear] = name;
        cout << name << " joined queue" << endl;
    }
    
    void dequeue() {
        if(isEmpty()) {
            cout << "Queue empty" << endl;
            return;
        }
        cout << patrons[front] << " completed transaction" << endl;
        front++;
        if(front > rear) {
            front = -1;
            rear = -1;
        }
    }
    
    void display() {
        if(isEmpty()) {
            cout << "No patrons waiting" << endl;
            return;
        }
        cout << "Current queue: ";
        for(int i = front; i <= rear; i++) {
            cout << patrons[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice;
    string name;
    
    do {
        cout << "1. Add patron 2. Complete transaction 3. Show queue 4. Exit: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                q.enqueue(name);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
        }
    } while(choice != 4);
    
    return 0;
}
