#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root)
{
    int l = root;
    int left = 2*root + 1;
    int right = 2*root + 2;

    if (left < n && arr[left] > arr[l])
        l = left;

    if (right < n && arr[right] > arr[l])
        l = right;

    if (l != root)
    {
        swap(arr[root], arr[l]);
        heapify(arr, n, l);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int j=n-1; j>=0; j--)
    {
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }   
}

void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

int main()
{
   int n;
   cout << "Enter the size of the array: ";
   cin >> n;
   int heap_arr[n];

   cout << "Enter the elements of the array:";
   for (int i = 0; i < n; i++) {
       cin >> heap_arr[i];
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr, n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
