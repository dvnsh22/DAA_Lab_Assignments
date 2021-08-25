/*
Problem 1: Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and 
implement it using a program to find which alphabet has maximum number of occurrences and print 
it. (Time Complexity = O(n)) (Hint: Use counting sort)
*/

#include <iostream>

using namespace std;

// Function to find alphabet with maximum frequency in array
void maxAlphabet(char arr[], int n) {
    int *count = new int[26]();

    for (int i = 0; i < n; ++i)
        ++count[arr[i] - 'a'];

    int max_idx = 0;
    for (int i = 1; i < 26; ++i) {
        if (count[i] > count[max_idx])
            max_idx = i;
    }

    if (count[max_idx] > 1)
        cout << char('a' + max_idx) << " - " << count[max_idx] << endl;
    else
        cout << "No duplicates present" << endl;
}

// Driver function
int main() {
    int t, size;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> size;
        char *arr = new char[size];

        for (int i = 0; i < size; ++i)
            cin >> arr[i];

        // Function call
        maxAlphabet(arr, size);
    }
    return 0;
}