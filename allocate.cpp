// #include <bits/stdc++.h>
// #include <vector>
// bool isPossible(vector<int> &pages, int n, int b, int mid)
// {

//     int page = 0;
//     int students = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (page + pages[i] <= mid)
//         {
//             page += pages[i];
//         }
//         else
//         {
//             students++;
//             if (students > b || pages[i] > mid)
//             {
//                 return false;
//             }
//             page = pages[i];
//         }
//     }
//     return true;
// }
// int allocateBooks(vector<int> &pages, int n, int b)
// {
//     if (n < b)
//     {
//         return -1;
//     }
//     // Write your code here.
//     int si = 0;
//     int ei = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ei += pages[i];
//     }
//     int mid = si + (ei - si) / 2;
//     int ans = -1;
//     while (si <= ei)
//     {
//         if (isPossible(pages, n, b, mid))
//         {
//             ans = mid;
//             ei = mid - 1;
//         }
//         else
//         {
//             si = mid + 1;
//         }
//         mid = si + (ei - si) / 2;
//     }
//     return ans;
// }

// #include <vector>

// int ans(int n, int dp[])
// {
//     if (n <= 1)
//     {
//         return n;
//     }
//     if (dp[n] != 0)
//     {
//         return dp[n];
//     }
//     int a = ans(n - 1, dp) + ans(n - 2, dp);
//     dp[n] = a % (1000000007);
//     return a % (1000000007);
// }
// int fibonacciNumber(int n)
// {
//     int dp[n + 1] = {0};

//     int answer = (ans(n, dp));
//     return answer;
// }

// #include <vector>
// #include <climits>

// long long maxSubarraySum(std::vector<int> arr, int n)
// {
//     long long maxEndingHere = arr[0];
//     long long maxSoFar = arr[0];

//     for (int i = 1; i < n; i++)
//     {
//         maxEndingHere = std::max(static_cast<long long>(arr[i]), maxEndingHere + arr[i]);
//         maxSoFar = std::max(maxSoFar, maxEndingHere);
//     }
//     if (maxSoFar <= 0)
//     {
//         maxSoFar = 0;
//     }

//     return maxSoFar;
// }

// int *getProductArrayExceptSelf(int *arr, int n)
// {
//     // Write your code here
//     int *ans = (int *)malloc(n * sizeof(int));

//     for (int i = 0; i < n; i++)
//     {
//         int a = 1;
//         for (int j = 0; j < n; j++)
//         {
//             if (j != i)
//             {
//                 a = (a * arr[j]) % 1000000007;
//             }
//         }
//         ans[i] = a;
//     }

//     return ans;
// }

// #include <vector>
// #include <algorithm>
// using namespace std;
// std::vector<std::pair<int, int>> twoSum(std::vector<int> &arr, int target, int n)
// {
//     // Write your code here.
//     if (arr.size() < 2)
//     {
//         return {{-1, -1}}; // Return an empty vector, as there are no pairs to consider
//     }
//     std::sort(arr.begin(), arr.end());
//     std::vector<std::pair<int, int>> ans;

//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             // std::pair<int, int> temp;
//             std::pair<int, int> temp;
//             if (arr[i] + arr[j] == target)
//             {
//                 temp.first = arr[i];
//                 temp.second = arr[j];
//                 ans.push_back(temp);
//                 arr[j] = 100000;
//                 break;
//             }
//         }
//     }
//     if (ans.size() == 0)
//     {
//         return {{-1, -1}};
//     }
//     return ans;
// }

// #include <bits/stdc++.h>

// std::vector<int> Klargest(std::vector<int> &a, int k, int n)
// {
//     // Write your code here
//     std::sort(a.begin(), a.end());
//     std::vector<int> ans;
//     int curint = a[n - 1];
//     ans.push_back(curint);
//     int count = 1;

//     for (int i = n - 2; i >= 0 && count < k; i--)
//     {

//         count++;
//         ans.push_back(a[i]);
//     }

//     std::sort(ans.begin(), ans.end());
//     return ans;
// }

// #include <bits/stdc++.h>
// int magicIndex(vector<int> a, int n)
// {
//     // Write your code here
//     int si = 0;
//     int ei = n - 1;
//     int mid = si + (ei - si) / 2;
//     int ans = -1;
//     while (si <= ei)
//     {
//         if (a[mid] == mid)
//         {
//             ans = mid;
//             return mid;
//         }
//         else if (mid > a[mid])
//         {
//             si = mid + 1;
//         }
//         else
//         {
//             ei = mid - 1;
//         }
//         mid = si + (ei - si) / 2;
//     }

//     return ans;
// }

#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n)
{
    stack<int> st;             // Ek stack banate hain jo indices store karega
    vector<int> result(n, -1); // Result vector ko initialize karte hain, -1 se

    for (int i = 0; i < n; i++)
    {
        // Jab tak stack khali nahi hai aur current element, stack ke top par ke element se bada hai
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            // Current element, stack ke top par ke element ka next greater element hai
            result[st.top()] = arr[i];
            st.pop(); // Top element ko pop karte hain
        }
        st.push(i); // Current element ki index ko stack mein daal dete hain
    }

    return result; // Result vector ko return karte hain
}
