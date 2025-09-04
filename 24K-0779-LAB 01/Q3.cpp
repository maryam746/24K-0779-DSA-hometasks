#include <iostream>
using namespace std;

class Exam
{
private:
    int *marks;

public:
    Exam(int m)
    {
        marks = new int(m);
    }
    void setMarks(int m)
    {
        *marks = m;
    }

    void display() const
    {
        cout << "Marks: " << *marks << endl;
    }

    ~Exam()
    {
        delete marks;
    }
};

int main()
{
    Exam e1(85);
    Exam e2 = e1;
    e1.display();
    e2.display();
    e2.setMarks(90);
    cout << "After modifying e2:" << endl;
    e1.display();
    e2.display();
}
