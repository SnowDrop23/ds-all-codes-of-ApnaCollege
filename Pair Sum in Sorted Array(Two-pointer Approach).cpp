#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> &nums, int target)
{
    vector<int>ans;
    int i = 0, j = (nums.size()) - 1;

    while(i < j)
    {
        int pairSum = nums[i] + nums[j];
        if(pairSum > target) j--;
        else if(pairSum < target) i++;
        else
        {
            ans.push_back(i); // return index i
            ans.push_back(j); // return index j
            //ans.push_back(nums[i]); // return value of i-th index
            //ans.push_back(nums[j]); // return value of j-th index
            return ans;
        }
    }
    return ans;
}


int main ()
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter target value: ";
    cin >> target;
    vector<int>nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int>ans = pairSum(nums, target);

    if(ans.empty()) cout << "No such pair exits." << endl;
    else cout << "(" << ans[0] << ", " << ans[1] << ")" << endl;
    
    return 0;
    
}
