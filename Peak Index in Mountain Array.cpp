/* in any mountain array,
left half         < peak > right half
(increasing order)   .     (decreasing order)
 0, 3, 8,            9,     5, 2

|       *
|         
|  *         *
|*             *
------------------------ // Mountain array, so 0-th index and (n-1)-th index will never be the peak element.

Time complexity: O(log(n))
*/

#include <iostream>
#include <vector>
using namespace std;


int peakIndexInMountainArray(vector<int>&nums)
{
    int start = 1, end = nums.size()-2;

    while(start <= end)
    {
        int mid = start + (end-start)/2;

        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
        else if(nums[mid-1] < nums[mid]) //array is in increasing order, so peak will be in right half, apply binary search
            start = mid+1;
        else //array is in decreasing order, so peak will be in left side, apply binary search
            end = mid-1;
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
    
    cout << peakIndexInMountainArray(arr) << endl;

    
    return 0;
}

