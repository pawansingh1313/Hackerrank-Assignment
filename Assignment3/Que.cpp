// 1- count sort

#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}
void sort(vector<int> &A)
{
    int k = 0;
    for (int i = 0; i < A.size(); i++)
    {
        k = max(k, A[i]);
    }
    int count[10] = {0};
    for (int i = 0; i < A.size(); i++)
    {
        count[A[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }
    int output[A.size()];
    for (int i = A.size() - 1; i >= 0; i--)
    {
        output[--count[A[i]]] = A[i];
    }
    for (int i = 0; i < A.size(); i++)
    {
        A[i] = output[i];
    }
}

int main()
{
    vector<int> A = {6, 1, 2, 3, 4, 6, 1, 5, 3, 4, 8};
    // printVector(A);
    // your code goes here
    sort(A);
    cout << "sorted vector: ";
    printVector(A);

    return 0;
}

// 2 Merge sort
#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++, k++;
        }
        else
        {
            arr[k] = b[j];
            k++, j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++, i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++, j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}
int main()
{
    int arr[] = {5, 4, 3, 61, 7, 1};
    mergeSort(arr, 0, 5);
    cout << "The sorted Array is:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}