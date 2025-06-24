#include <bits/stdc++.h>
using namespace std;

// Recursive helper function to explore all possible paths
void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans)
{
    int n = mat.size();

    // Check for out-of-bound, blocked, or already visited cells
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1)
        return;

    // Destination reached – store the current path
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // Mark current cell as visited by setting it to -1
    mat[r][c] = -1;

    // Explore all 4 directions: Down, Up, Left, Right
    helper(mat, r + 1, c, path + "D", ans); // Move Down
    helper(mat, r - 1, c, path + "U", ans); // Move Up
    helper(mat, r, c - 1, path + "L", ans); // Move Left
    helper(mat, r, c + 1, path + "R", ans); // Move Right

    // Backtrack: Unmark the cell by resetting it to 1
    mat[r][c] = 1;
}

// Main function to initiate path finding
vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<string> ans;
    string path = "";
    // Start the recursive backtracking from (0,0)
    helper(mat, 0, 0, path, ans);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of the maze (n x n): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze row by row (0 for blocked, 1 for open):" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> maze[i][j];
        }
    }

    // Call function to get all paths from (0,0) to (n-1,n-1)
    vector<string> paths = findPath(maze);

    // Print each valid path
    cout << "Possible paths from source to destination:" << endl;
    for (string &p : paths)
        cout << p << endl;

    return 0;
}
