// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

// Return the maximum difference. If no such i and j exists, return -1.

// Example 1:

// Input: nums = [7,1,5,4]
// Output: 4
// Explanation:
// The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
// Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
// Example 2:

// Input: nums = [9,4,3,2]
// Output: -1
// Explanation:
// There is no i and j such that i < j and nums[i] < nums[j].
// Example 3:

// Input: nums = [1,5,2,10]
// Output: 9
// Explanation:
// The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

// Constraints:

// n == nums.length
// 2 <= n <= 1000
// 1 <= nums[i] <= 109
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int diff = INT_MIN;
        int min_ele = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > min_ele)
                diff = max(diff, nums[i] - min_ele);
            else
                min_ele = nums[i];
        }

        return (diff <= 0) ? -1 : diff;
    }
};
// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {
//         int diff=INT_MIN;
//         for(int i=0;i<nums.size()-1;i++){
//             for(int j=i+1;j<nums.size();j++)
//                 diff = max(diff,nums[j]-nums[i]);
//         }

//         return (diff<=0)?-1:diff;
//     }
// };
int main()
{
    Solution sol;

    // Example input
    vector<int> nums = {9, 4, 3, 2};

    int result = sol.maximumDifference(nums);

    cout << "Maximum Difference: " << result << endl;

    return 0;
}
