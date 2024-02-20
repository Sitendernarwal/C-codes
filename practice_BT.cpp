#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *BuildTree(int array[], int &i)
{
    if (array[i] == -1)
    {
        return NULL;
    }

    node *newnode = new node(array[i]);
    newnode->left = BuildTree(array, ++i);
    newnode->right = BuildTree(array, ++i);
    return newnode;
}
void inOrder(node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void LevelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        if (node == NULL)
        {
            cout << endl;
            // cout << " ";
            if (q.empty())
                return;
            else
                q.push(nullptr);
        }
        else
        {
            cout << " " << node->data;
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }
}

int height(node *root)
{
    if (root == nullptr)
        return 0;

    int right = height(root->right);
    int left = height(root->left);

    return max(left, right) + 1;
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->right);
    int op2 = diameter(root->left);
    int h = height(root->left) + height(root->right) + 1;

    return max(h, max(op1, op2));
}
pair<int, int> fast_diameter(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = fast_diameter(root->left);
    pair<int, int> right = fast_diameter(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
bool isBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    bool op1 = isBalanced(root->left);
    bool op2 = isBalanced(root->right);
    bool op3 = abs(height(root->left) - height(root->right)) <= 1;

    if (op1 && op2 && op3)
    {
        return true;
    }
    return false;
}
int main()
{
    int array[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int i = 0;
    node *root = BuildTree(array, i);
    inOrder(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;
    cout << height(root) << endl;
    cout << diameter(root) << endl;
    pair<int, int> ans = fast_diameter(root);
    cout << ans.first << endl;
    return 0;
}