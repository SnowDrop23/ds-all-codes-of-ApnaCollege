// If value found, return i,j in the form of a pair, else return i = -1, j = -1 as pair

#include <iostream>
#include <utility>

using namespace std;

pair<int, int> linearSearch(int mat[100][100], int rows, int cols, int key)
{
    pair<int, int>p;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(mat[i][j] == key)
            {
                p.first = i;
                p.second = j;

                return p;
            }
        }
    }
    p.first = -1;
    p.second = -1;
    return p;
}

int main()
{
    int rows, cols, key;
    cout << "Enter number of rows and columns of a matrix: ";
    cin >> rows >> cols;

    int mat[100][100];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Enter the value to search: ";
    cin >> key;

    
    cout << "(";
    cout << linearSearch(mat, rows, cols, key).first << "," << linearSearch(mat, rows, cols, key).second;
    cout << ")";
}
