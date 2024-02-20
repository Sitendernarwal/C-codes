#include <iostream>
using namespace std;
class stack
{
    int *arr;
    int size;
    int arrsize;

public:
    stack(int n)
    {
        arr = new int[2];
        size = 1;
        arr[0] = n;
        arrsize = 2;
    }

    void push(int n)
    {
        if (size >= arrsize)
        {
            int *arr2 = new int[2 * arrsize];
            for (int i = 0; i < arrsize; i++)
            {
                arr2[i] = arr[i];
            }
            delete arr;
            arr = new int[2 * arrsize];
            for (int i = 0; i < arrsize; i++)
            {
                arr[i] = arr2[i];
            }
            delete arr2;
            arrsize *= 2;
        }
        arr[size] = n;
        size++;
    }

    void pop()
    {
        if (size > 0)
            size--;
    }
    int top()
    {
        if (size > 0)
        {
            return arr[size - 1];
        }
        else
        {
            return -1;
        }
    }

    bool empty()
    {
        return size == 0;
    }
};
int main()
{
    stack st(2);
    st.push(3);
    st.push(9);
    cout << st.top();
    return 0;
}
