//Problem Statement: https://leetcode.com/problems/two-sum/description/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> m; // value -> index

    for(int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];
        int second = target - first;

        if(m.find(second) != m.end())
        {
            ans.push_back(m[second]);
            ans.push_back(i);

            
            break;
        }
        // Store the current number and its index
        m[first] = i;
    }
    return ans;
}

int main ()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> v(n);
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> ans = twoSum(v, target);
    if (!ans.empty())
    {
        for(int i : ans) cout << i << " ";
    }
    else
    {
        cout << "No valid pair found.\n";
    }
    
}
