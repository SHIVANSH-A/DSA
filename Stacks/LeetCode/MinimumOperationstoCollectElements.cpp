// You are given an array nums of positive integers and an integer k.

// In one operation, you can remove the last element of the array and add it to your collection.

// Return the minimum number of operations needed to collect elements 1, 2, ..., k.

// Example 1:

// Input: nums = [3,1,5,4,2], k = 2
// Output: 4
// Explanation: After 4 operations, we collect elements 2, 4, 5, and 1, in this order. Our collection contains elements 1 and 2. Hence, the answer is 4.
#include <iostream>
#include <vector>
#include <algorithm> // For std::find

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int opr = 0;
        int target = k;
        int i = nums.size() - 1;
        vector<int> v;
        while (target > 0)
        {
            if (nums[i] <= k && find(v.begin(), v.end(), nums[i]) == v.end())
            {
                v.push_back(nums[i]);
                opr++;
                target--;
            }
            else
            {
                opr++;
            }
            i--;
        }
        return opr;
    }
};

int main()
{
    // Test case
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int k = 5;

    Solution solution;
    int result = solution.minOperations(nums, k);

    cout << "Minimum operations to satisfy the condition: " << result << endl;

    return 0;
}
