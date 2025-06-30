// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

// Example 1:

// Input: nums = [1,3,2,2,5,2,3,7]

// Output: 5

// Explanation:

// The longest harmonious subsequence is [3,2,2,2,3].

// Example 2:

// Input: nums = [1,2,3,4]

// Output: 2

// Explanation:

// The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

// Example 3:

// Input: nums = [1,1,1,1]

// Output: 0

// Explanation:

// No harmonic subsequence exists.

// Constraints:

// 1 <= nums.length <= 2 * 104
// -109 <= nums[i] <= 109

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// class Solution {
// public:
//     int findLHS(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> freq;
//         int len = 0;
//         for(int i=0;i<n;i++){
//             freq[nums[i]]++;
//         }
//         for(int i=0;i<n;i++){
//             if(freq.count(nums[i]+1)) len = max(len,freq[nums[i]]+freq[nums[i]+1]);//count -O(n)
//         }
//         return len;
//     }
// };

// class Solution {
// public:
//     int findLHS(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> freq;
//         int len = 0;
//         for(int i=0;i<n;i++){
//             freq[nums[i]]++;
//         }
//         sort(begin(nums),end(nums));
//         for(int i=0;i<n;i++){
//             int f = freq[nums[i]+1];
//             if(f!=0) len = max(len,f+freq[nums[i]]);
//         }
//         return len;
//     }
// };

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int left = 0, maxLen = 0;
        int n = nums.size();

        for (int right = 0; right < n; ++right)
        {
            // shrink the window if the condition breaks
            while (nums[right] - nums[left] > 1)
            {
                left++;
            }

            // check if it’s a valid LHS window
            if (nums[right] - nums[left] == 1)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};

    int result = sol.findLHS(nums);
    cout << "Longest Harmonious Subsequence Length: " << result << endl;

    return 0;
}
