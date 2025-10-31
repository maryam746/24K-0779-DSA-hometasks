#include <iostream>
#include <string>
using namespace std;

class Emp {
public:
    string n;
    int id, s;
};

void merge(Emp a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Emp L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].s >= R[j].s) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void msort(Emp a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    Emp e[12];
    for (int i = 0; i < 12; i++) {
        cout << "Enter name, id, and salary: ";
        cin >> e[i].n >> e[i].id >> e[i].s;
    }

    msort(e, 0, 11);

    cout << "\nTop 3 highest paid employees:\n";
    for (int i = 0; i < 3; i++)
        cout << e[i].n << " " << e[i].id << " " << e[i].s << endl;

    return 0;
}
