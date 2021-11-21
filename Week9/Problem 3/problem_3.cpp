/*
Problem 3: Given an array of elements. Assume arr[i] represents the size of file 'i'. Design an algorithm 
           and implement it using a program to merge all these files int o a single file with minimum computation.
           For given 2 files 'A' and 'B' with sizes 'm' and 'n', computation cost of merging them is O(m + n).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mergeFiles(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    int cost = (n > 1) ? 0 : arr[0];

    for (int i = 1; i < n; ++i) {
        arr[i] += arr[i - 1];
        cost += arr[i];
    }

    return cost;
}

// Driver function
int main() {
    int t, n;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
                cin >> arr[i];

        // Function call
        cout << mergeFiles(arr, n) << endl;
    }
    return 0;
}