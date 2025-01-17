#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> &nums, int target)
{
    vector<int>ans;
    
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i+1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}


int main ()
{
    int n, target;
    cout << "Enter size of an array: ";
    cin >> n;
    cout << "Enter target value: ";
    cin >> target; 

    vector<int>nums(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    vector<int>ans = pairSum(nums, target);

    if(ans.empty()) cout << "No such pair exits." << endl;
    else cout << "(" <<ans[0] << ", " << ans[1] << ")" << endl;
    
    return 0;
    
}
