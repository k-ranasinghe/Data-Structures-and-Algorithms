#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    // Generate random array
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 900001 + 100000;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    insertionSort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        //cout << arr[i] << " ";
    }
    cout << "\nTime taken for sorting: " << fixed << cpu_time_used << " seconds" << endl;

    return 0;
}
