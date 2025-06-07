//Problem Link: https://leetcode.com/problems/subsets-ii/description/
#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all unique subsets
void get_all_subsets(vector<int> &a, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
    // Base case: all elements considered
    if(i == a.size())
    {
        allSubsets.push_back(ans); // store current subset
        return;
    } 

    // ---------- INCLUDE STEP ----------
    ans.push_back(a[i]);
    get_all_subsets(a, ans, i + 1, allSubsets);

    // ---------- BACKTRACK ----------
    ans.pop_back();

    // ---------- SKIP DUPLICATES in EXCLUDE STEP ----------
    int idx = i + 1;
    while(idx < a.size() && a[idx] == a[idx - 1]) idx++;

    // ---------- EXCLUDE STEP ----------
    get_all_subsets(a, ans, idx, allSubsets);
}

// Wrapper function to sort input and start recursion
vector<vector<int>> print_subsets(vector<int>& nums)
{
    sort(nums.begin(), nums.end());  // Sort to group duplicates
    vector<vector<int>> allSubsets;
    vector<int> ans;

    get_all_subsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];  // Input array

    vector<vector<int>> subsets = print_subsets(v);

    // Print all unique subsets
    for(auto subset : subsets)
    {
        cout << "{";
        for(int x : subset)
            cout << x << " ";
        cout << "}" << endl;
    }
}
