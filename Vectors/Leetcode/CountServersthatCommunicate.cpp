// You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

// Return the number of servers that communicate with any other server
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowf(m, 0);
        vector<int> colf(n, 0);
        int noOfServers = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    rowf[i] += 1;
                    colf[j] += 1;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (rowf[i] > 1 || colf[j] > 1)
                    {
                        noOfServers++;
                    }
                }
            }
        }
        return noOfServers;
    }
};
int main()
{
    // Define the grid
    vector<vector<int>> grid = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 0, 1}};

    // Create an instance of the Solution class
    Solution solution;

    // Call the countServers function and store the result
    int result = solution.countServers(grid);

    // Print the result
    cout << "Number of servers that communicate: " << result << endl;

    return 0;
}
class SolutionTwo
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowalone(m, -1);
        vector<int> colf(n, 0);
        int noOfServers = 0;

        for (int i = 0; i < m; i++)
        {
            int rowServers = 0;
            int k = -1;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    rowServers++;
                    colf[j] += 1;
                    k = j;
                }
            }
            if (rowServers >= 2)
                noOfServers += rowServers;
            else
            {
                rowalone[i] = k;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (rowalone[i] != -1 && colf[rowalone[i]] > 1)
            {
                noOfServers++;
            }
        }

        return noOfServers;
    }
};