// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

 

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.
// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.
 

// Constraints:

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

// Idea
// If cost.size() == n, then:

// There are n stairs (0-indexed: 0 to n-1)

// The top of the floor is considered to be after the last stair

// So, the top is at index n

// To reach step n, you must have come from:

// Step n-1 (+1 step)

// OR step n-2 (+2 steps)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(int n, vector<int> &dp, vector<int> &cost) {
        if (n <= 1) return cost[n];

        if (dp[n] != -1) return dp[n];

        int left = f(n - 1, dp, cost);
        int right = f(n - 2, dp, cost);

        return dp[n] = cost[n] + min(left, right);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        // We can reach the top from the last or second-last step
        return min(f(n - 1, dp, cost), f(n - 2, dp, cost));
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to reach the top: " << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
