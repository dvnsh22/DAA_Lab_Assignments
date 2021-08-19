/*
Problem 1: Given an unsorted array of integers, design an algorithm and implement it using a program 
to sort an array of elements by dividing the array into two subarrays and combining these subarrays 
after sorting each of them. Your program should also find number of comparisons and inversions 
during sorting the array.
*/

#include <iostream>

using namespace std;

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

// Function to merge 2 arrays
void merge(int arr[], int low, int mid, int high, int &cmp, int &inv) {
    int size1 = mid - low + 1, size2 =  high - mid;
    int *subArr1 = new int[size1], *subArr2 = new int[size2];

    for (int i = 0; i < size1; ++i)
        subArr1[i] = arr[low + i];
    for (int j = 0; j < size2; ++j)
        subArr2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < size1 && j < size2) {
        ++cmp;
        if (subArr1[i] > subArr2[j]) {
            arr[k++] = subArr2[j++];
            inv += (mid - i - low + 1);
        }
        else
            arr[k++] = subArr1[i++];
    }

    while (i < size1)
        arr[k++] = subArr1[i++];
    
    while (j < size2)
        arr[k++] = subArr2[j++];
}

// Function to implement Merge Sort
void mergeSort(int arr[], int low, int high, int &cmp, int &inv) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, cmp, inv);
        mergeSort(arr, mid + 1, high, cmp, inv);
        merge(arr, low, mid, high, cmp, inv);
    }
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
        
        int cmp = 0, inv = 0;

        // Function call
        mergeSort(arr, 0, size - 1, cmp, inv);
        printArray(arr, size);
        cout << "Comparisons: " << cmp << endl;
        cout << "Inversions: " << inv << endl << endl;
    }
    return 0;
}