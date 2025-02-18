//Optimised Approach in terms of Time and Space Complexity

#include<iostream>
#include<vector>
using namespace std;


int recursiveBinarySearch(vector<int>&arr, int target)
{ 
    int start = 0, end = arr.size()-1;

    while(start <=  end)
    {
        int mid = start + (end-start)/2;

        if(target > arr[mid]) 
            start = mid+1; //right half
        else if(target < arr[mid]) 
            end = mid-1; //left half
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

    int result = recursiveBinarySearch(arr, target);
    if(result != -1) cout << "Target found at index " << result << endl;
    else cout << "Target not found!" << endl;
    
}
