#include <iostream>
using namespace std;

class Box {
private:
    int* vol;

public:
    Box() {
        vol = new int(0);
    }

    Box(int v) {
        vol = new int(v);
    }

    Box(const Box& b) {
        vol = new int(*(b.vol));
    }

    void setVolume(int v) {
        *vol = v;
    }

    void display() const {
        cout << "Volume: " << *vol << endl;
    }

    ~Box() {
        delete vol;
    }
};

int main() {
    Box b1(50);         
    cout << "b1 "; 
    b1.display();

    Box b2 = b1;        
    cout << "b2 (copied from b1) "; 
    b2.display();

    b2.setVolume(100);  

    cout << "\nAfter modifying b2:" << endl;
    cout << "b1 "; b1.display();   
    cout << "b2 "; b2.display();  

    return 0;
}
