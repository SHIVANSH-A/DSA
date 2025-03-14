// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most vali.
// The amount by which each value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.

// Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int q;
    bool DiffArrayTec(vector<int> nums, vector<vector<int>> queries, int k)
    {
        vector<int> diff(n, 0);
        for (int i = 0; i <= k; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if (r + 1 < n)
                diff[r + 1] -= x;
        }

        int csum = 0;
        for (int i = 0; i < n; i++)
        {
            csum += diff[i];
            diff[i] = csum;

            if (nums[i] - diff[i] > 0)
            {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        n = nums.size();
        q = queries.size();

        auto lambda = [](int x)
        {
            return x == 0;
        };

        if (all_of(nums.begin(), nums.end(), lambda))
        {
            return 0;
        }

        int l = 0;
        int r = q - 1;
        int k = -1;

        while (r >= l)
        {
            int mid = l + (r - l) / 2;
            if (DiffArrayTec(nums, queries, mid) == true)
            {
                k = mid + 1;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return k;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 9};
    vector<vector<int>> queries = {{0, 1, 3}, {1, 2, 2}, {0, 2, 1}};
    cout << sol.minZeroArray(nums, queries) << endl;
    return 0;
}
