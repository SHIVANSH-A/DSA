// A sequence x1, x2, ..., xn is Fibonacci-like if:

// n >= 3
// xi + xi+1 == xi+2 for all i + 2 <= n
// Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

// A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        const int n = arr.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        unordered_map<int, int> numToIndex;

        for (int i = 0; i < n; ++i)
            numToIndex[arr[i]] = i;

        for (int j = 0; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
            {
                const int ai = arr[k] - arr[j];
                if (ai < arr[j] && numToIndex.contains(ai))
                {
                    const int i = numToIndex[ai];
                    dp[j][k] = dp[i][j] + 1;
                    ans = max(ans, dp[j][k]);
                }
            }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int result = solution.lenLongestFibSubseq(arr);
    cout << "Length of Longest Fibonacci-like Subsequence: " << result << endl;
    return 0;
}
