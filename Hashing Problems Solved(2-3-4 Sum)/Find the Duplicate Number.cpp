// If the question is not asking "You must solve the problem without modifying the array nums and using only constant extra space." 
// then this is easier approach to solve
// Time Complexity: O(n)
// Space Complexity: O(n) 


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find any one duplicate in the array
int findDuplicate(vector<int>& nums)
{
    unordered_set<int> s; // Set to store seen elements

    for(int i : nums)
    {
        // If the current element is already in the set, it's a duplicate
        if(s.find(i) != s.end()) return i;

        // Otherwise, insert it into the set
        s.insert(i);
    }

    // If no duplicate is found, return -1
    return -1;
}

int main()
{
    int n;
    // Prompt user to enter the number of elements
    cout << "Enter the size: ";
    cin >> n;

    vector<int> v(n);
    // Prompt user to input the array elements
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    } 

    // Call the function and print the duplicate element (if found)
    cout << "Duplicate element: " << findDuplicate(v) << endl;
}
