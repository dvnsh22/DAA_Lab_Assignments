/*
Problem 1: Given an unsorted array of integers, design an algorithm and a program to sort the array using 
insertion sort. Your program should be able to find number of comparisons and shifts (shifts total 
number of times the array elements are shifted from their place) required for sorting the array.
*/

#include <iostream>

using namespace std;

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

// Function to implement Insertion Sort
void insertionSort(int arr[], int n) {
    int cmp = 0, shifts = 0;

    for (int i = 1; i < n; ++i) {
        int temp = arr[i];
        int j = i - 1;

        while (j > -1 && arr[j] > temp) {
            ++shifts;
            ++cmp;
            arr[j + 1] = arr[j];
            --j;
        }

        ++shifts;
        arr[j + 1] = temp;
    }

    printArray(arr, n);
    cout << "Comparisons: " << cmp << endl;
    cout << "Shifts: " << shifts << endl << endl;
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
        insertionSort(arr, size);
    }
    return 0;
}