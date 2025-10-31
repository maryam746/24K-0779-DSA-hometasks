#include <iostream>
using namespace std;

int getmax(int a[], int n) {
 int m = a[0];
 for(int i = 1; i < n; i++)
  if(a[i] > m) m = a[i];
 return m;
}

void countsort(int a[], int n, int exp) {
 int out[n], cnt[10] = {0};

 for(int i = 0; i < n; i++)
  cnt[(a[i] / exp) % 10]++;

 for(int i = 1; i < 10; i++)
  cnt[i] += cnt[i - 1];

 for(int i = n - 1; i >= 0; i--) {
  int idx = (a[i] / exp) % 10;
  out[cnt[idx] - 1] = a[i];
  cnt[idx]--;
 }

 for(int i = 0; i < n; i++)
  a[i] = out[i];
}

void radixsort(int a[], int n) {
 int m = getmax(a, n);

 for(int exp = 1; m / exp > 0; exp *= 10) {
  cout << "sorting by digit " << exp << endl;
  countsort(a, n, exp);

  for(int i = 0; i < n; i++)
   cout << a[i] << " ";
  cout << endl;
 }
}

int main() {
 int a[20];

 cout << "enter 20 product ids:" << endl;
 for(int i = 0; i < 20; i++)
  cin >> a[i];

 cout << "before sorting:" << endl;
 for(int i = 0; i < 20; i++)
  cout << a[i] << " ";
 cout << endl;

 radixsort(a, 20);

 cout << "after sorting:" << endl;
 for(int i = 0; i < 20; i++)
  cout << a[i] << " ";
 cout << endl;
}
