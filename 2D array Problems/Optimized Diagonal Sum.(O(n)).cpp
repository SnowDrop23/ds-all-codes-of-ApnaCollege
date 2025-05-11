#include <iostream>

#include <bits/stdc++.h>
using namespace std;

int diagonalSum(int arr[][100], int n)
{
    int sum = 0;
    //Primary Diagonal: j = i
    //Secondary Diagonal: j = n-i-1
    
    for(int i = 0; i < n; i++)
    {
        sum += arr[i][i];

        if(i != (n-i-1)) sum += arr[i][n-i-1];
        
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
