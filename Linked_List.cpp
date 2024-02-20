#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class linkedList
{
public:
    void print(node *head)
    {
        node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }

    void insert(int position, int data, node *&head)
    {
        node *temp = new node(data);
        if (position == 1)
        {
            temp->next = head;
            head = temp;
            return;
        }

        node *cur = head;
        for (int i = 1; i < position - 1; i++)
        {
            if (cur == nullptr)
            {
                return;
            }
            cur = cur->next;
        }

        temp->next = cur->next;
        cur->next = temp;
    }

    void delete_data(int data, node *&head)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->data == data)
        {
            head = nullptr;
            return;
        }
        else if (head->next->data == data)
        {
            node *temp = head->next;
            head->next = temp->next;
            delete temp;
            return;
        }
        node *prev = head;
        node *tobedelted = head->next;
        while (tobedelted->data != data && tobedelted != nullptr)
        {
            tobedelted = tobedelted->next;
            prev = prev->next;
        }
        if (tobedelted != nullptr)
        {
            node *temp = tobedelted;
            prev->next = tobedelted->next;
            delete temp;
        }
        else
        {
            return;
        }
    }
};

int main()
{
    // making linked list
    node *head = new node(1);
    linkedList list;
    list.insert(1, 10, head);
    list.insert(3, 19, head);
    list.delete_data(19, head);
    list.print(head);
}