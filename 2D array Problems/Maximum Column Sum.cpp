#include <iostream>

#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[][100], int rows, int cols)
{
    int maxColSum = INT_MIN;
    int a = 0, colSumJ = 0;

    for (int j = 0; j < cols; j++)
    {
        int colSumJ = 0;
        for (int i = 0; i < rows; i++)
            colSumJ += arr[i][j];
        maxColSum = max(maxColSum, colSumJ);
    }

    return maxColSum;
}

int main()
{
    int row, cols;
    cout << "Enter the value of rows and cols: ";
    cin >> row >> cols;

    int arr[100][100];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }

    cout << maxSum(arr, row, cols) << endl;
}
