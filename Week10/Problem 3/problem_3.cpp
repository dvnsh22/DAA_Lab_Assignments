/*
Problem 3: Given an unsorted array of elements, design an algorithm and implement it using a program to
           find whether majority element exists or not. Also find median of the array. A majority element is
           an element that appears more than n/2 times, where n is the size of array.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void findMajorityElem(vector<int> &arr, int n) {
    int freq = -1, elem;
    map<int, int> mp;

    for (int i = 0; i < n; ++i) {
        ++mp[arr[i]];

        if (freq < mp[arr[i]]) {
            freq = mp[arr[i]];
            elem = arr[i];
        }
    }

    if (freq > n/2) {
        cout << "Yes" <<endl;
        cout << elem;
    }
    else
        cout << "No";
    cout << endl;
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
        findMajorityElem(arr, n);
    }

    return 0;
}