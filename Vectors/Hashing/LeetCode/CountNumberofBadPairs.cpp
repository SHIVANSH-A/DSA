// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

// Return the total number of bad pairs in nums.
// If any relation like i and value at i -> try to simplify
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] - i;
        }
        long long count = 0;
        mpp[nums[0]]++;
        for (int i = 1; i < n; i++)
        {
            count += i - mpp[nums[i]];
            mpp[nums[i]]++;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 1, 3, 3};
    cout << "Count of bad pairs: " << sol.countBadPairs(nums) << endl;
    return 0;
}
