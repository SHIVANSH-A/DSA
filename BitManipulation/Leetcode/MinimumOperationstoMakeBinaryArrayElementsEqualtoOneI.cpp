// You are given a binary array nums.

// You can do the following operation on the array any number of times (possibly zero):

// Choose any 3 consecutive elements from the array and flip all of them.
// Flipping an element means changing its value from 0 to 1, and from 1 to 0.

// Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0, 1, 0};
    Solution sol;
    cout << sol.minOperations(nums) << endl;
    return 0;
}
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int j = 0;
        int length = nums.size();
        // int sum = 0;
        int count = 0;

        while (j <= length - 3)
        {
            if (nums[j] == 0)
            {
                // nums[j] ^= 1;
                nums[j + 1] = 1 - nums[j + 1];
                nums[j + 2] = 1 - nums[j + 2];
                count++;
            }
            // sum++;
            j++;
        }

        return ((nums[length - 1] & nums[length - 2] == 1) ? count : -1);
    }
};