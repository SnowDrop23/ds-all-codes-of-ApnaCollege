//Problem Statement: https://leetcode.com/problems/spiral-matrix/description/
#include <iostream>
#include <vector>
using namespace std;

// Function to return the elements of the matrix in spiral order
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int m = matrix.size();           // Number of rows
    int n = matrix[0].size();        // Number of columns

    int srow = 0, scol = 0;          // Starting row and column
    int erow = m - 1, ecol = n - 1;  // Ending row and column

    vector<int> ans;

    while (srow <= erow && scol <= ecol)
    {
        // Traverse the top row from left to right
        for (int j = scol; j <= ecol; j++)
        {
            ans.push_back(matrix[srow][j]);
        }

        // Traverse the right column from top to bottom
        for (int i = srow + 1; i <= erow; i++)
        {
            ans.push_back(matrix[i][ecol]);
        }

        // Traverse the bottom row from right to left
        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow) break; // Avoid double-counting the same row
            ans.push_back(matrix[erow][j]);
        }

        // Traverse the left column from bottom to top
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if (scol == ecol) break; // Avoid double-counting the same column
            ans.push_back(matrix[i][scol]);
        }

        // Move towards the inner layer
        srow++;
        erow--;
        scol++;
        ecol--;
    }

    return ans;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;

    cout << "Enter the number of columns (m): ";
    cin >> m;

    vector<vector<int>> v(n, vector<int>(m));
    cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<int> res = spiralOrder(v);

    cout << "Spiral Order Traversal: ";
    for (int &i : res)
        cout << i << " ";

    cout << endl;
    return 0;
}
