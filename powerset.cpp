#include <iostream>
#include <vector>
using namespace std;
void powerSet(string str, string ans)
{
    if (str.length() == 0)
    {
        if (ans.length() != 0)
            cout << ans << " ";
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        string newstr = str.substr(0, i) + str.substr(i + 1);
        powerSet(newstr, ans + str[i]);
    }
}
int main()
{
    powerSet("A*B", "");
    return 0;
}