// You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

// Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

// Example 1:

// Input: m = 1, n = 1
// Output: 3
// Explanation: The three possible colorings are shown in the image above.
// Example 2:

// Input: m = 1, n = 2
// Output: 6
// Explanation: The six possible colorings are shown in the image above.
// Example 3:

// Input: m = 5, n = 5
// Output: 580986

// Constraints:

// 1 <= m <= 5
// 1 <= n <= 1000

// Make all possible combinations of R,G,B of max length m(as m can be max 5) then iterate over combinations and fill columns.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int M = 1e9 + 7;
    vector<string> states;
    vector<vector<int>> t;

    // Generate valid coloring states for one column
    void generateColStates(string curr, char prev, int l, int m)
    {
        if (l == m)
        {
            states.push_back(curr);
            return;
        }
        for (char ch : {'R', 'G', 'B'})
        {
            if (ch == prev)
                continue;
            generateColStates(curr + ch, ch, l + 1, m);
        }
    }

    // Count ways recursively with memoization
    int solve(int prevIdx, int rem, int m)
    {
        if (rem == 0)
            return 1;
        if (t[rem][prevIdx] != -1)
            return t[rem][prevIdx];

        int ways = 0;
        string prevState = states[prevIdx];
        for (int i = 0; i < states.size(); i++)
        {
            if (i == prevIdx)
                continue;
            string curr = states[i];
            bool valid = true;
            for (int j = 0; j < m; j++)
            {
                if (curr[j] == prevState[j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ways = (ways + solve(i, rem - 1, m)) % M;
        }
        return t[rem][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n)
    {
        states.clear();
        generateColStates("", '!', 0, m); // Generate valid single-column colorings
        int res = 0;
        int totalStates = states.size();
        t = vector<vector<int>>(n, vector<int>(totalStates, -1));

        for (int i = 0; i < totalStates; i++)
        {
            res = (res + solve(i, n - 1, m)) % M;
        }

        return res;
    }
};

// Entry point
int main()
{
    Solution sol;

    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    int result = sol.colorTheGrid(m, n);
    cout << "Number of ways to color the grid: " << result << endl;

    return 0;
}
