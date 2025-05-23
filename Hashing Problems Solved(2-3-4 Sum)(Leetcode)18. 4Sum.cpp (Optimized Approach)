//Question: https://leetcode.com/problems/4sum/description/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find all unique quadruplets that sum up to the given target
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;

    // Step 1: Sort the array to apply the two-pointer technique and skip duplicates easily
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++)
    {
        // Skip duplicate values for the first number
        if(i > 0 && nums[i] == nums[i-1]) continue;

        for(int j = i + 1; j < n;)
        {
            // Initialize two pointers
            int p = j + 1, q = n - 1;

            while(p < q)
            {
                // Use long long to avoid integer overflow
                long long sum = (long long)nums[i] + (long long)nums[j] +
                                (long long)nums[p] + (long long)nums[q];

                if(sum < target) p++;       // Need a larger sum
                else if(sum > target) q--;  // Need a smaller sum
                else
                {
                    // Found a valid quadruplet
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++; q--;

                    // Skip duplicates for the third number
                    while(p < q && nums[p] == nums[p - 1]) p++;
                }
            }

            // Move j to the next different value (skip duplicates for the second number)
            j++;
            while(j < n && nums[j] == nums[j - 1]) j++;
        }
    }
    return ans;
}

int main ()
{
    int n, target;

    // Prompt user for size of array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Prompt user for the target sum to find
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> v(n);
    cout << "Enter " << n << " integers:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // Call the function to get all quadruplets
    vector<vector<int>> ans = fourSum(v, target);

    // Output the result
    cout << "\nQuadruplets that sum up to " << target << ":\n";
    for(auto i : ans)
    {
        for(int val : i) cout << val << " ";
        cout << "\n";
    }

    return 0;
}
