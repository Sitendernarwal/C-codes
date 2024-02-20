#include <iostream>
using namespace std;
int find(int arr[], int n)
{
    int si = 0;
    int ei = n - 1;
    int mid = si + (ei - si) / 2;
    while (si < ei)
    {
        if (arr[mid] > arr[0])
        {
            ei = mid;
        }
        else
        {
            si = mid + 1;
        }
        mid = si + (ei - si) / 2;
    }
    return si;
}
int main()
{
}