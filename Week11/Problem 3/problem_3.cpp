/*
Problem 3: Given a set of elements, you have to partition the set into two subsets such that the sum of
           elements in both subsets is same. Design an algorithm and implement it using a program to solve
           this problem.
*/

#include <iostream>
#include <vector>

using namespace std;
 
bool hasSubsetSumEqual(vector<int> &arr, int n, int sum) {
    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    if (arr[n - 1] > sum)
        return hasSubsetSumEqual(arr, n - 1, sum); 

    return hasSubsetSumEqual(arr, n - 1, sum) || 
           hasSubsetSumEqual(arr, n - 1, sum - arr[n - 1]);
}

// Driver function
int main() {
    int t, n, sum = 0;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
            cin >> arr[i], sum += arr[i];

        if (sum % 2 != 0)
            cout << "No";
        else {
            // Function call
            if (hasSubsetSumEqual(arr, n, sum / 2))
                cout << "Yes";
            else
                cout << "No";
        }
        cout << endl;
    }
    return 0;
}