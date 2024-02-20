#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &maze, int n, vector<vector<int>> &visited, int x, int y)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && maze[x][y] == 1)
        return true;
    else
        return false;
}

void solve(vector<vector<int>> &maze, int n, vector<string> &ans, string path, int x, int y, vector<vector<int>> &visited)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // UP
    int newx = x - 1;
    int newy = y;
    if (isSafe(maze, n, visited, newx, newy))
    {
        path.push_back('U');
        solve(maze, n, ans, path, newx, newy, visited);
        path.pop_back();
    }

    // DOWN
    newx = x + 1;
    newy = y;
    if (isSafe(maze, n, visited, newx, newy))
    {
        path.push_back('D');
        solve(maze, n, ans, path, newx, newy, visited);
        path.pop_back();
    }

    // RIGHT
    newx = x;
    newy = y + 1;
    if (isSafe(maze, n, visited, newx, newy))
    {
        path.push_back('R');
        solve(maze, n, ans, path, newx, newy, visited);
        path.pop_back();
    }

    // LEFT
    newx = x;
    newy = y - 1;
    if (isSafe(maze, n, visited, newx, newy))
    {
        path.push_back('L');
        solve(maze, n, ans, path, newx, newy, visited);
        path.pop_back();
    }

    visited[x][y] = 0;
}

void mazePaths(vector<vector<int>> &maze, int n, vector<string> &ans)
{
    if (maze[0][0] == 0)
    {
        return;
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(maze, n, ans, path, 0, 0, visited);
    return;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {1, 0, 1, 1}};

    vector<string> ans;
    mazePaths(maze, 4, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }
    cout << endl;
}
