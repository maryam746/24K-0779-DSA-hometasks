// Shell Sort shows intermediate steps with gap sequence: 3, 1
// It's more efficient than Bubble Sort (O(n log n) vs O(n^2)) making it faster for airport scale
// If luggage is nearly sorted, Shell Sort performs close to O(n) as fewer comparisons are needed
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
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }
}

int main() {
    int luggage[] = {32, 25, 40, 12, 18, 50, 28};
    int n = 7;
    
    cout << "Original luggage: ";
    for (int i = 0; i < n; i++) cout << luggage[i] << " ";
    cout << endl;
    
    shellsort(luggage, n);
    
    cout << "Sorted luggage: ";
    for (int i = 0; i < n; i++) cout << luggage[i] << " ";
    cout << endl;
    
    return 0;
}
