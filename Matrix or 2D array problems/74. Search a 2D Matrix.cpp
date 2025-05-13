// Problem statement: https://leetcode.com/problems/search-a-2d-matrix/description/
#include <iostream>
#include <vector>
using namespace std;

bool searchInRow(vector<vector<int>> &mat, int target, int row)
{
    int n = mat[0].size();
    int start = 0, end = n-1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(target == mat[row][mid]) return true;
        else if(target > mat[row][mid]) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();

    int startRow = 0, endRow = m-1;
    while(startRow <= endRow)
    {
        int midRow = startRow + (endRow - startRow)/2;

        if(target >= mat[midRow][0] && target <= mat[midRow][n-1])
        {
            return searchInRow(mat, target, midRow);
        }
        else if(target >= mat[midRow][n-1]) startRow = midRow + 1;
        else endRow = midRow - 1;
    }
    return false;
}

int main()
{
    int m, n, target;
    cout << "Enter the number of rows and coloums: ";
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    
    cout << "Enter elements: ";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << "Enter target: ";
    cin >> target;
     
    
    if(searchMatrix(v, target)) cout << "Found\n";
    else cout << "Not found.\n";
	
}
