//Problem link: https://leetcode.com/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
using namespace std;

int mostWater(vector<int> &arr)
{
    int most_water = 0, left_pointer = 0, right_pointer = arr.size()-1;
    while(left_pointer < right_pointer)
    {
        int width = right_pointer - left_pointer;
        int hight = min(arr[left_pointer], arr[right_pointer]);
        int ans = width * hight;
        most_water = max(ans, most_water);

        if(arr[left_pointer] < arr[right_pointer]) left_pointer++;
        else right_pointer--;
    }
    return most_water;
}
//Time Complexity: O(n) 

int main ()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << mostWater(arr);
}
