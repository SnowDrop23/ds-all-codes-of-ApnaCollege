//Here is Question: https://leetcode.com/problems/majority-element/description/
#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>&nums)
{
    
    for(int i = 0; i < nums.size(); i++)
    {
        int count = 1;
        for(int j = i+1; j < nums.size(); j++)
        {
            if(nums[i] == nums[j]) count++;
        }
        if(count > (nums.size() / 2)) return nums[i];
        
    }
    return -1;
}


int main ()
{
    int n, count = 0;
    cout << "Enter array size: ":
    cin >> n;
    vector<int>nums(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    int result = majorityElement(nums);

    if(result != -1) cout << result << endl;
    else cout << "No majority element found!" << endl;
    
    return 0;
    
}
