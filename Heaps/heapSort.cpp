// #include "bits/stdc++.h"
// using namespace std;

// void heapify(int a[], int n, int i)
// {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;
//     if (left < n && a[largest] < a[left])
//     {
//         largest = left;
//     }
//     if (right < n && a[largest] < a[right])
//     {
//         largest = right;
//     }
//     if (largest != i)
//     {
//         swap(a[largest], a[i]);
//         heapify(a, n, largest);
//     }
// }

// int main()
// {

//     int n;
//     cout << "ENTER THE SIZE OF THE ARRAY" << endl;
//     cin >> n;
//     int a[n];
//     cout << "ENTER " << n << " ELEMENTS: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout << "ARRAY BEFORE HEAP SORT: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }

//     //Building Max Heap from array
//     for (int i = n / 2 - 1; i >= 0; i--)
//     {
//         heapify(a, n, i);
//     }

//     //Now Delete first and storing it to last
//     int c = 1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         swap(a[0], a[i]);
//         heapify(a, n - c, 0);
//         c = c + 1;
//     }
//     cout << endl
//          << "ARRAY AFTER HEAP SORT: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << a[i] << " ";
//     }
// cout << endl
//      << "CODE IS DEVELOPED BY BADRI VISHAL SINGHAL 20U03001" << endl;
// }

#include <bits/stdc++.h>
using namespace std;

void buildMaxHeap(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // if child is bigger than parent
        if (arr[i] > arr[(i - 1) / 2])
        {
            int j = i;

            // swap child and parent until
            // parent is smaller
            while (arr[j] > arr[(j - 1) / 2])
            {
                swap(arr[j], arr[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        // maintaining heap property
        // after each swapping
        int j = 0, index;

        do
        {
            index = (2 * j + 1);

            // if left child is smaller than
            // right child point index variable
            // to right child
            if (arr[index] < arr[index + 1] &&
                index < (i - 1))
                index++;

            // if parent is smaller than child
            // then swapping parent with child
            // having higher value
            if (arr[j] < arr[index] && index < i)
                swap(arr[j], arr[index]);

            j = index;

        } while (index < i);
    }
}

int main()
{
    int n;
    cout << "ENTER THE SIZE OF THE ARRAY" << endl;
    cin >> n;
    int a[n];
    cout << "ENTER " << n << " ELEMENTS: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "ARRAY BEFORE HEAP SORT: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    heapSort(a, n);

    cout << endl
         << "ARRAY AFTER HEAP SORT: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl
         << "CODE IS DEVELOPED BY BADRI VISHAL SINGHAL 20U03001" << endl;
}
