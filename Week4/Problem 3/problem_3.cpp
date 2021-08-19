/*
Problem 3: Given an unsorted array of integers, design an algorithm and implement it using a program 
to find Kth smallest or largest element in the array. (Worst case time complexity: O(n))
*/

#include <iostream>

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

// Function to find Kth smallest element in array
int KthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int part = partition(arr, low, high);
        if (part - low == k - 1)
            return arr[part];
        if (part - low > k - 1)
            return KthSmallest(arr, low, part - 1, k);
        return KthSmallest(arr, part + 1, high, k - part + low - 1);
    }
    return INT_MAX;
}

// Driver function
int main() {
    int t, size, k;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> size;
        int *arr = new int[size];

        for (int i = 0; i < size; ++i)
            cin >> arr[i];
        
        cin >> k;

        // Function call
        int ans = KthSmallest(arr, 0, size - 1, k);
        if (ans == INT_MAX)
            cout << "Not Present" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}