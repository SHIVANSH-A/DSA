// There is a dungeon with n x m rooms arranged as a grid.

// You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

// Return the minimum time to reach the room (n - 1, m - 1).

// Two rooms are adjacent if they share a common wall, either horizontally or vertically.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution
{
public:
    // Similar to 3341. Find Minimum Time to Reach Last Room I
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        return dijkstra(moveTime, {0, 0},
                        {moveTime.size() - 1, moveTime[0].size() - 1});
    }

private:
    int dijkstra(const vector<vector<int>> &moveTime, const pair<int, int> &src,
                 const pair<int, int> &dst)
    {
        constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int m = moveTime.size();
        const int n = moveTime[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        using T = pair<int, pair<int, int>>; // (d, (ux, uy))
        priority_queue<T, vector<T>, greater<>> minHeap;
        minHeap.push({dist[0][0], src});

        while (!minHeap.empty())
        {
            const auto [d, u] = minHeap.top();
            minHeap.pop();
            if (u == dst)
                return d;
            const auto [i, j] = u;
            if (d > dist[i][j])
                continue;
            for (const auto &[dx, dy] : kDirs)
            {
                const int x = i + dx;
                const int y = j + dy;
                if (x < 0 || x == m || y < 0 || y == n)
                    continue;
                const int newDist = max(moveTime[x][y], d) + ((i + j) % 2 + 1);
                if (newDist < dist[x][y])
                {
                    dist[x][y] = newDist;
                    minHeap.push({newDist, {x, y}});
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> moveTime = {
        {0, 2, 1},
        {4, 3, 2},
        {1, 1, 0}};

    Solution sol;
    int result = sol.minTimeToReach(moveTime);
    cout << "Minimum time to reach last room: " << result << endl;
    return 0;
}
