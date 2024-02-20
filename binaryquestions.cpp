#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node()
    {
        this->data = 0;
        this->right = nullptr;
        this->left = nullptr;
    }
};

node *BuildTree(int nodes[], int &indx)
{
    if (nodes[indx] == -1)
    {
        return nullptr;
    }
    node *newnode = new node;
    newnode->data = nodes[indx];
    newnode->left = BuildTree(nodes, ++indx);
    newnode->right = BuildTree(nodes, ++indx);
    return newnode;
}

void traverseLeft(node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary_traversal(node *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> ans;
    ans.push_back(root->data);
    // traverse left subtree

    traverseLeft(root->left, ans);

    // traverse leaf

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);

    // traverse right subtree

    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    int nodes[] = {8, 1, 2, 5, 2, -1, -1, 9, -1, -1, -1, -1, -1};
    int indx = 0;
    node *root = BuildTree(nodes, indx);
    vector<int> boundary;
    boundary = boundary_traversal(root);

    for (int i = 0; i < boundary.size(); i++)
    {
        cout << boundary[i] << " ";
    }
    cout << endl;
    return 0;
}