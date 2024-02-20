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
    node()
    {
        this->next = nullptr;
        this->data = 0;
    }
};
node *reverse_by_recursion(node *head)
{
    if (head == nullptr || head->next == NULL)
        return head;

    node *newhead = reverse_by_recursion(head->next);
    head->next = NULL;
    node *temp = newhead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    return newhead;
}
int main()
{
    node *head = new node(1);
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9};
    node *temp = head;
    for (int i = 0; i < 8; i++)
    {
        node *newnode = new node(arr[i]);
        temp->next = newnode;
        temp = temp->next;
    }
    head = reverse_by_recursion(head);
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}