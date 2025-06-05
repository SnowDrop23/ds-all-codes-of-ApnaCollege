#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &arr, int n)
{
    if(n == 0 || n == 1) return true; // if the array is empty or has one element, means it is already sorted

    return (arr[n-1] >= arr[n-2] && isSorted(arr, n-1));
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << isSorted(arr, arr.size()) << endl;
}
