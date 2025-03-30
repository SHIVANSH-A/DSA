// An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

// You are given a 0-indexed integer array nums of length n with one dominant element.

// You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

// 0 <= i < n - 1
// nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
// Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

// Return the minimum index of a valid split. If no valid split exists, return -1.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 2, 3, 2, 2}; // Example input
    int result = sol.minimumIndex(nums);
    cout << "Minimum index: " << result << endl;
    return 0;
}
class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        int dominant = -1, totalCount = 0;
        int key, value;
        for (auto &[key, value] : freq)
        {
            if (value * 2 > n)
            {
                dominant = key;
                totalCount = value;
                break;
            }
        }

        if (dominant == -1)
            return -1;

        int prefixCount = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == dominant)
            {
                prefixCount++;
            }
            int suffixCount = totalCount - prefixCount;

            if (prefixCount * 2 > (i + 1) && suffixCount * 2 > (n - i - 1))
            {
                return i;
            }
        }

        return -1;
    }
};
