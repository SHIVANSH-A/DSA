// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

// Example 1:

// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:

// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:

// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.

// Constraints:

// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> r(m, vector<int>(n, INT_MAX));

        auto isValid = [&](int x, int y)
        {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        r[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            int diff = pq.top().first;
            auto ele = pq.top().second;
            int x = ele.first;
            int y = ele.second;
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return diff;

            for (auto dir : directions)
            {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isValid(x_, y_))
                {
                    int abs_diff = abs(heights[x][y] - heights[x_][y_]);
                    int max_diff = max(diff, abs_diff);

                    if (max_diff < r[x_][y_])
                    {
                        r[x_][y_] = max_diff;
                        pq.push({max_diff, {x_, y_}});
                    }
                }
            }
        }

        return r[m - 1][n - 1];
    }
};

// Test the implementation
int main()
{
    Solution sol;

    vector<vector<int>> heights1 = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}};

    vector<vector<int>> heights2 = {
        {1, 2, 3},
        {3, 8, 4},
        {5, 3, 5}};

    cout << "Minimum Effort Path (Test 1): " << sol.minimumEffortPath(heights1) << endl;
    cout << "Minimum Effort Path (Test 2): " << sol.minimumEffortPath(heights2) << endl;

    return 0;
}
