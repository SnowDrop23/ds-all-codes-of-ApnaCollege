//Question link: https://leetcode.com/problems/subsets/description/
#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all subsets of array 'a'
void get_all_subsets(vector<int> &a, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
    // Base case: all elements have been considered
    if(i == a.size())
    {
        allSubsets.push_back(ans);  // Store the current subset
        return;
    } 

    // ---------- INCLUDE STEP ----------
    // Include current element a[i] in the current subset
    ans.push_back(a[i]);

    // Recurse to the next index with a[i] included
    get_all_subsets(a, ans, i + 1, allSubsets);

    // ---------- BACKTRACK ----------
    // Remove the last added element (a[i]) to explore exclusion path
    ans.pop_back();

    // ---------- EXCLUDE STEP ----------
    // Recurse to the next index without including a[i]
    get_all_subsets(a, ans, i + 1, allSubsets);
}

// Wrapper function to initialize and return all subsets
vector<vector<int>> print_subsets(vector<int>& nums)
{
    vector<vector<int>> allSubsets;  // Stores all generated subsets
    vector<int> ans;                 // Stores the current subset during recursion

    // Start recursion from index 0
    get_all_subsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main()
{
    int n;
    cin >> n;  // Input the number of elements

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];  // Input array elements

    // Call function to get all subsets
    vector<vector<int>> subsets = print_subsets(v);

    // Print all subsets
    for(auto subset : subsets)
    {
        cout << "{";
        for(int x : subset)
            cout << x << " ";
        cout << "}" << endl;
    }

    return 0;
}
