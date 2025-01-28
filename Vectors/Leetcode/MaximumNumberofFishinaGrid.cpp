// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:

// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int ans = 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] > 0)
                    ans = max(ans, dfs(grid, i, j));

        return ans;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
            return 0;
        if (grid[i][j] == 0)
            return 0;
        int caughtFish = grid[i][j];
        grid[i][j] = 0;
        return caughtFish +
               dfs(grid, i + 1, j) + dfs(grid, i - 1, j) +
               dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 2, 3},
        {4, 0, 5},
        {1, 6, 0}};

    Solution solution;
    int maxFish = solution.findMaxFish(grid);

    cout << "Maximum fish that can be caught: " << maxFish << endl;

    return 0;
}
