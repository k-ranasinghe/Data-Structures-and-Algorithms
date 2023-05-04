#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    cout << "total elements in array: ";
    cin >> n;
    int arr[n];

    // Generate random array
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    selectionSort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    //cout << "Sorted array:\n";
    //for (int i = 0; i < n; i++) {
    //    cout << arr[i] << " ";
    //}
    cout << "\ntime taken: " << fixed << cpu_time_used   << " seconds" << endl;

    return 0;
}
