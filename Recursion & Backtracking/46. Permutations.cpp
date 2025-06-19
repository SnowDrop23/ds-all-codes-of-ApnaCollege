//Problem: https://leetcode.com/problems/permutations/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to generate permutations
void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    // 🔚 Base case: If index reaches end of array, a full permutation is formed
    if(idx == nums.size())
    {
        ans.push_back({nums}); // Add the current permutation to the answer list
        return;
    }

    // 🔁 Try placing every possible element at current index
    for(int i = idx; i < nums.size(); i++)
    {
        // ✅ Choose: Swap current index with i to fix a number at position idx
        swap(nums[idx], nums[i]);

        // 🔽 Recurse: Fix the next index (idx + 1)
        getPerms(nums, idx+1, ans);

        // 🔁 Backtrack: Undo the swap to restore original state before next iteration
        swap(nums[idx], nums[i]);
    }
}

// Wrapper function to initialize answer list and call recursion
vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans; // To store all permutations
    getPerms(nums, 0, ans);  // Start generating from index 0

    return ans;
}

int main()
{
    int n;
    cin >> n; // Input number of elements

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i]; // Input the array elements

    vector<vector<int>> ans = permute(a); // Get all permutations

    cout << "All Permutations:\n";
    for(auto i : ans) // Print each permutation
    {
        for(int x : i) cout << x << " ";
        cout << endl;
    }
}
