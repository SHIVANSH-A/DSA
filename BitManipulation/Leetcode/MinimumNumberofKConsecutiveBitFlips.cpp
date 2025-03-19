// You are given a binary array nums and an integer k.

// A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

// Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

// A subarray is a contiguous part of an array.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0, 1, 0};
    int k = 2;
    Solution sol;
    cout << sol.minKBitFlips(nums, k) << endl;
    return 0;
}
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        int flip = 0;

        vector<int> isFlipped(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (i >= k)
            {
                flip ^= isFlipped[i - k];
            }
            if ((nums[i] ^ flip) == 0)
            {
                if (i + k > n)
                    return -1;
                flip ^= 1;
                isFlipped[i] = 1;
                count++;
            }
        }

        return count;
    }
};
