#include <iostream>

int countWays(int n)
{
    int count = 0;
    int start = 1, end = 1;
    int sum = 1;

    while (start <= n / 2)
    {
        if (sum < n)
        {
            end++;
            sum += end;
        }
        else if (sum > n)
        {
            sum -= start;
            start++;
        }
        else
        {
            // Found a valid sequence
            count++;
            sum -= start;
            start++;
        }
    }

    return count;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    int result = countWays(n);

    std::cout << "Number of ways to express " << n << " as the sum of consecutive positive integers: " << result << std::endl;

    return 0;
}
