#include <iostream>
#include <queue>
using namespace std;

class Order {
public:
    int num;
    string name;
    int qty;
};

class Restro {
    queue<Order> q;
    int count;
    int max;
    
public:
    Restro(int s = 100) {
        count = 1;
        max = s;
    }
    
    void add(string n, int q) {
        if(q.size() >= max) {
            cout << "full" << endl;
            return;
        }
        Order o;
        o.num = count++;
        o.name = n;
        o.qty = q;
        q.push(o);
        cout << "added " << o.num << " " << n << " " << q << endl;
    }
    
    void process() {
        if(q.empty()) {
            cout << "empty" << endl;
            return;
        }
        Order o = q.front();
        q.pop();
        cout << "processed " << o.num << " " << o.name << " " << o.qty << endl;
    }
    
    void next() {
        if(q.empty()) {
            cout << "empty" << endl;
            return;
        }
        Order o = q.front();
        cout << "next " << o.num << " " << o.name << " " << o.qty << endl;
    }
    
    void show() {
        if(q.empty()) {
            cout << "no orders" << endl;
            return;
        }
        queue<Order> t = q;
        while(!t.empty()) {
            Order o = t.front();
            cout << o.num << " " << o.name << " " << o.qty << endl;
            t.pop();
        }
    }
    
    bool empty() {
        return q.empty();
    }
    
    bool full() {
        return q.size() >= max;
    }
};

int main() {
    Restro r;
    
    r.add("pizza", 2);
    r.add("burger", 1);
    r.add("pasta", 3);
    
    r.show();
    
    r.process();
    r.process();
    
    r.show();
    
    return 0;
}
