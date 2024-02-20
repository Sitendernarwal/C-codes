#include <iostream>
using namespace std;
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < pivot)
            count++;
    }
    int pivotIndex = count + start;
    swap(arr[start], arr[pivotIndex]);
    int i = start;
    int j = end;
    while (i < j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int start, int end)
{

    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}
int main()
{
    int arr[] = {4, 9, 1, 8, 2, 6, 7, 3, 5};
    quickSort(arr, 0, 8);
    for (int i = 0; i <= 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}