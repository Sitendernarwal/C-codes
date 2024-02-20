#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>> &maze, vector<vector<int>> &visited, int n, int x, int y)
{
  return ((x < n && y < n) && (x >= 0 && y >= 0) && visited[x][y] == 0 && maze[x][y] == 1);
}
void solve(vector<vector<int>> &maze, vector<vector<int>> &visited, int n, int x, int y, string &output, vector<string> &ans)
{
  if (x == n - 1 && y == n - 1)
  {
    ans.push_back(output);
    return;
  }

  visited[x][y] = 1;

  // up
  int newx = x - 1;
  int newy = y;
  if (isSafe(maze, visited, n, newx, newy))
  {
    output.push_back('U');
    solve(maze, visited, n, newx, newy, output, ans);
    output.pop_back();
  }
  newx = x + 1;
  newy = y;
  if (isSafe(maze, visited, n, newx, newy))
  {
    output.push_back('D');
    solve(maze, visited, n, newx, newy, output, ans);
    output.pop_back();
  }
  newx = x;
  newy = y - 1;
  if (isSafe(maze, visited, n, newx, newy))
  {
    output.push_back('L');
    solve(maze, visited, n, newx, newy, output, ans);
    output.pop_back();
  }

  newx = x;
  newy = y + 1;
  if (isSafe(maze, visited, n, newx, newy))
  {
    output.push_back('R');
    solve(maze, visited, n, newx, newy, output, ans);
    output.pop_back();
  }
  visited[x][y] = 0;
}
void solve_maze(vector<vector<int>> &maze, vector<string> &ans, int n)
{
  if (n <= 1)
  {
    return;
  }
  vector<vector<int>> visited(n, vector<int>(n, 0));
  string output = "";
  solve(maze, visited, n, 0, 0, output, ans);
}
int main()
{
  vector<string> ans;
  vector<vector<int>> maze = {{1, 0, 0, 0},
                              {1, 1, 0, 0},
                              {0, 1, 0, 0},
                              {0, 1, 1, 1}};

  solve_maze(maze, ans, 4);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}