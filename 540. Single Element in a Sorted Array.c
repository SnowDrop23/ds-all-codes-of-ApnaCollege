
#include <iostream>
#include <vector>
using namespace std;


int singleNonDuplicate(vector<int>&nums)
{
    int n = nums.size();

    if(n == 1) return nums[0];

    int start = 0, end = n-1, mid;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        
        //edge cases, when a non-duplicate element whether in at very first index(1/0) or at last index(n-1)
        if(mid == 0 && nums[0] != nums[1]) return nums[mid];
        if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];

        if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
        if(mid % 2 == 0)
        {
            if(nums[mid-1] == nums[mid]) end = mid-1; //search on left half
            else start = mid+1; //search on right half
        }
        else
        {
            if(nums[mid-1] == nums[mid]) start = mid+1; //search on right half
            else end = mid-1; //search on left half
        }

    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int res = singleNonDuplicate(arr);
    if(res == -1) cout << "Non-duplicate element not found!" << endl;
    else cout << "Non duplicate element is: " << res << endl;

    
    return 0;
}
