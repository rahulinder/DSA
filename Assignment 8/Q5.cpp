#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HeapSort {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Max-heap property
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Heap Sort function
    void sort(vector<int>& arr, bool increasing = true) {
        int n = arr.size();

        // Build max-heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Extract elements
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }

        // For decreasing order, just reverse the array
        if (!increasing)
            reverse(arr.begin(), arr.end());
    }
};

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    HeapSort hs;

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    hs.sort(arr, true);
    cout << "Sorted (increasing): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    hs.sort(arr, false);
    cout << "Sorted (decreasing): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}


