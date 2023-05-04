#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Total elements in array: ";
    cin >> n;
    int arr[n];

    // Generate random array
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10001 + 10000;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken: " << fixed << setprecision(9) << cpu_time_used << " seconds" << endl;

    return 0;
}
