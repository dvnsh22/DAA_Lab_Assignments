/*
Problem 2: Given an unsorted array of integers, design an algorithm and implement it using a program 
to sort an array of elements by partitioning the array into two subarrays based on a pivot element 
such that one of the subarray holds values smaller than the pivot element while another subarray holds 
values greater than the pivot element. Pivot element should be selected randomly from the array. 
Your program should alse find number of comparisons and swaps required for sorting the array.
*/

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// Function to swap 2 numbers
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

// Function to partition the array 
int partition(int arr[], int low, int high, int &cmp, int &swaps) {
    int pivot = arr[high], j = low - 1;

    for (int i = low; i < high; ++i) {
        ++cmp;
        if (arr[i] <= pivot) {
            swap(arr[++j], arr[i]);
            ++swaps;
        }
    }
    swap(arr[high], arr[j + 1]);
    ++swaps;

    return (j + 1);
}

// Function to randomly pick a pivot element
int choosePivot(int arr[], int low, int high, int &cmp, int &swaps) {
   srand(time(0));
   int p_index = low + rand() % (high - low);
   swap(arr[high], arr[p_index]);
   return partition(arr, low, high, cmp, swaps);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high, int &cmp, int &swaps) {
    if (low < high) {
        int p_index = choosePivot(arr, low, high, cmp, swaps);
        quickSort(arr, low, p_index - 1, cmp, swaps);
        quickSort(arr, p_index + 1, high, cmp, swaps);
    }
    return;
}

// Driver function
int main() {
    int t, size;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> size;
        int *arr = new int[size];

        for (int i = 0; i < size; ++i)
            cin >> arr[i];

        int cmp = 0, swaps = 0;
        
        // Function call
        quickSort(arr, 0, size - 1, cmp, swaps);
        printArray(arr, size);
        cout << "Comparisons: " << cmp << endl;
        cout << "Swaps: " << swaps << endl << endl;
    }
    return 0;
}