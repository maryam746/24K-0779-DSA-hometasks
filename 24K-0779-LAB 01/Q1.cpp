#include <iostream>
using namespace std;

class Researchpaper {
private:
    string* author;
    int n;

public:
    Researchpaper() {
        cout << "Enter the number of authors: ";
        cin >> n;
        author = new string[n];
        cout << "Enter the names of authors: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> author[i];
        }
    }

    
    Researchpaper(const Researchpaper& rp) {
        n = rp.n;
        author = new string[n];
        for (int i = 0; i < n; i++) {
            author[i] = rp.author[i];
        }
    }

   
    Researchpaper& operator=(const Researchpaper& rp) {
        if (this != &rp) {
            delete[] author; 
            n = rp.n;
            author = new string[n];
            for (int i = 0; i < n; i++) {
                author[i] = rp.author[i];
            }
        }
        return *this;
    }

    void display() {
        cout << "Authors: ";
        for (int i = 0; i < n; i++) {
            cout << author[i] << " ";
        }
        cout << endl;
    }

    void setAuthor(int index, string name) {
        if (index >= 0 && index < n) {
            author[index] = name;
        }
    }

    ~Researchpaper() {
        delete[] author;
    }
};

int main() {
    Researchpaper r1;
    cout << "r1 "; 
    r1.display();

    Researchpaper r2 = r1;   
    cout << "r2 "; 
    r2.display();

    Researchpaper r3;
    cout << "r3 before assignment "; 
    r3.display();

    r3 = r1;  
    cout << "r3 after assignment ";
     r3.display();

    cout << "\n--- Demonstrating Deep Copy ---" << endl;
    r2.setAuthor(0, "Khaled_Hosseini");
    r3.setAuthor(1, "Paulo_Coelho");

    cout << "After modifying r2 and r3:" << endl;
    cout << "r1 "; r1.display();
    cout << "r2 "; r2.display();
    cout << "r3 "; r3.display();
}
