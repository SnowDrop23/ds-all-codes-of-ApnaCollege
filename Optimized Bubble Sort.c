
#include<iostream>
using namespace std;


void printArray(int arr[], int n)
{
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
}
void bubbleSort(int arr[], int n)
{
	bool isSwap = false;
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
			isSwap = true;
		}
	}
	if(!isSwap) return;
	
}



int main()
{
	int n, value;
	cout << "Enter array size: ";
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	bubbleSort(arr, n);
	printArray(arr, n);

} 
