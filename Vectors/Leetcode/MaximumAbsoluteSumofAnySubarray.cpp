// You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

// Return the maximum absolute sum of any (possibly empty) subarray of nums.

// Note that abs(x) is defined as follows:

// If x is a negative integer, then abs(x) = -x.
// If x is a non-negative integer, then abs(x) = x.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int ans = INT_MIN;
        int maxSum = 0;
        int minSum = 0;

        for (const int num : nums)
        {
            maxSum = max(num, maxSum + num);
            minSum = min(num, minSum + num);
            ans = max({ans, maxSum, -minSum});
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, -3, 2, 3, -4}; // Example input
    cout << "Maximum Absolute Sum of Any Subarray: " << solution.maxAbsoluteSum(nums) << endl;
    return 0;
}