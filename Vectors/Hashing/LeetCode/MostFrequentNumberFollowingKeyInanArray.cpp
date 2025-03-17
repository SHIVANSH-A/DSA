// You are given a 0-indexed integer array nums. You are also given an integer key, which is present in nums.

// For every unique integer target in nums, count the number of times target immediately follows an occurrence of key in nums. In other words, count the number of indices i such that:

// 0 <= i <= nums.length - 2,
// nums[i] == key and,
// nums[i + 1] == target.
// Return the target with the maximum count. The test cases will be generated such that the target with maximum count is unique.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        unordered_map<int, int> mpp;
        int m_count = 0;
        int m;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == key)
            {
                mpp[nums[i + 1]]++;
            }
            if (mpp[nums[i + 1]] > m_count)
            {
                m = nums[i + 1];
                m_count = mpp[nums[i + 1]];
            }
        }
        return m;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 100, 200, 1, 100};
    int key = 1;
    cout << sol.mostFrequent(nums, key) << endl;
    return 0;
}
