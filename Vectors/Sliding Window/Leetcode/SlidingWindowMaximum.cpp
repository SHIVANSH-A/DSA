// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 0, j = 0;
        priority_queue<pair<int, int>> q;
        vector<int> r;

        while (j < n)
        {
            // Push current element with its index
            q.push({arr[j], j});

            // If window size is reached
            if (j - i + 1 == k)
            {
                // Remove stale elements (whose index is out of the window)
                while (!q.empty() && q.top().second < i)
                {
                    q.pop();
                }

                // Push the max element from the window to result
                if (!q.empty())
                {
                    r.push_back(q.top().first);
                }

                // Slide the window
                i++;
            }

            j++;
        }

        return r;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(arr, k);

    cout << "Sliding window maximums are: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
