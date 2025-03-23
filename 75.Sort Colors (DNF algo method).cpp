#include <iostream>
#include <vector>
using namespace std;


void sortColors(vector<int>&nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1) mid++;
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int>arr(n);
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    sortColors(arr);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
