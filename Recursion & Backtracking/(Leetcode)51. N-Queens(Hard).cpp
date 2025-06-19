//problem: https://leetcode.com/problems/n-queens/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(vector<string> &board, int row, int col, int n)
{
    // Check the current row on the left side
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
            return false;
    }

    // Check the current column
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // If all checks pass, it's safe to place a queen
    return true;
}

// Recursive function to try placing queens row by row
void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans)
{
    // Base case: all queens are placed successfully
    if (row == n)
    {
        ans.push_back(board); // Save the current valid board configuration
        return;
    }

    // Try placing a queen in each column of the current row
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j, n))
        {
            board[row][j] = 'Q';        // Place queen
            nQueens(board, row + 1, n, ans); // Recurse to next row
            board[row][j] = '.';        // Backtrack (remove queen)
        }
    }
}

// Function to solve the N-Queens problem and return all valid board configurations
vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));  // Create an empty n x n board
    vector<vector<string>> ans;              // To store all valid solutions

    nQueens(board, 0, n, ans);               // Start solving from row 0
    return ans;
}

int main()
{
    int n;
    cin >> n;  // Input the value of N

    vector<vector<string>> ans = solveNQueens(n); // Get all solutions

    if (ans.empty()) {
        cout << "No solution exists for n = " << n << endl;
    } else {
        cout << "All Solutions:\n";
        for (auto &solution : ans)
        {
            for (auto &row : solution)
            {
                cout << row << endl;
            }
            cout << endl; // Separate each board solution
        }
    }

    return 0;
}
