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

int nodes[] = {8, 1, 2, 5, 2, -1, -1, 9, -1, -1, -1, -1, -1};
int indx = 0;
node *root = BuildTree(nodes, indx);