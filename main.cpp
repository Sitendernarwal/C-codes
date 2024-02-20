#include <iostream>
using namespace std;
void perm(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string newstr = str.substr(0, i) + str.substr(i + 1);
        perm(newstr, ans + ch);
    }
}
int main()
{
    string ans = "";
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        ans.push_back('0');
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            if (ans[j - 1] == '1')
                ans[j - 1] = '0';
            else
                ans[j - 1] = '1';
        }
    }
    cout << ans << endl;
    return 0;
}