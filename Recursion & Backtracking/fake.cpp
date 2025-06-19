
int main()
{
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter the suduku board (use '.' empty cells): \n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    }

    solveSudoku(board);

    cout << "\nSolved Sudoku Board:\n";
    for (auto &row : board)
    {
        for (char cell : row)
            cout << cell << " ";
        cout << endl;
    }
}
