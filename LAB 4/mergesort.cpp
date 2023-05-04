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

void mergeSort(int Array[], int const begin, int const end){
    if (begin >= end){
        return;
    }
    auto mid = begin + (end - begin) / 2;
    mergeSort(Array,begin,mid);
    mergeSort(Array, mid + 1, end);
    merge(Array,begin,mid,end);
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
    mergeSort(arr, 0, n);
    auto end = chrono::high_resolution_clock::now();

    cpu_time_used = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Time taken: " << cpu_time_used << " nanoseconds" << endl;

    return 0;
}
