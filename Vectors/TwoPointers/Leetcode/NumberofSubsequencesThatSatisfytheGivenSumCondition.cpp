// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)
// Example 2:

// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
// Example 3:

// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
// Number of valid subsequences (63 - 2 = 61).
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= target <= 106

// Intuition -  1)Sort the array
//              2)Take two pointer i=0,j-n-1
//              3)Traverse the array
//              4)if(a[i]+a[j]<=target) r+=pow(2,l-r);i++ else j--
//              Precompute power of 2 to reduce complexity


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long M = 1e9 + 7;  // Modulo to prevent integer overflow

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> power(n);

        // Precompute powers of 2 modulo M
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % M;
        }

        sort(nums.begin(), nums.end());  // Sort the array for two-pointer approach
        int i = 0, j = n - 1;
        int r = 0;

        while (i <= j) {
            // If the sum of the smallest and largest is within the target
            if (nums[i] + nums[j] <= target) {
                // Count the number of subsequences between i and j
                r = (r + power[j - i]) % M;
                i++;
            } else {
                // If the pair exceeds the target, try smaller max
                j--;
            }
        }
        return r;
    }
};

// Main function to test the above logic
int main() {
    Solution sol;
    
    // Example test case
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    int result = sol.numSubseq(nums, target);
    cout << "Number of valid subsequences: " << result << endl;

    return 0;
}
