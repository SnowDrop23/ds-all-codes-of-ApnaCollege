
// Problem statement: https://leetcode.com/problems/search-a-2d-matrix-ii/description/
#include <iostream>
#include <vector>
using namespace std;



bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size(), n = mat[0].size();

    int r = 0, c = n-1;
    while(r < m && c >= 0)
    {

        if(target == mat[r][c])
        {
            return true;;
        }
        else if(target < mat[r][c]) c--;
        else r++;
    }
    return false;
}

int main()
{
    int m, n, target;
    cout << "Enter the number of rows and coloums: ";
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    
    cout << "Enter elements: \n";
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
