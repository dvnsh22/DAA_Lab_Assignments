/*
Problem 3: Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array 
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2^k] and so on. 
Once the interval (arr[2^k] < key < arr[2^(k+1)] ) is found, perform a linear search operation from the index 2^k
to find the element key. Also, find total number of comparisons for each input case. 
(Complexity < O(n), where n is the number of elements need to be scanned for searching).
*/

#include <iostream>

using namespace std;

// Function to implement Jump Search
int jumpSearch(int arr[], int n, int key) {
    int cmp = 0;
    bool found = false, do_binary = false;

    int prev = 0, upper = n;
    for (int i = 0; i < upper; (i == 0 && !do_binary) ? i += 2 : (do_binary ? ++i : i *= 2)) {
        ++cmp;
        if (arr[i] == key) {
            found = true;
            break;
        }

        if (arr[i] > key) {
            do_binary = true;

            // Swapping values of 'i' and 'prev'
            prev += i;
            i = prev - i;
            prev -= i;

            upper = prev;
        }
        else
            prev = i;
    }

    if (!found) {
        for (int i = prev + 1; i < n; ++i) {
            ++cmp;
            if (arr[i] == key) {
                found = true;
                break;
            }
        }
    }
    
    if (found)
        cout << "Present ";
    else
        cout << "Not Present ";

    return cmp;
}

// Driver function
int main() {
    #ifndef ONLINE_JUDGE
    // For getting input from input.txt
    freopen("input.txt", "r", stdin);
    
    // For writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    int t, size, key;

    // t = No. of test cases
    cin >> t;

    while (t--) {
        cin >> size;

        int *arr = new int[size];
        for (int i = 0; i < size; ++i)
            cin >> arr[i];

        cin >> key;
        
        // Function call
        int cmp = jumpSearch(arr, size, key);
        cout << cmp << endl;
    }
    return 0;
}