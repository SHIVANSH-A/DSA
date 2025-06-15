// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
// Example 2:

// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

// Constraints:

// 1 <= nums.length <= 2 * 104
// 1 <= nums[i], k <= nums.length
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int FindKsub(vector<int> &nums, int k)
    {
        int r = 0;
        int i = 0, j = 0;
        unordered_map<int, int> mpp;
        int n = nums.size();

        while (j < n)
        {
            mpp[nums[j]]++;

            while (mpp.size() > k)
            {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)
                    mpp.erase(nums[i]);
                i++;
            }

            r += j - i + 1;
            j++;
        }

        return r;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return FindKsub(nums, k) - FindKsub(nums, k - 1);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    int result = sol.subarraysWithKDistinct(nums, k);
    cout << "Number of subarrays with exactly " << k << " distinct elements: " << result << endl;

    return 0;
}
