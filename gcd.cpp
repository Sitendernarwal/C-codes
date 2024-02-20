#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0 || a == b)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    int x = a > b ? a : b;
    int y = a < b ? a : b;
    while (y != 0)
    {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}
int main()
{
    cout << gcd(43, 86);
    return 0;
}