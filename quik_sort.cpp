#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{

    int a = arr[s];
    int count = 0;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] < a)
        {
            count++;
        }
    }

    swap(arr[s], arr[s + count]);

    int i = s;
    int j = e;

    while (i < s + count && j > s + count)
    {

        while (arr[i] < a && i < s + count)
        {
            i++;
        }

        while (arr[j] >= a && j > s + count)
        {
            j--;
        }

        swap(arr[i], arr[j]);
    }

    return s + count;
}

void quikSort(int arr[], int s, int e)
{

    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    quikSort(arr, s, p - 1);   //left

    quikSort(arr, p + 1, e);   //rigth
}

int main()
{

    int arr[5] = {3, 1, 5, 2, 4};
    int n = 5;
    int s = 0;
    int e = n - 1;

    quikSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
