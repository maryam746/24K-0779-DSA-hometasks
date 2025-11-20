#include<iostream>
using namespace std;

class minheap{
    public:
    int heap[50];
    int size;
     
    minheap(){
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
        if(size ==50) return;

        heap[size] = val;
        int i = size;
        size++;
    
        while(i!=0 && heap[parent(i)]>heap[i]){
            swap(heap[i],heap[parent(i)]);
            i= parent(i);

        }
    }

    void removemin(){
        if(size == 0) return;

        heap[0] = heap[size-1];
        size--;

        heapify(0);
    }


    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if(l<size && heap[l]<heap[smallest]){
            smallest = l;
        }

        if(r<size && heap[r]<heap[smallest]){
            smallest = r;
        }

        if(smallest != i){
            swap(heap[i],heap[smallest]);
            heapify(smallest);
        }
    }
    void display(){
    for(int i=0;i<size;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
};


int main(){
    minheap h;

   h.insert(100);
    h.insert(50);
    h.insert(75);
    h.insert(60);

     h.display();

    h.insert(55);

    h.display();
    h.removemin();
    h.display();


}