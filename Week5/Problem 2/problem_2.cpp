/*
Problem 2: Given an unsorted array of integers, design an algorithm and implement it using a program to 
find whether two elements exist such that their sum is equal to the given key element. (Time 
Complexity = O(n log n))
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Function to find elements such that arr[i] + arr[j] = key
void printElemsWithSum(int arr[], int n, int key) {
    sort(arr, arr + n);
    int l = 0, r = n - 1;
    bool found = false;

    while (l < r) {
        if (arr[l] + arr[r] == key) {
            cout << "(" << arr[l] << ", " << arr[r--] << ") ";
            found = true;
        }
        else if (arr[l] + arr[r] < key) ++l;
        else --r;
    }

    if (!found)
        cout << "No such pair exist";
    cout << endl;
}

// Driver function
int main() {
    int t, size, key;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> size;
        int *arr = new int[size];

        for (int i = 0; i < size; ++i)
            cin >> arr[i];

        cin >> key;
        
        // Function call
        printElemsWithSum(arr, size, key);
    }
    return 0;
}