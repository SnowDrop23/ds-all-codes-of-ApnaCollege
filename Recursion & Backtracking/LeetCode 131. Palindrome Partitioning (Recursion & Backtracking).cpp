#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s1)
{
    string s2 = s1;                      
    reverse(s2.begin(), s2.end());       
    return s1 == s2;                     
}

// Recursive function to generate all palindromic partitions
void get_all_parts(string s, vector<string> &partitions, vector<vector<string>> &ans)
{
    // Base Case: If the string is empty, current partition is complete
    if(s.size() == 0)
    {
        ans.push_back(partitions);       // Add current partition to result
        return;
    }

    // Try all prefixes of the current string
    for(int i = 0; i < s.size(); i++)
    {
        string part = s.substr(0, i+1);  // Extract prefix substring

        // If the prefix is a palindrome
        if(is_palindrome(part))
        {
            partitions.push_back(part);                          // Choose: Add to current partition
            get_all_parts(s.substr(i+1), partitions, ans);       // Explore: Recurse on the remaining string
            partitions.pop_back();                               // Backtrack: Remove last to try next option
        }
    }
}

// Wrapper function to initiate backtracking
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;          // Final result of all partitions
    vector<string> partitions;           // Current path of palindromic substrings
    get_all_parts(s, partitions, ans);   // Begin recursion
    return ans;
}

int main() {
    // Prompt user to enter input string
    cout << "Enter a string to find all palindromic partitions: ";
    string str;
    cin >> str;

    // Get all palindrome partitionings
    vector<vector<string>> r = partition(str);

    // Output all possible partitions
    cout << "\nAll palindromic partitions are:\n";
    for(auto i : r)
    {
        for(auto x : i) cout << x << " ";
        cout << endl;
    }

    return 0;
}
