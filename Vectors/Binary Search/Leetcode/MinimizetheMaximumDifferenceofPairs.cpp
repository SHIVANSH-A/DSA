// You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

// Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

 

// Example 1:

// Input: nums = [10,1,2,7,1,3], p = 2
// Output: 1
// Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
// The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
// Example 2:

// Input: nums = [4,2,1,2], p = 1
// Output: 0
// Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109
// 0 <= p <= (nums.length)/2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Check if we can form at least 'p' pairs with max difference <= mid
    bool isValid(vector<int>& nums, int p, int mid) {
        int n = nums.size();
        int i = 0;
        int count = 0;
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= mid) {
                count++;
                i += 2; // skip the next one to ensure non-overlapping
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums), end(nums));  // Sort for adjacent pairing

        int l = 0;
        int r = nums[n - 1] - nums[0]; // Max possible diff
        int ans = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isValid(nums, p, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {1, 3, 6, 19};
    int p = 1;

    int result = sol.minimizeMax(nums, p);
    cout << "Minimum maximum difference for " << p << " pairs is: " << result << endl;

    return 0;
}
