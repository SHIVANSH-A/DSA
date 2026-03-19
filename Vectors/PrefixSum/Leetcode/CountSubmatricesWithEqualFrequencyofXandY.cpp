// Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:

// grid[0][0]
// an equal frequency of 'X' and 'Y'.
// at least one 'X'.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        vector<vector<int>> cumSumX(r, vector<int>(c, 0));
        vector<vector<int>> cumSumY(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cumSumX[i][j] = (grid[i][j] == 'X');
                cumSumY[i][j] = (grid[i][j] == 'Y');

                if (i - 1 >= 0)
                {
                    cumSumX[i][j] += cumSumX[i - 1][j];
                    cumSumY[i][j] += cumSumY[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    cumSumX[i][j] += cumSumX[i][j - 1];
                    cumSumY[i][j] += cumSumY[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    cumSumX[i][j] -= cumSumX[i - 1][j - 1];
                    cumSumY[i][j] -= cumSumY[i - 1][j - 1];
                }

                if (cumSumX[i][j] == cumSumY[i][j] && cumSumX[i][j] > 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));

    // Input grid
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int result = obj.numberOfSubmatrices(grid);

    cout << result << endl;

    return 0;
}