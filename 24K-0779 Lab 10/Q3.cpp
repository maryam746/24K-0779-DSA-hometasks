#include<iostream>
using namespace std;

class maxheap{
    public:
    int heap[50];
    int size;

    maxheap(){
        size=0;
    }

    int parent(int i){
        return (i-1)/2;
    }

    int left (int i ){
        return 2*i+1;

    }

    int right(int i)
    {
        return 2*i+2;

    }


    void insert(int val){
        if(size =50) return;

        heap[size] = val;
        int i = size;
        size++;
    
        while(i!=0 && heap[parent(i)]<heap[i]){
            swap(heap[i],heap[parent(i)]);
            i= parent(i);

        }
    }

    void removemax(){

        if(size == 0) return;

        heap[0] = heap[size-1];
        size--;

        heapify(0);
    }


    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int largest = i;

        if(l<size && heap[l]>heap[largest]){
            largest = l;
        }
        if(r <size && heap[r]> heap[largest]){
            largest = r;
    }

    if(largest != i){
    
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

void display(){
    for(int i=0;i<size;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
};


int main() {
    maxheap h;

    h.insert(5);
    h.insert(3);
    h.insert(8);

    h.display();
    h.removemax();
    h.display();
}