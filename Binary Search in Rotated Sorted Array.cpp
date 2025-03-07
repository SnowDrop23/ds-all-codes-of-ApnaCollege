/*
In rotated sorted array:
1) whether left half is sorted 2) else right half is sorted
after finding this, apply binary search in that sorted half

*/
#include <iostream>
#include <vector>
using namespace std;


int Search(vector<int>&nums, int target)
{
    int start = 0, end = nums.size()-1;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(nums[mid] == target) return mid;

        if(nums[start] <= nums[mid]) //left sorted
        {
            if(nums[start] <= target && target < nums[mid]) end = mid - 1;
            else start = mid + 1;
        }
        else //right half
        {
            if(nums[mid] < target && target <= nums[end]) start = mid + 1;
            else end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, target;
    cout << "Enter array size: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> target;
    cout << Search(arr, target) << endl;

    
    return 0;
}
