// You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

// For each queries[i]:

// Select a subset of indices within the range [li, ri] in nums.
// Decrement the values at the selected indices by 1.
// A Zero Array is an array where all elements are equal to 0.

// Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

// Example 1:

// Input: nums = [1,0,1], queries = [[0,2]]

// Output: true

// Explanation:

// For i = 0:
// Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
// The array will become [0, 0, 0], which is a Zero Array.
// Example 2:

// Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]

// Output: false

// Explanation:

// For i = 0:
// Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
// The array will become [4, 2, 1, 0].
// For i = 1:
// Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
// The array will become [3, 1, 0, 0], which is not a Zero Array.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> diff(n, 0);

        for (auto &i : queries)
        {
            int l = i[0];
            int r = i[1];
            diff[l] -= 1;
            if (r + 1 < n)
                diff[r + 1] += 1;
        }

        int cum = 0;
        for (int i = 0; i < n; i++)
        {
            cum += diff[i];
            if (nums[i] + cum > 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {1, 1, 1, 1};
    vector<vector<int>> queries = {
        {0, 3} // Subtract 1 from indices 0 to 3
    };

    bool result = sol.isZeroArray(nums, queries);
    cout << (result ? "YES" : "NO") << endl; // Output: YES

    return 0;
}
