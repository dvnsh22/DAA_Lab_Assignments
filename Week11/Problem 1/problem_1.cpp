/*
Problem 1: Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
           matrices together. To find the optimal solution, you need to find the order in which these
           matrices should be multiplied. 
*/

#include <iostream>
#include <vector>

using namespace std;

int calcMinOperations(vector<int> &arr, int n) {
    vector<vector<int>> dp(n, vector<int> (n));
 
    for (int i = 1; i < n; ++i)
        dp[i][i] = 0;
 
    for (int L = 2; L < n; ++L) {
        for (int i = 1; i < n - L + 1; ++i) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
 
    return dp[1][n - 1];
}

// Driver function
int main() {
    int t, n;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> arr(n + 1);
        int temp, k = 0;

        for (int i = 0; i <= n*2; ++i) {
          cin >> temp;
          if (i == 0 || i % 2 != 0)
            arr[k++] = temp;
        }

        // Function call
        cout << calcMinOperations(arr, n + 1) << endl;
    }
    return 0;
}