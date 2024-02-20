#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
int main()
{
    std::unordered_set<int> set;
    set.insert(1);
    set.insert(89);
    set.insert(8);
    set.insert(9);
    set.insert(809);
    set.insert(10);
    for (const auto &elemnet : set)
    {
        cout << elemnet << " ";
    }
    return 0;
}