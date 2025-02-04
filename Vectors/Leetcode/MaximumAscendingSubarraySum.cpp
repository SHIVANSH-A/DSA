// Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

// A subarray is defined as a contiguous sequence of numbers in an array.

// A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int max_sum = nums[0];
        int curr_sum = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                curr_sum += nums[i + 1];
            }
            else
            {
                max_sum = max(max_sum, curr_sum);
                curr_sum = nums[i + 1];
            }
        }
        max_sum = max(curr_sum, max_sum);
        return max_sum;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {10, 20, 30, 5, 10, 50};
    cout << "Max Ascending Sum: " << solution.maxAscendingSum(nums) << endl;
    return 0;
}
