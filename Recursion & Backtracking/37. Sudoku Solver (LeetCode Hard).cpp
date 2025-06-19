//Problem link: https://leetcode.com/problems/sudoku-solver/description/
#include <bits/stdc++.h>
using namespace std;

// Function to check if placing 'dig' at board[row][col] is valid
bool isSafe(vector<vector<char>> &board, int row, int col, char dig)
{
    // Check the row for duplicate
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == dig)
            return false;
    }

    // Check the column for duplicate
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == dig)
            return false;
    }

    // Check the 3x3 subgrid for duplicate
    int srow = (row / 3) * 3;  // starting row of subgrid
    int scol = (col / 3) * 3;  // starting column of subgrid

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

// Recursive function to fill the board
bool helper(vector<vector<char>> &board, int row, int col)
{
    // If we've reached the end of the board, it's solved
    if (row == 9)
        return true;

    // Move to next cell
    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    // If current cell is already filled, go to the next one
    if (board[row][col] != '.')
    {
        return helper(board, nextRow, nextCol);
    }

    // Try placing digits '1' to '9' in the empty cell
    for (char dig = '1'; dig <= '9'; dig++)
    {
        if (isSafe(board, row, col, dig))
        {
            board[row][col] = dig;  // place digit

            // Recursively try to solve rest of the board
            if (helper(board, nextRow, nextCol))
                return true;
        }

        // If placing dig doesn't work, backtrack
        board[row][col] = '.';
    }

    // None of the digits worked — need to backtrack
    return false;
}

// Main solving function
void solveSudoku(vector<vector<char>> &board)
{
    helper(board, 0, 0);  // start solving from cell (0, 0)
}

int main()
{
    vector<vector<char>> board(9, vector<char>(9));

    // Input: Read the board from user
    cout << "Enter the Sudoku board (use '.' for empty cells): \n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    }

    // Solve the board
    solveSudoku(board);

    // Output: Print the solved board
    cout << "\nSolved Sudoku Board:\n";
    for (auto &row : board)
    {
        for (char cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}
