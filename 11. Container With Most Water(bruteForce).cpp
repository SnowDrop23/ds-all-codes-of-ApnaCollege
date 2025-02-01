//Problem Link: https://leetcode.com/problems/container-with-most-water/description/
// We will get TLE if I submit it!!!!!!!!!

#include <iostream>
#include <vector>
using namespace std;

int mostWater(vector<int> &arr)
{
    int most_water = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = i + 1; j < arr.size(); j++)
        {
            int width = j - i;
            int hight = min(arr[i], arr[j]);
            int area = width * hight;
            most_water = max(most_water, area);
        }
    }
    return most_water;
}
int main ()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << mostWater(arr);
}
