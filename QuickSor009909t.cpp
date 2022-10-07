#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    // swap arr[low] and arr[j]
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void Quicksort(int arr[], int low, int high)
{
    int partitionIndex; // index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);

        Quicksort(arr, low, partitionIndex - 1);  // sort left subarray
        Quicksort(arr, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{

    int n;
    cout << "Enter the no of array you want:- " ;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element of  array :- " ;
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "your array is :- " << arr[i] << endl; // printing the array before sorting
    }

    Quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << " you Quick sort array is :- " << arr[i] << endl; // printing the array before sorting
    }

    return 0;
}