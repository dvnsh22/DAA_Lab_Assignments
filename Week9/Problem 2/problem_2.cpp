/*
Problem 2: Given a knapsack of maximum capacity 'w'. 'N' items are provided, each having its own value and weight.
           You have to design an algorithm and implement it using a program to find the list of selected items, such
           that the final selected content has weight 'w' and the maximum value. You can take fractions of items, i.e.,
           the items can be broken into smaller pieces so that you have to carry only a fraction 'xi' of item 'i', where
           0 <= xi <= 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int id;
    float weight, value, vperw;
};

bool cmpVpw(Item i1, Item i2) {
    return (i1.vperw > i2.vperw);
}

void fractionalKnapsack(vector<Item> &items, int n, int cap) {
    vector<pair<int, int>> ans;
    float profit = 0.0;

    for (int i = 0; i < n; ++i)
        items[i].vperw = (items[i].value / items[i].weight);

    sort(items.begin(), items.end(), cmpVpw);

    for (int i = 0; i < n; ++i) {
        if (items[i].weight <= cap) {
            profit += items[i].value;
            cap -= items[i].weight;
            ans.push_back({items[i].id, items[i].weight});
        }
        else {
            profit += (cap * items[i].vperw);
            ans.push_back({items[i].id, cap});
            break;
        }
    }

    cout << "Maximum value: " << profit << endl;
    cout << "Item\tWeight" << endl;

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << "\t\t" << ans[i].second << endl;
}

// Driver function
int main() {
    int t, n, cap;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> n;
        vector<Item> items(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> items[i].weight;
            items[i].id = (i + 1);
        }

        for (int i = 0; i < n; ++i)
            cin >> items[i].value;

        cin >> cap;

        // Function call
        fractionalKnapsack(items, n, cap);
    }
    return 0;
}