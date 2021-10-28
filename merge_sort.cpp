#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

	int* leftArray = new int[subArrayOne];
	int* rightArray = new int[subArrayTwo];

	for(int i = 0; i < subArrayOne; i++)
		leftArray[i] = arr[left + i];
	for(int j = 0; j < subArrayTwo; j++)
		rightArray[j] = arr[mid + 1 + j];

	int indexOfSubArrayOne = 0,indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
    {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
        {
			arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else 
        {
			arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) 
    {
		arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	while (indexOfSubArrayTwo < subArrayTwo) 
    {
		arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void mergeSort(int arr[], int begin, int end)
{
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

void printArray(int a[], int size)
{
	for(int i = 0;i<size; i++)
		cout << a[i] << " ";
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elemments of array: ";
    for(int i=0;i<n;i++)
        cin >> arr[i];
	mergeSort(arr,0,n-1);
	cout << "Sorted array is: ";
	printArray(arr,n);
	return 0;
}
