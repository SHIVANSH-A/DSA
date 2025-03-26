// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

// A uni-value grid is a grid where all the elements of it are equal.

// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
// We are sorting and taking the median and taking element at that index as target

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> v;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int r = 0;
        int target = v[v.size() / 2];
        for (int i : v)
        {
            if ((abs(target - i) % x) != 0)
                return -1;
            r += abs(target - i) / x;
        }
        return r;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    int x = 2;

    int result = sol.minOperations(grid, x);
    cout << "Minimum operations: " << result << endl;

    return 0;
}
