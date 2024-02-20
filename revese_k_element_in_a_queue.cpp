#include <iostream>
#include <queue>
using namespace std;

void insertAtBottom(queue<int> &q, int x)
{
    if (q.empty())
    {
        q.push(x);
        return;
    }
    int a = q.front();
    q.pop();
    insertAtBottom(q, x);
    q.push(a);
}

void reverseFirstK(queue<int> &q, int k)
{
    if (k <= 0 || q.empty())
        return;
    int x = q.front();
    q.pop();
    reverseFirstK(q, k - 1);
    insertAtBottom(q, x);
}

queue<int> reverseKelements(queue<int> &q, int k)
{
    // Reverse the first k elements
    reverseFirstK(q, k);
    // Move the first (size-k) elements to the back to maintain original order after the first k
    int size = q.size();
    for (int i = 0; i < size - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

void print(queue<int> &q)
{
    queue<int> temp = q; // Use a temporary queue to avoid modifying the original queue
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    cout << "Original queue: ";
    print(q);
    cout << endl;

    reverseKelements(q, 3);
    cout << "After reversing first 3 elements: ";
    print(q);
}