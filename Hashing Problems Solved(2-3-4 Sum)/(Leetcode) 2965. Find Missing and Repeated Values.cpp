#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
{
    vector<int> ans;
    unordered_set<int> s; // to track seen numbers
    int n = grid.size();
    int a, b; // a = repeated number, b = missing number

    int expSum = 0, actualSum = 0;

    // Calculate actual sum and find the repeated number
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end()) 
            {
                a = grid[i][j]; // repeated number found
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }

    // Calculate expected sum of numbers from 1 to n*n
    expSum = (n*n) * ((n*n) + 1) / 2;

    // Calculate missing number using formula
    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int main ()
{
    int n;
    cout << "Enter the size of the grid (n): ";
    cin >> n;

    vector<vector<int>> v (n, vector<int>(n));
    cout << "Enter " << n*n << " elements (numbers from 1 to " << n*n << "):\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) 
            cin >> v[i][j];
    } 

    vector<int> ans = findMissingAndRepeatedValues(v);

    cout << "Repeated number and missing number are: ";
    for(int i : ans) cout << i << " ";
}
