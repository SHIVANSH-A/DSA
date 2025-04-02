// You are given a 0-indexed integer array nums.

// Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

// The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long m = 0;
        int n = nums.size();
        long long diff = 0;
        long long max_i = 0;

        for (int num : nums)
        {
            m = max(m, diff * num);
            diff = max(diff, max_i - num);
            long long t = num;
            max_i = max(max_i, t);
        }

        return m;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 5, 2, 8, 1};
    cout << "Maximum Triplet Value: " << sol.maximumTripletValue(nums) << endl;
    return 0;
}