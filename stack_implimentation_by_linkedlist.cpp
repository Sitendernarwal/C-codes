#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

class Stack
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    Stack(int n)
    {
        head = new Node(n);
        tail = head;
        size = 1;
    }

    void push(int n)
    {
        if (head == NULL)
        {
            // Stack is empty, create the first node
            Node *temp = new Node(n);
            head = temp;
            tail = head;
            size = 1;
        }
        else
        {
            // Add a new node to the end of the stack
            Node *temp = new Node(n);
            tail->next = temp;
            tail = temp;
            size += 1;
        }
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Error: Stack is empty!!!" << endl;
            return;
        }
        if (head->next == NULL)
        {
            // Stack has only one element, make it empty
            head = NULL;
            tail = head;
            size = 0;
        }
        else
        {
            // Traverse to the second last node and remove the last node
            Node *cur = head;
            while (cur->next != tail)
            {
                cur = cur->next;
            }
            Node *temp = cur->next;
            cur->next = NULL;
            delete temp;
            tail = cur;
            size--;
        }
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Error: Stack is empty!!!" << endl;
            return -1; // Assuming -1 as an error indicator; you can choose your own convention
        }
        return tail->data;
    }

    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    Stack st(2);
    st.push(3);
    st.push(9);
    st.pop();
    cout << st.top();
    return 0;
}
