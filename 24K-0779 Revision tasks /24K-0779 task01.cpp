// Shell Sort is more efficient than Insertion Sort because it starts with large gaps,
// allowing elements to move long distances quickly. This reduces the total number
// of comparisons and swaps needed. For small datasets like book IDs, Shell Sort's
// O(n log n) performance is better than Insertion Sort's O(n^2) worst case.
#include <iostream>
using namespace std;

void shellsort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
        cout << "Gap " << gap << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int books[] = {205, 102, 310, 450, 120, 90};
    int n = 6;
    
    cout << "Original: ";
    for (int i = 0; i < n; i++) cout << books[i] << " ";
    cout << endl;
    
    shellsort(books, n);
    
    cout << "Sorted: ";
    for (int i = 0; i < n; i++) cout << books[i] << " ";
    cout << endl;
    
    return 0;
}
