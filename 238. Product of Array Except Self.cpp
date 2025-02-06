//Problem Link: https://leetcode.com/problems/product-of-array-except-self/description/
#include <iostream>
#include <vector>
using namespace std;

vector<int>productExceptSelf(vector<int>&arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);

    //prefix
    for(int i = 1; i < n; i++) ans[i] = ans[i-1] * arr[i-1];

    int suffix = 1;
    //suffix
    for(int i = (n-2); i >= 0; i--)
    {
        suffix *= arr[i+1];
        ans[i] *= suffix;
    }
    return ans;
}
int main ()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res = productExceptSelf(arr);

    for(int i : res) cout << i << " ";

}
