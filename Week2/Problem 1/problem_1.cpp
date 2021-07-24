/*
Problem 1: Given a sorted array of positive integers containing few duplicate elements, design an algorithm 
and implement it using a program to find whether the given key element is present in the array 
or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/

#include <iostream>

using namespace std;

// Function for binary search
int binarySearch(int arr[], int low, int high, int key, char l_or_f) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        bool found = false;

        if (arr[mid] == key) {
            found = true;
            if (l_or_f == 'F') {
                if ((mid == 0) || (mid == high && arr[mid - 1] != key) || (mid > 0 && mid < high && arr[mid - 1] != key)) 
                    return mid;

                high = mid - 1;
            }
            else {
                if ((mid == high) || (mid == 0 && arr[mid + 1] != key) || (mid > 0 && mid < high && arr[mid + 1] != key)) 
                    return mid;

                low = mid + 1;
            }
        }

        if (!found) {
            if (arr[mid] < key) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
    }

    return -1;
}

// Function to search the key and print no. of its copies
void searchKey(int arr[], int n, int key) {
    int first = binarySearch(arr, 0, n - 1, key, 'F');
    int last = binarySearch(arr, 0, n - 1, key, 'L');
    
    if (first == -1) {
        cout << "Key not present" << endl;
        return;
    }

    int copies = last - first + 1;
    cout << key << " - " << copies << endl;
    return;
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
        searchKey(arr, size, key);
    }
	return 0;
}