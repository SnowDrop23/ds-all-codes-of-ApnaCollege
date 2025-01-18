//Question link: https://leetcode.com/problems/majority-element/description/
//Moore's Voting Algorithm Approach
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>&nums)
{
	int n = nums.size(), candidate = 0, count = 0;
	for(int i = 0; i < n; i++)
	{
		if(count == 0) candidate = nums[i];
		if(candidate == nums[i]) count++;
		else count--;
		
	}
	count = 0;
	for(int i = 0; i < n; i++) 
	{
		if(nums[i] == candidate) count++;
	}
	if(count > n/2) return candidate;
	else return -1;
	
}
int main ()
{
   int n;
  cout << "Enter size: ";
	cin >> n;
	vector<int> nums(n);
  cout << "Enter elements: ";
	for(int i = 0; i < n; i++) cin >> nums[i];
	

	int ans = majorityElement(nums);
	
	if(ans != -1) cout << ans << endl;
	else cout << "Majority element not found!";
	

}
