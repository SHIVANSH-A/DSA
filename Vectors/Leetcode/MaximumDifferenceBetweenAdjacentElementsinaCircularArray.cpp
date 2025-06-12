// Given a circular array nums, find the maximum absolute difference between adjacent elements.

// Note: In a circular array, the first and last elements are adjacent.

// Example 1:

// Input: nums = [1,2,4]

// Output: 3

// Explanation:

// Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

// Example 2:

// Input: nums = [-5,-10,-5]

// Output: 5

// Explanation:

// The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int n = nums.size();
        int diff = abs(nums[0] - nums[n - 1]);

        for (int i = 0; i < n - 1; i++)
        {
            diff = max(diff, abs(nums[i] - nums[i + 1]));
        }

        return diff;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 7, 2, 9};

    int result = sol.maxAdjacentDistance(nums);
    cout << "Maximum adjacent distance: " << result << endl;

    return 0;
}
