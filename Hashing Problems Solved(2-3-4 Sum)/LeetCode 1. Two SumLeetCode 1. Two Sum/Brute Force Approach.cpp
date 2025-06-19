#include <iostream>
#include <vector>
using namespace std;

// Function to find indices of the two numbers such that they add up to the target
vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ans;
    int sum = 0;

    // Brute force approach: check all pairs
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            sum = nums[i] + nums[j];
            if(sum == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans; // Return immediately after finding one valid pair
            }
        }
    }
    return ans; // Returns empty vector if no pair is found
}

int main ()
{
    int n, target;

    // Prompt user for number of elements and target sum
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> v(n);

    // Prompt user to input the array elements
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> v[i];

    // Call twoSum and store result
    vector<int> ans = twoSum(v, target);

    // Output the result
    if (!ans.empty()) {
        cout << "Indices of elements that sum to target: ";
        for(int i : ans) cout << i << " ";
    } else {
        cout << "No two elements found that sum to the target.";
    }
    cout << endl;
}
