#include <bits/stdc++.h>
using namespace std;

// Merge two sorted subarrays and count inversions
int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int inv_count = 0;

    // Compare and merge while counting inversions
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            inv_count += (mid - i + 1); // All remaining left elements are greater
        }
    }

    // Copy remaining elements from left and right subarrays
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for (int idx = 0; idx < temp.size(); idx++)
        arr[idx + st] = temp[idx];

    return inv_count;
}

// Recursive merge sort function with inversion counting
int merge_sort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        // Count inversions in left and right halves
        int left_inv_count = merge_sort(arr, st, mid);
        int right_inv_count = merge_sort(arr, mid + 1, end);

        // Count split inversions and merge
        int inv_count = merge(arr, st, mid, end);

        return left_inv_count + right_inv_count + inv_count;
    }
    return 0; // Base case: single element
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = merge_sort(a, 0, n - 1);

    cout << "Number of inversions: " << ans << endl;

    return 0;
}
