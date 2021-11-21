/*
Problem 2: Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
           deadline associated with it. You have to design an algorithm and implement it using a program to
           find maximum number of tasks that can be completed without crossing their deadlines and also
           find list of selected tasks.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct task {
    int id, duration, deadline;
};

bool cmpDL(task t1, task t2) {
    return (t1.deadline < t2.deadline);
}

void maxTasks(vector<task> &T, int n) {
    int sum = 0;
    vector<int> ans;
    
    sort(T.begin(), T.end(), cmpDL);

    for (int i = 0; i < n; ++i) {
        if (T[i].deadline >= (sum + T[i].duration)) {
            ans.push_back(T[i].id);
            sum += T[i].duration;
        }
    }

    int no_of_tasks = ans.size();
    cout << endl << "Maximum no. of tasks: " << no_of_tasks;
    cout << endl << "List of selected tasks: ";
    for (int i = 0; i < no_of_tasks; ++i) {
        cout << ans[i];
        if (i < no_of_tasks - 1)
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
        vector<task> T(n);
        for (int i = 0; i < n; ++i) {
            T[i].id = i + 1;
            cin >> T[i].duration;
        }

        for (int i = 0; i < n; ++i)
            cin >> T[i].deadline;

        // Function call
        maxTasks(T, n);
    }
    return 0;
}