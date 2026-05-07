// You are given an integer array nums.

// From any index i, you can jump to another index j under the following rules:

// Jump to index j where j > i is allowed only if nums[j] < nums[i].
// Jump to index j where j < i is allowed only if nums[j] > nums[i].
// For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

// Return an array ans where ans[i] is the maximum value reachable starting from index i.

// Example 1:

// Input: nums = [2,1,3]

// Output: [2,2,3]

// Explanation:

// For i = 0: No jump increases the value.
// For i = 1: Jump to j = 0 as nums[j] = 2 is greater than nums[i].
// For i = 2: Since nums[2] = 3 is the maximum value in nums, no jump increases the value.
// Thus, ans = [2, 2, 3].

// Example 2:

// Input: nums = [2,3,1]

// Output: [3,3,3]

// Explanation:

// For i = 0: Jump forward to j = 2 as nums[j] = 1 is less than nums[i] = 2, then from i = 2 jump to j = 1 as nums[j] = 3 is greater than nums[2].
// For i = 1: Since nums[1] = 3 is the maximum value in nums, no jump increases the value.
// For i = 2: Jump to j = 1 as nums[j] = 3 is greater than nums[2] = 1.
// Thus, ans = [3, 3, 3].
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maxValue(vector<int> &nums)
    {

        int n = nums.size();

        // maxLeft[i]
        // stores maximum element from index 0 to i
        //
        // Example:
        // nums = [3,1,5,2]
        //
        // maxLeft = [3,3,5,5]
        vector<int> maxLeft(n);

        // minRight[i]
        // stores minimum element from index i to n-1
        //
        // Example:
        // nums = [3,1,5,2]
        //
        // minRight = [1,1,2,2]
        vector<int> minRight(n);

        // first element itself is maximum till index 0
        maxLeft[0] = nums[0];

        // last element itself is minimum from last index
        minRight[n - 1] = nums[n - 1];

        // BUILD PREFIX MAX ARRAY
        //
        // maxLeft[i] =
        // maximum value from 0 to i
        //
        // We compare current number with previous maximum
        for (int i = 1; i < n; i++)
        {

            maxLeft[i] = max(nums[i], maxLeft[i - 1]);
        }

        // BUILD SUFFIX MIN ARRAY
        //
        // minRight[i] =
        // minimum value from i to n-1
        //
        // We compare current number with next minimum
        for (int i = n - 2; i >= 0; i--)
        {

            minRight[i] = min(nums[i], minRight[i + 1]);
        }

        // result array
        vector<int> r(n);

        // last answer is always maximum till last index
        r[n - 1] = maxLeft[n - 1];

        // MAIN LOGIC
        //
        // We check partition:
        //
        // [0 ... i] | [i+1 ... n-1]
        //
        // Condition:
        //
        // largest element on LEFT
        // <=
        // smallest element on RIGHT
        //
        // maxLeft[i]
        // gives largest element on LEFT
        //
        // minRight[i+1]
        // gives smallest element on RIGHT
        //
        // If condition true:
        // answer becomes maxLeft[i]
        //
        // Else:
        // take next valid answer from right side
        for (int i = n - 2; i >= 0; i--)
        {

            // valid partition possible
            if (maxLeft[i] <= minRight[i + 1])
            {

                r[i] = maxLeft[i];
            }

            // partition not valid
            else
            {

                // use next valid answer
                r[i] = r[i + 1];
            }
        }

        return r;
    }
};

int main()
{

    Solution s;

    // sample input
    vector<int> nums = {5, 1, 3, 8, 6};

    vector<int> ans = s.maxValue(nums);

    cout << "Result Array:\n";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}