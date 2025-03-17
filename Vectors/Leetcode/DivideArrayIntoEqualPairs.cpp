// You are given an integer array nums consisting of 2 * n integers.

// You need to divide nums into n pairs such that:

// Each element belongs to exactly one pair.
// The elements present in a pair are equal.
// Return true if nums can be divided into n pairs, otherwise return false.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    Solution solution;
    vector<int> nums = {3, 2, 3, 2, 2, 2};
    cout << (solution.divideArray(nums) ? "true" : "false") << endl;
    return 0;
}
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        vector<int> v(501, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            v[nums[i]]++;
        }

        int req_pairs = nums.size() / 2;
        int count = 0;

        for (int i = 0; i < v.size(); i++)
        {
            count += v[i] / 2;
        }

        return count == req_pairs;
    }
};
