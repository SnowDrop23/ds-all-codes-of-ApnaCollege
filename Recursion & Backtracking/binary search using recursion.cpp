#include <iostream>      // For input/output
#include <vector>        // For using vector container
#include <algorithm>     // For sort() function
using namespace std;

// Recursive Binary Search Function, helper function if the given function only pass two parameters but we need to pass two extra parameters for recursion
int binSearch(vector<int>& arr, int target, int start, int end)
{
    // Continue searching while the range is valid
    if(start <= end)
    {
        int mid = start + (end - start)/2;  // Calculate middle index safely

        if(arr[mid] == target){             // If middle element is the target
            return mid;
        } else if(arr[mid] < target) {      // If target is greater, search right half
            return binSearch(arr, target, mid+1, end);
        } else {                            // If target is smaller, search left half
            return binSearch(arr, target, start, mid-1);
        }
    }

    // Target not found
    return -1;
}

// Wrapper function for binary search
int search(vector<int>& nums, int target) {
    return binSearch(nums, target, 0, nums.size()-1); // Search the full array
}

// Recursive function to check if array is sorted in non-decreasing order
bool is_sorted(vector<int>& arr, int n)
{   
    if(n == 0 || n == 1) return true;  // Base case: empty or single-element array is sorted

    // Check if last two elements are in order, and rest of the array is also sorted
    return (arr[n-1] >= arr[n-2] && is_sorted(arr, n-1));
}

int main()
{
    int n, target;
    cin >> n;                  // Input size of array
    vector<int> arr(n);        // Declare vector of size n

    // Input array elements
    for(int i = 0; i < n; i++) cin >> arr[i];

    cin >> target;             // Input target to search

    // If array is not sorted, sort it
    if(!is_sorted(arr, arr.size())) 
        sort(arr.begin(), arr.end());

    // Perform binary search and output result
    cout << search(arr, target) << endl;

    return 0;
}
