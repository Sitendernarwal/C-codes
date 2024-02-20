#include <iostream>
using namespace std;
int findroot(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int si = 0;
    int ei = n;
    int mid = si + (ei - si) / 2;
    while (si < ei)
    {
        if (mid * mid <= n && (mid + 1) * (mid + 1) > n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            ei = mid;
        }
        else
        {
            si = mid + 1;
        }
        mid = si + (ei - si) / 2;
    }
    return 1;
}
float moreprecise(int n, int pricesision, int number)
{
    float factor = 1;
    float ans = n;
    for (int i = 0; i < pricesision; i++)
    {
        factor /= 10;
        for (int j = ans; j * j < number; j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int x = findroot(n);
    float prans = moreprecise(x, 3, n);
    cout << x << " " << prans << endl;
}