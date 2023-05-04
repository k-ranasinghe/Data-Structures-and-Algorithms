#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped = true;
    int i, j;
    for (i = 0; i < n - 1 && swapped; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
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
        arr[i] = rand() % 9001 + 1000;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        //cout << arr[i] << " ";
    }
    cout << "\ntime taken: " << fixed << cpu_time_used << " seconds" << endl;

    return 0;
}
