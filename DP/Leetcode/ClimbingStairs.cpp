// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// Constraints:

// 1 <= n <= 45

// Approach - Think it of as you are at last stair (index n) now either you can take one step or two step.
//         Now , if you take one step it will generate left subtree of recursion and for two step right subtree.
//         All ways will be sum of them.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int left = f(n - 1, dp);  // Taking 1 step
        int right = f(n - 2, dp); // Taking 2 step

        return dp[n] = left + right;
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};

int main()
{
    Solution sol;
    int n = 4;
    cout << "Number of ways to climb " << n << " stairs: " << sol.climbStairs(n) << endl;
    return 0;
}
