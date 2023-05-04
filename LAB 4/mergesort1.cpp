#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;

void merge(int array[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne ; i++){
        leftArray[i] = array[left + i];
    }
    for (auto j = 0; j < subArrayTwo; j++){
        rightArray[j] = array[mid + 1 + j];
    }
    auto indexOfSubArrayOne = 0;
    auto indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int n) {
    int curr_size; 
    int left_start; 

    for (curr_size = 1; curr_size <= n-1; curr_size = 2*curr_size) {
        for (left_start = 0; left_start < n-1; left_start += 2*curr_size) {
            int mid = min(left_start + curr_size - 1, n-1);
            int right_end = min(left_start + 2*curr_size - 1, n-1);
            merge(arr, left_start, mid, right_end);
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

    double cpu_time_used;

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, n);
    auto end = chrono::high_resolution_clock::now();

    cpu_time_used = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Time taken: " << cpu_time_used << " nanoseconds" << endl;
    /*for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }*/
    return 0;
}
