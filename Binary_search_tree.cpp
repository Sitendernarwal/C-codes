#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree
{
};

node *insert(node *root, int value)
{
    if (root == nullptr)
    {
        root = new node(value);
        return root;
    }

    if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void inOrder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

node *inOrderSuccessor(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
bool search(node *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data > key)
    {
        return search(root->left, key);
    }
    else if (root->data == key)
    {
        return true;
    }
    else
    {
        return search(root->right, key);
    }
}

node *delete_node(node *root, int data_of_node)
{
    if (root->data > data_of_node)
    {
        root->left = delete_node(root->left, data_of_node);
    }
    else if (root->data < data_of_node)
    {
        root->right = delete_node(root->right, data_of_node);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        if (root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *IS = inOrderSuccessor(root->right);
        root->data = IS->data;
        root->right = delete_node(root->right, IS->data);
    }

    return root;
}

int main()
{
    int arr[] = {5, 1, 3, 4, 6, 2, 7};
    node *root = nullptr;
    for (int i = 0; i < 7; i++)
    {
        root = insert(root, arr[i]);
    }
    inOrder(root);
    cout << endl;
    root = delete_node(root, 2);
    inOrder(root);
    cout << endl;
    return 0;
}