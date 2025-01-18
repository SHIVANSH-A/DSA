// Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

// 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
// 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
// 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
// 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
// Notice that there could be some signs on the cells of the grid that point outside the grid.

// You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

// You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

// Return the minimum cost to make the grid have at least one valid path.

// Example 1:

// Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
// Output: 3
// Explanation: You will start at point (0, 0).
// The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
// The total cost = 3.
// Example 2:

// Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
// Output: 0
// Explanation: You can follow the path from (0, 0) to (2, 2).
// Example 3:

// Input: grid = [[1,2],[4,3]]
// Output: 1
class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();

        // Initialize a 2D vector to keep track of visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Define directions according to the grid value (1: right, 2: left, 3: down, 4: up)
        vector<vector<int>> directions = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Queue to perform the BFS, holding pairs of (cell_index, current_cost)
        deque<pair<int, int>> queue;
        queue.push_back({0, 0}); // Start from the top-left corner with 0 cost

        // While there are elements in the queue
        while (!queue.empty())
        {
            // Get the front element
            auto current = queue.front();
            queue.pop_front();

            // Calculate row and column from the cell index
            int row = current.first / cols, col = current.first % cols;
            int cost = current.second;

            // If we've reached the bottom-right corner, return the current cost
            if (row == rows - 1 && col == cols - 1)
                return cost;

            // If the current cell is already visited, skip it
            if (visited[row][col])
                continue;

            // Mark the current cell as visited
            visited[row][col] = true;

            // Check all four adjacent cells
            for (int k = 1; k <= 4; ++k)
            {
                int newRow = row + directions[k][0], newCol = col + directions[k][1];

                // If the new cell is within the grid bounds
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
                {
                    // Calculate the new cell index
                    int newIndex = newRow * cols + newCol;

                    // If the grid indicates the current direction, add to the front of the queue without increasing cost
                    if (grid[row][col] == k)
                        queue.push_front({newIndex, cost});
                    // Otherwise, the direction is not towards the grid arrow - increase the cost and add to the back of the queue
                    else
                        queue.push_back({newIndex, cost + 1});
                }
            }
        }

        // Return -1 if the bottom-right corner could not be reached
        return -1;
    }
};