#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of subarrays whose sum equals k
int subArraySum(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;

    // Loop through all subarrays using two pointers
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];  // Corrected: Add the current element arr[j]
            if(sum == k) count++;  // If sum matches k, increase the count
        }
    }
    return count;
}

int main()
{
    int n, k;

    // Taking size of array as input
    cout << "Enter the size of the array: ";
    cin >> n;

    // Taking target sum as input
    cout << "Enter the target sum (k): ";
    cin >> k;

    vector<int> v(n);

    // Taking array elements as input
    cout << "Enter " << n << " integers separated by space:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    } 

    // Output the result
    cout << "Number of subarrays with sum equal to " << k << " is: ";
    cout << subArraySum(v, k) << endl;

    return 0;
}
