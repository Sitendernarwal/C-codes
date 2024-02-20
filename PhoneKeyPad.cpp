#include <iostream>
#include <vector>
using namespace std;
vector<string> mapping = {" ", " ", "ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX", "YZ"};
void KeypadPemutations(vector<int> digits, vector<string> &ans, string output, int index)
{
    if (index >= digits.size())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index];
    string str = mapping[number];
    for (int i = 0; i < str.length(); i++)
    {
        output.push_back(str[i]);
        KeypadPemutations(digits, ans, output, index + 1);
        output.pop_back();
    }
}
int main()
{
    vector<int> digits = {2, 3};
    vector<string> ans;
    KeypadPemutations(digits, ans, "", 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}