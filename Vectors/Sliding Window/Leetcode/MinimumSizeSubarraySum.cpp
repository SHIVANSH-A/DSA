// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0;
        int minLen = INT_MAX;
        int n = nums.size();
        
        while (j < n) {
            sum += nums[j];

            while (sum >= target) {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

int main() {
    int target;
    cout << "Enter target sum: ";
    cin >> target;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.minSubArrayLen(target, nums);
    cout << "Minimum subarray length with sum ≥ " << target << " is: " << result << endl;

    return 0;
}
