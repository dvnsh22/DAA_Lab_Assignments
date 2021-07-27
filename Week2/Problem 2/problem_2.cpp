/*
Problem 2: Given a sorted array of positive integers, design an algorithm and implement it using a program 
to find three indices i, j, k such that arr[i] + arr[j] = arr[k]. 
*/

#include <iostream>

using namespace std;

// Function for binary search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
    	int mid = low + (high - low) / 2;

    	if (arr[mid] == key)
    		return mid;

    	if (arr[mid] < key) 
    		low = mid + 1;
    	else 
    		high = mid - 1;
    }

    return -1;
}

// Function to print sequence of elements such that arr[i] + arr[j] = arr[k]
void printSequence(int arr[], int size) {

	for (int i = 0; i < size - 2; ++i) {
		for (int j = i + 1; j < size - 1; ++j) {
			int index = binarySearch(arr, j + 1, size - 1, arr[i] + arr[j]);
			if (index != -1) {
				cout << (i + 1) << ", " << (j + 1) << ", " << (index + 1) << endl;
				return;
			}
		}
	}

	cout << "No sequence found" << endl;
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
        
        // Function call
        printSequence(arr, size);
    }
	return 0;
}