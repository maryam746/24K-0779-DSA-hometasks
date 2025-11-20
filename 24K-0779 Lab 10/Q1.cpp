#include <iostream>
using namespace std;

class minheap {
public:
    int heap[50];
    int size;

    minheap() {
        size = 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    void insert(int val) {
        heap[size] = val;
        int i = size;
        size++;

        while(i != 0 && heap[parent(i)] > heap[i]) {
            int t = heap[i];
            heap[i] = heap[parent(i)];
            heap[parent(i)] = t;
            i = parent(i);
        }
    }

    void display() {
        for(int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    minheap h;

    h.insert(1);
    h.insert(3);
    h.insert(5);
    h.insert(4);
    h.insert(2);

   
    h.display();

    h.insert(2);

    cout << "updated"<<endl;
    h.display();
}
