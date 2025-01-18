//Question link: https://leetcode.com/problems/majority-element/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majorityElement(vector<int>&nums)
{
	int n = nums.size(), count = 1, ans = 0;
	for(int i = 1; i < n; i++)
	{
		if(nums[i] == nums[i-1]) count++;
		else 
		{
			count = 1;
			ans = nums[i];
		}
		if(count > n/2) return ans;
		
	}
	return -1; 
	
	
}
int main ()
{
   	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());
	int ans = majorityElement(nums);
	
	if(ans != -1) cout << ans << endl;
	else cout << "Majority element not found!";
	

}

