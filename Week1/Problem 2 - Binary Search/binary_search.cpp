/*
Problem 2: Given an already sorted array of positive integers, design an algorithm and implement it using a 
program to find whether given key element is present in the array or not. Also, find total number 
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).
*/

#include <iostream>

using namespace std;

// Function to implement Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, cmp = 0;
    bool found = false;

    while (low <= high) {
    	int mid = low + (high - low) / 2;

    	++cmp;
    	if (arr[mid] == key) {
    		found = true;
    		cout << "Present ";
    		break;
    	}

    	if (arr[mid] < key) 
    		low = mid + 1;
    	else 
    		high = mid - 1;
    }

    if (!found)
        cout << "Not Present ";

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
        int cmp = binarySearch(arr, size, key);
        cout << cmp << endl;
    }
    return 0;
}