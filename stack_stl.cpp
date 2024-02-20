#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(2);
    cout << st.top() << endl;
    st.push(3);
    cout << st.top() << endl;
    st.push(4);
    cout << st.top() << endl;
    st.push(5);
    cout << st.top() << endl;
    st.push(6);
    cout << st.top() << endl;
    st.push(7);
    cout << st.top() << endl;
    return 0;
}