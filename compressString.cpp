#include <iostream>
#include <vector>
struct Node
{
    int data;
    struct Node *next;
};
using namespace std;
vector<Node *> interconnectLL(Node *head1, Node *head2)
{
    Node *cur1 = head1;
    Node *cur2 = head2;
    while (cur1->next != nullptr && cur2->next != nullptr)
    {
        Node *temp1 = cur1->next;
        Node *temp2 = cur2->next;
        cur1->next = temp2;
        cur2->next = temp1;
        cur1 = temp1;
        cur2 = temp2;
    }
    while (cur1->next != nullptr)
    {
        cur2->next = cur1->next;
        cur1->next = cur2->next;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    while (cur2->next != nullptr)
    {
        cur1->next = cur2->next;
        cur2->next = cur1->next;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    vector<Node *> ans;
    ans.push_back(head1);
    ans.push_back(head2);
    return ans;
}
int main()
{
}