/*
Problem 1: Given a list of activities with their starting time and finishing time. Your goal is to select
           maximum number of activities that can be performed by a single person such that selected
           activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
           activity is greater than or equal to the finishing time of the other activity. Assume that a person
           can only work on a single activity at a time.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void activitySelection(vector<int> &start, vector<int> &end, int n) {
    vector<pair<pair<int, int>, int>> activity(n);
    vector<int> ans;

    for (int i = 0; i < n; ++i)
        activity[i] = {{end[i], start[i]}, (i + 1)};

    sort(activity.begin(), activity.end());

    ans.push_back(activity[0].second);
    int e_time = activity[0].first.first;

    for (int i = 1; i < n; ++i) {
        if (activity[i].first.second >= e_time) {
            e_time = activity[i].first.first;
            ans.push_back(activity[i].second);
        }
    }

    int no_of_act = ans.size();
    cout << endl << "No. of non-conflicting activities: " << no_of_act;
    cout << endl << "List of selected activities: ";
    for (int i = 0; i < no_of_act; ++i) {
        cout << ans[i];
        if (i < no_of_act - 1)
            cout << ", ";
    }
}

// Driver function
int main() {
    int t, n;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> start(n), end(n);
        for (int i = 0; i < n; ++i)
            cin >> start[i];

        for (int i = 0; i < n; ++i)
            cin >> end[i];

        // Function call
        activitySelection(start, end, n);
    }
    return 0;
}