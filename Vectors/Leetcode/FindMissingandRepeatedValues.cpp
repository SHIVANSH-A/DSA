// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Solution solution;
    vector<vector<int>> grid = {{1, 3}, {2, 2}};

    vector<int> result = solution.findMissingAndRepeatedValues(grid);
    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        const int nSquared = n * n;
        vector<int> count(nSquared + 1);

        for (const vector<int> &row : grid)
            for (const int num : row)
                ++count[num];

        int repeated = -1;
        int missing = -1;

        for (int i = 1; i <= nSquared; ++i)
        {
            if (count[i] == 2)
                repeated = i;
            if (count[i] == 0)
                missing = i;
        }

        return {repeated, missing};
    }
};