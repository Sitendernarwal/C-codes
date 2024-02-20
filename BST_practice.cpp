#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data = 0)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
bool isPresent(node *root, int value)
{
    if (root == NULL)
        return false;

    bool ans;
    if (root->data == value)
        return true;
    else if (root->data > value)
    {
        ans = isPresent(root->left, value);
    }
    else
    {
        ans = isPresent(root->right, value);
    }
    return ans;
}
node *insert(int value, node *root)
{
    if (root == NULL)
    {
        root = new node(value);
        return root;
    }

    if (root->data > value)
    {
        root->left = insert(value, root->left);
    }
    else
    {
        root->right = insert(value, root->right);
    }
    return root;
}

int min_val(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return min_val(root->left);
    }
}
node *delete_node(node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {
        // no child nodes
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // one child node
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // two child nodes

        if (root->right != NULL && root->left != NULL)
        {
            int min = min_val(root->right);
            root->data = min;
            root->right = delete_node(root->right, min);
            return root;
        }
    }
    else if (root->data > value)
    {
        root->left = delete_node(root->left, value);
        return root;
    }
    else
    {
        root->right = delete_node(root->right, value);
        return root;
    }
}

void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            cout << endl;
            if (q.empty())
            {
                break;
            }
            else
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    int arr[] = {7, 1, 4, 19, 3, 10, 2, 8, 9, 5, 6};
    node *root = NULL;
    for (int i = 0; i < 11; i++)
    {
        root = insert(arr[i], root);
    }

    root = delete_node(root, 6);
    levelOrder(root);
    if (isPresent(root, 6))
    {
        cout << "Value is present: " << endl;
    }
    return 0;
}