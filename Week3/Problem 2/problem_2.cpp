/*
Problem 2: Given an unsorted array of integers, design an algorithm and implement a program to sort this 
array using selection sort. Your program should also find number of comparisons and number of 
swaps required.
*/

#include <iostream>

using namespace std;

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

// Function to implement Selection Sort
void selectionSort(int arr[], int n) {
    int cmp = 0, swaps = 0;

    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            ++cmp;
            if (arr[j] < arr[min_index]) 
                min_index = j;
        }

        ++swaps;
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    printArray(arr, n);
    cout << "Comparisons: " << cmp << endl;
    cout << "Swaps: " << swaps << endl << endl;
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
        
        // Function call
        selectionSort(arr, size);
    }
    return 0;
}