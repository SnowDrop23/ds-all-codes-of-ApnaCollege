#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all subsets
void print_subsets(vector<int> &a, vector<int> &ans, int i)
{
    // Base case: if we have considered all elements
    if(i == a.size())
    {
        cout << "{";
        // Print the current subset
        for(int i : ans) cout << i << " ";
        cout << "}";
        cout << endl;
        return;
    } 

    // Include a[i] in the current subset
    ans.push_back(a[i]);

    // Move to the next index with a[i] included
    print_subsets(a, ans, i+1);

    // Backtrack: remove a[i] to try the path without it
    ans.pop_back();

    // Exclude a[i] from the current subset and move to the next
    print_subsets(a, ans, i+1);
}

int main()
{
    int n;
    cin >> n; // Take input for size of array

    vector<int> v(n);      // Input array
    vector<int> ans;       // To store current subset

    // Read elements of the array
    for(int i = 0; i < n; i++) cin >> v[i];

    // Call the recursive function to generate subsets
    print_subsets(v, ans, 0);
}
