//Problem link: https://leetcode.com/problems/sudoku-solver/description/
#include <bits/stdc++.h>
using namespace std;

// Check if placing 'dig' at board[row][col] is valid according to Sudoku rules
bool isSafe(vector<vector<char>> &board, int row, int col, char dig)
{
    // Check current row
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == dig)
            return false;
    }

    // Check current column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == dig)
            return false;
    }

    // Check 3x3 grid
    int srow = (row / 3) * 3;
    int scol = (col / 3) * 3;
    for (int i = srow; i <= srow + 2; i++)
    {
        for (int j = scol; j <= scol + 2; j++)
        {
            if (board[i][j] == dig)
                return false;
        }
    }

    // No conflict found, placement is safe
    return true;
}

// Recursive backtracking helper function to solve the Sudoku
bool helper(vector<vector<char>> &board, int row, int col)
{
    // Base case: If row is 9, the board is fully filled
    if (row == 9)
        return true;

    // Move to next cell
    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    // If current cell is already filled, move to the next
    if (board[row][col] != '.')
    {
        return helper(board, nextRow, nextCol);
    }

    // Try placing digits from '1' to '9' in the current empty cell
    for (char dig = '1'; dig <= '9'; dig++)
    {
        if (isSafe(board, row, col, dig))
        {
            board[row][col] = dig; // Place the digit

            // Recursively attempt to solve the rest
            if (helper(board, nextRow, nextCol))
                return true;

            // Backtrack if placement doesn't lead to solution
            board[row][col] = '.';
        }
    }

    // If no digit fits, return false (trigger backtracking)
    return false;
}

// Main solving function
void solveSudoku(vector<vector<char>> &board)
{
    helper(board, 0, 0);
}

int main()
{
    // Declare a 9x9 Sudoku board
    vector<vector<char>> board(9, vector<char>(9));

    // Prompt user for input
    cout << "Enter the Sudoku board (use '.' for empty cells):\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    }

    // Solve the puzzle
    solveSudoku(board);

    // Print the solved board
    cout << "\nSolved Sudoku Board:\n";
    for (auto &row : board)
    {
        for (char cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}
