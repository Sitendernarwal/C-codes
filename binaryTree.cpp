#include <iostream>
#include <queue>
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
class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};
class BinaryTree
{
public:
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

    void preOrder(node *root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(node *root)
    {
        if (root == nullptr)
            return;

        preOrder(root->left);
        cout << root->data << " ";
        preOrder(root->right);
    }

    void postOrder(node *root)
    {
        if (root == nullptr)
            return;

        preOrder(root->left);
        preOrder(root->right);
        cout << root->data << " ";
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

    int countNodes(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int x = countNodes(root->left);
        int y = countNodes(root->right);
        return x + y + 1;
    }
    int sum_0f_Nodes(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int x = sum_0f_Nodes(root->left);
        int y = sum_0f_Nodes(root->right);
        return x + y + root->data;
    }

    int Height_of_Tree(node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int x = Height_of_Tree(root->left);
        int y = Height_of_Tree(root->right);
        return (x > y) ? (x + 1) : (y + 1);
    }

    int Diameter_of_Tree(node *root)
    {

        if (root == nullptr)
            return 0;
        int d1 = Diameter_of_Tree(root->left);
        int d2 = Diameter_of_Tree(root->right);
        int d3 = Height_of_Tree(root->left) + Height_of_Tree(root->right) + 1;
        return max(max(d1, d2), d3);
    }

    vector<int> zig_zag_tree(node *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<int> ans;
        queue<node *> q;
        q.push(root);

        bool Left_to_Right = true;
        while (!q.empty())
        {

            int size = q.size();
            vector<int> temp(size);
            for (int i = 0; i < size; i++)
            {
                node *tmp = q.front();
                q.pop();
                if (Left_to_Right)
                {
                    temp[i] = tmp->data;
                }
                else
                {
                    temp[size - i - 1] = tmp->data;
                }

                if (tmp->left)
                    q.push(tmp->left);

                if (tmp->right)
                    q.push(tmp->right);
            }
            for (int i = 0; i < temp.size(); i++)
            {
                ans.push_back(temp[i]);
            }
            Left_to_Right = !Left_to_Right;
        }
        return ans;
    }
    info solve(node *root, int &ans)
    {
        // base case
        if (root == NULL)
        {
            return {INT32_MAX, INT32_MIN, true, 0};
        }
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        info cur;
        cur.maxi = max(left.maxi, root->data);
        cur.mini = min(right.mini, root->data);
        cur.size = left.size + right.size + 1;
        if (left.isBST && right.isBST && (left.maxi < root->data && right.mini > root->data))
        {
            cur.isBST = true;
        }
        else
        {
            cur.isBST = false;
        }
        if (cur.isBST)
        {
            ans = max(ans, cur.size);
        }
        return cur;
    }
    int max_BST(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int max = 0;
        info temp = solve(root, max);
        return max;
    }
};

int main()
{
    int nodes[] = {8, 1, 2, 5, 2, -1, -1, 9, -1, -1, -1, -1, -1};
    BinaryTree tree;
    int indx = 0;
    node *root = tree.BuildTree(nodes, indx);
    vector<int> zig_zag;
    zig_zag = tree.zig_zag_tree(root);
    cout << "PreOrder way of traversal" << endl;
    tree.preOrder(root);
    cout << endl;
    cout << "InOrder way of traversal" << endl;
    tree.inOrder(root);
    cout << endl;
    cout << "PostOrder way of traversal" << endl;
    tree.postOrder(root);
    cout << endl;
    cout << "LevelOrder way of traversal" << endl;
    tree.levelOrder(root);
    cout << "Number of nodes is :" << tree.countNodes(root) << endl;
    cout << "The sum of the data of nodes :" << tree.sum_0f_Nodes(root) << endl;
    cout << "The height of the tree is :" << tree.Height_of_Tree(root) << endl;
    cout << "The Diameter of the tree is :" << tree.Diameter_of_Tree(root) << endl;
    for (int i = 0; i < zig_zag.size(); i++)
    {
        cout << zig_zag[i] << " ";
    }
    cout << endl;

    return 0;
}
