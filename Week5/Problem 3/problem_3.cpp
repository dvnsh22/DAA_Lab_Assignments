/*
Problem 3: You have been given two sorted integer arrays of size m and n. Design an algorithm and 
implement it using a program to find list of elements which are common to both. (Time Complexity 
= O(m+n))
*/

#include <iostream>

using namespace std;

// Function to find common elements of 2 arrays
void findCommonElems(int arr1[], int size1, int arr2[], int size2) {
    int i = 0, j = 0;
    bool found = false;

    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            found = true;
            ++i;    ++j;
        }
        else if (arr1[i] > arr2[j]) ++j;
        else ++i;
    }

    if (!found)
        cout << "No common elements found";
    cout << endl;
}

// Driver function
int main() {
    int t, size1, size2;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> size1;
        int *arr1 = new int[size1];

        for (int i = 0; i < size1; ++i)
            cin >> arr1[i];
        
        cin >> size2;
        int *arr2 = new int[size2];

        for (int i = 0; i < size2; ++i)
            cin >> arr2[i];

        // Function call
        findCommonElems(arr1, size1, arr2, size2);
    }
    return 0;
}