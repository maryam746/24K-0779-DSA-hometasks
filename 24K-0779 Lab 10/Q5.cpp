#include <iostream>
using namespace std;

class maxheap {
public:
    int heap[50];
    int size;

    maxheap() {
        size = 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int val) {
        heap[size] = val;
        int i = size;
        size++;

        while(i != 0 && heap[parent(i)] < heap[i]) {
            int t = heap[i];
            heap[i] = heap[parent(i)];
            heap[parent(i)] = t;
            i = parent(i);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if(l < size && heap[l] > heap[largest]) largest = l;
        if(r < size && heap[r] > heap[largest]) largest = r;

        if(largest != i) {
            int t = heap[i];
            heap[i] = heap[largest];
            heap[largest] = t;
            heapify(largest);
        }
    }

    void remove_max() {
        if(size == 0) return;
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    maxheap h;

    h.insert(1500);
    h.insert(1200);
    h.insert(1800);
    h.insert(1600);

    
    h.display();

    h.insert(1700);
   
    h.display();

    h.remove_max();
    h.display();
}
