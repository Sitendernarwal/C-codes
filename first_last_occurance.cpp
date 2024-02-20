#include <iostream>
using namespace std;

int firstoc(int arr[], int size, int key)
{
    int si = 0;
    int ei = size - 1;
    int mid;
    int ans = -1;
    while (si <= ei)
    {
        mid = si + (ei - si) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            ei = mid - 1;
        }
        else if (arr[mid] > key)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }
    return ans;
}

int lastoc(int arr[], int size, int key)
{
    int si = 0;
    int ei = size - 1;
    int mid;
    int ans = -1;
    while (si <= ei)
    {
        mid = si + (ei - si) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            si = mid + 1;
        }
        else if (arr[mid] > key)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }
    return ans;
}

pair<int, int> p(int arr[], int size, int key)
{
    pair<int, int> result;
    result.first = firstoc(arr, size, key);
    result.second = lastoc(arr, size, key);
    return result;
}

int main()
{
    int arr[11] = {1, 2, 2, 2, 2, 2, 3, 4, 5, 6, 7};
    int first = firstoc(arr, 11, 2);
    cout << first << endl
         << endl;
    pair<int, int> result = p(arr, 11, 2);
    cout << result.first << " " << result.second << endl;
    return 0;
}
