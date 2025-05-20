// Problem: https://leetcode.com/problems/3sum/description/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find all unique triplets in the array that sum to zero
vector<vector<int>> threeSum(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    // Step 1: Sort the array to enable two-pointer technique and easy duplicate removal
    sort(nums.begin(), nums.end());

    // Step 2: Iterate through the array and fix one number at a time
    for(int i = 0; i < n; i++)
    {
        // Skip duplicate elements to avoid duplicate triplets
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int j = i + 1;       // Start pointer
        int k = n - 1;       // End pointer

        // Step 3: Use two-pointer approach to find the other two numbers
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if(sum < 0) j++;           // If sum is too small, move left pointer to the right
            else if(sum > 0) k--;      // If sum is too large, move right pointer to the left
            else 
            {
                // Found a valid triplet
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                // Skip duplicates for nums[j]
                while(j < k && nums[j] == nums[j - 1]) j++;

                // Skip duplicates for nums[k]
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main ()
{
    int n;
    cout << "🔢 Enter the number of elements in the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "📥 Enter " << n << " integers:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> ans = threeSum(v);

    cout << "\n✅ Unique triplets that sum to zero:\n";
    for(auto triplet : ans)
    {
        for(int val : triplet) 
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
