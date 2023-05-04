#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int l = root;
    int left = 2*root + 1;      // left child
    int right = 2*root + 2;     // right child
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[l])
        l = left;
 
    // If right child is larger than l
    if (right < n && arr[right] > arr[l])
        l = right;
 
    // If l is not root
    if (l != root)
    {
        swap(arr[root], arr[l]);
        heapify(arr, n, l);
    }
}

  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    // extracting elements from heap one by one
    for (int j=n-1; j>=0; j--)
    {
        // Move current root to end
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
    }   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
