/*
Problem 3: Given an array of nonnegative integers, design an algorithm and a program to count the number 
of pairs of integers such that their difference is equal to a given key, K.
*/

#include <iostream>
#include <algorithm>

using namespace std;

// Function to count pairs such that |arr[i| - arr[j]| = K
int countPairs(int arr[], int size, int K) {
	sort(arr, arr + size);
	int pairs = 0;

	for (int i = 0; i < size - 1; ++i) {
		if (binary_search(arr + i + 1, arr + size, arr[i] + K))
			++pairs;
	}
	return pairs;
}

// Driver function
int main() {
	int t, size, K;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> size;
        int *arr = new int[size];

        for (int i = 0; i < size; ++i)
            cin >> arr[i];
        
        cin >> K;

        // Function call
        int pairs = countPairs(arr, size, K);
        cout << pairs << endl;
    }
	return 0;
}