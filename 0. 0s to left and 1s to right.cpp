// nums = [1,0,1,0,1]
//       to
// nums = [0,0,1,1,1]

#include <iostream>
#include <vector>
using namespace std;


void sortColors(vector<int>&nums)
{
    int n = nums.size();
    int low = 0, high = n-1;

    while(low < high)
    {
        if(nums[low] == 1)
        {
            swap(nums[low], nums[high]);
            high--;
        }
        else low++;
        
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
