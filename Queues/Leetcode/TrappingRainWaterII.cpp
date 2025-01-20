// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

// Example 1:

// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<PP, vector<PP>, greater<>> boundrycells; // MinHeap {h, {i, j}}
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Pushing boundary elements to the heap and marking them visited
        for (int row = 0; row < m; row++)
        {
            for (int col : {0, n - 1})
            {
                boundrycells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        for (int col = 0; col < n; col++)
        {
            for (int row : {0, m - 1})
            {
                boundrycells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;
        while (!boundrycells.empty())
        {
            PP p = boundrycells.top();
            boundrycells.pop();

            int h = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for (vector<int> dir : dir)
            {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_])
                {
                    water += max((h - heightMap[i_][j_]), 0);                 // Trapped water
                    boundrycells.push({max(h, heightMap[i_][j_]), {i_, j_}}); // Updated height
                    visited[i_][j_] = true;
                }
            }
        }

        return water;
    }
};

int main()
{
    // Sample height map
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};

    // Create Solution object
    Solution solution;

    // Compute trapped water
    int result = solution.trapRainWater(heightMap);

    // Output the result
    cout << "Trapped Water: " << result << endl;

    return 0;
}
