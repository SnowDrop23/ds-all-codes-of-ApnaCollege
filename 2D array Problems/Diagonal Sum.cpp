#include <iostream>

#include <bits/stdc++.h>
using namespace std;

int diagonalSum(int arr[][100], int n)
{
    int sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) sum += arr[i][j]; //Primary digonal
            else if(j == (n - i - 1)) sum += arr[i][j]; //Secondary diagonal
        }
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the size of matrix "; // For diagonal sum, row = column
    cin >> n;

    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    cout << diagonalSum(arr, n) << endl;
}
