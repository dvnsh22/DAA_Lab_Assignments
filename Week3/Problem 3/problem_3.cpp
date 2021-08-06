/*
Problem 3: Given an unsorted array of positive integers, design an algorithm and implement it using a 
program to find whether there are any duplicate elements in the array or not. (Use sorting) (Time 
Complexity = O(n log n))
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

// Function to partition the array 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to randomly pick a pivot element
int choosePivot(int arr[], int low, int high) {
    srand(time(0));
    int p_index = low + rand() % (high - low);
    swap(arr[high], arr[p_index]);
    return partition(arr, low, high);
}

// Function for Quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p_index = choosePivot(arr, low, high);
        quickSort(arr, low, p_index - 1);
        quickSort(arr, p_index + 1, high);
    }
    return;
}

// Function to check if the array contains duplicates or not
bool hasDuplicates(int arr[], int n) {
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i + 1] == arr[i])
            return true;
    }
    return false;
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
        if (hasDuplicates(arr, size))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
        
    }
    return 0;
}