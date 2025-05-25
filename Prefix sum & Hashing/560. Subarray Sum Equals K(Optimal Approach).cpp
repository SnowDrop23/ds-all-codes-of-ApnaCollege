//Question: https://leetcode.com/problems/subarray-sum-equals-k/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the count of subarrays whose sum equals k
int subArraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;

    // Create a prefix sum vector to store cumulative sums
    vector<int> prefixSum(n, 0);

    // Initialize the first prefix sum with the first element
    prefixSum[0] = nums[0];

    // Build the prefix sum array
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    // Map to store frequencies of prefix sums encountered
    unordered_map<int, int> m;

    for(int j = 0; j < n; j++)
    {
        // If prefixSum[j] itself equals k, increment count
        if(prefixSum[j] == k) 
            count++;

        // Calculate the required prefix sum to form a subarray sum = k
        int val = prefixSum[j] - k;

        // If such a prefix sum has appeared before, add its frequency to count
        if(m.find(val) != m.end())
        {
            count += m[val];
        }

        // Record the frequency of the current prefix sum
        if(m.find(prefixSum[j]) == m.end())
            m[prefixSum[j]] = 0;

        m[prefixSum[j]]++;
    }

    return count;
}

int main()
{
    int n, k;

    // Prompt for size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Prompt for target sum k
    cout << "Enter the target sum (k): ";
    cin >> k;

    vector<int> v(n);

    // Prompt for array elements
    cout << "Enter " << n << " elements (space separated):\n";
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    } 

    // Output the count of subarrays with sum = k
    cout << "Number of subarrays with sum " << k << " is: " << subArraySum(v, k) << endl;

    return 0;
}
