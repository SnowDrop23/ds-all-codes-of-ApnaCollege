
#include<iostream>
using namespace std;


void printArray(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	    cout << arr[i] << " ";
	cout << endl;
}
void insertionSort(int arr[], int n)
{

	for(int i = 1; i < n; i++)
	{
		int curr = arr[i];
		int prev = i-1;

		while(prev >= 0 && arr[prev] > curr)
		{
			arr[prev+1] = arr[prev];
			prev--;
		}
		arr[prev+1] = curr;
	}
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	insertionSort(arr, n);
	printArray(arr, n);

}
