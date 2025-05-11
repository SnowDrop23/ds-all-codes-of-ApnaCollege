#include <iostream>

#include <bits/stdc++.h>
using namespace std;


int maxSum(int arr[][100], int rows, int cols)
{
    int maxRowSum = INT_MIN;

    for(int i = 0; i < rows; i++)
    {
        int rowSumI = 0;
        for(int j = 0; j < cols; j++)
        {
            rowSumI += arr[i][j];
        }

        maxRowSum = max(maxRowSum, rowSumI);
    }

    return maxRowSum;
}

int main()
{
    int row, cols;
    cout << "Enter the value of rows and cols: ";
    cin >> row >> cols;

    int arr[100][100];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < cols; j++) cin >> arr[i][j];
    }

    cout << maxSum(arr, row, cols) << endl;
}
