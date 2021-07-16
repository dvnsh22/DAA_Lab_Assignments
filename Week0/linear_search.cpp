/*
Question-1: Given an array of nonnegative integers, design a linear algorithm and
implement it using a program to find whether a given key element is present in the array or
not. Also, find the total number of comparisons for each input case. (Time Complexity =
O(n), where n is the size of input).
*/

#include <iostream>

using namespace std;

// Function to implement Linear Search
int linearSearch(int arr[], int n, int key) {
    int cmp = 0;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        ++cmp;
        if (arr[i] == key) {
            found = true;
            cout << endl << "Element found in array !";
            break;
        }   
    }

    if (!found)
        cout << endl << "Element NOT found in array !";

    return cmp;
}

// Driver function
int main() {
    #ifndef ONLINE_JUDGE
    // For getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // For writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
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
        int cmp = linearSearch(arr, size, key);
        cout << endl << "No. of comparisons: " << cmp << endl;
    }
    return 0;
}