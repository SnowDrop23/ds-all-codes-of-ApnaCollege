#include<iostream>
#include<vector>
using namespace std;


int recursiveBinarySearch(vector<int>&arr, int target, int start, int end)
{
    
    while(start <=  end)
    {
        int mid = start + (end-start)/2;

        if(target > arr[mid]) 
            return recursiveBinarySearch(arr, target, mid+1, end); //right half
        else if(target < arr[mid]) 
            return recursiveBinarySearch(arr, target, start, mid-1); //left half
        else return mid;
    }
    return -1;
}

int main ()
{
    int n, target;
    cin >> n >> target;

    vector<int>arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int result = recursiveBinarySearch(arr, target, 0, n-1);
    if(result != -1) cout << "Target found at index " << result << endl;
    else cout << "Target not found!" << endl;
    
}
