#include <iostream>
#include <vector>
#include <queue>
// #include <vector>
#include <algorithm>

using namespace std;

int aggressiveCows(std::vector<int> &stalls, int k)
{
    std::sort(stalls.begin(), stalls.end());
    int left = 1;                                      // Minimum distance between two cows
    int right = stalls[stalls.size() - 1] - stalls[0]; // Maximum distance between two cows
    int maxDist = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cows = 1;
        int prev = stalls[0];

        for (int i = 1; i < stalls.size(); ++i)
        {
            if (stalls[i] - prev >= mid)
            {
                cows++;
                prev = stalls[i];
            }
        }

        if (cows >= k)
        {
            maxDist = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return maxDist;
}

int minDaysToInfect(vector<vector<int>> &city)
{
    int rows = city.size();
    int cols = city[0].size();

    queue<pair<int, int>> infected;

    // Push all initially infected houses to the queue
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (city[i][j] == 2)
            {
                infected.push({i, j});
            }
        }
    }

    int days = 0;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!infected.empty())
    {
        int size = infected.size();

        for (int i = 0; i < size; ++i)
        {
            int x = infected.front().first;
            int y = infected.front().second;
            infected.pop();

            for (auto &dir : directions)
            {
                int nx = x + dir[0];
                int ny = y + dir[1];

                // Check if the next position is valid and can be infected
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && city[nx][ny] == 1)
                {
                    city[nx][ny] = 2;        // Mark the house as infected
                    infected.push({nx, ny}); // Push the newly infected house to the queue
                }
            }
        }

        if (!infected.empty())
        {
            ++days;
        }
    }

    // Check if all houses are infected
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (city[i][j] == 1)
            {
                return -1; // There are still non-infected houses, so it's impossible
            }
        }
    }

    return days;
}

int main()
{
    int N, M;
    cout << "Enter the number of rows (N): ";
    cin >> N;

    cout << "Enter the number of columns (M): ";
    cin >> M;

    vector<vector<int>> city(N, vector<int>(M, 0));

    cout << "Enter the city matrix (0 for empty, 1 for non-infected, 2 for infected):\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> city[i][j];
        }
    }

    int result = minDaysToInfect(city);

    if (result == -1)
    {
        cout << "It's impossible to infect all houses.\n";
    }
    else
    {
        cout << "Minimum number of days to infect all houses: " << result << endl;
    }

    return 0;
}
