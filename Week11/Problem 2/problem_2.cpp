/*
Problem 2: Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
           For a given value N, you have to design an algorithm and implement it using a program to find
           number of ways in which these coins can be added to make sum value equals to N.
*/

#include <iostream>
#include <vector>

using namespace std;

int findCoins(vector<int> &coins, int c, int N) {
    vector<vector<int>> dp(N + 1, vector<int> (c, 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < c; ++j) {
            int t1 = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;
            int t2 = (j >= 1) ? dp[i][j - 1] : 0;

            dp[i][j] = t1 + t2;
        }
    }

    return dp[N][c - 1];
}

// Driver function
int main() {
    int t, c, N;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> c;
        vector<int> coins(c);

        for (int i = 0; i < c; ++i)
            cin >> coins[i];
        
        cin >> N;

        // Function call
        cout << findCoins(coins, c, N) << endl;
    }
    return 0;
}