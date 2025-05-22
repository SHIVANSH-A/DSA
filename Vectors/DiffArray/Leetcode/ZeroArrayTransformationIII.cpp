// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most 1.
// The amount by which the value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.

// Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Min-heap of used queries' end indices
        priority_queue<int, vector<int>, greater<int>> past;

        // Max-heap of available queries' end indices
        priority_queue<int> maxHeap;

        // Sort queries by start index
        sort(queries.begin(), queries.end());

        int j = 0;              // Pointer to queries
        int usedCount = 0;      // Number of queries actually used

        for (int i = 0; i < n; ++i) {
            // Push all queries starting at index i into maxHeap
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);  // push only the end
                ++j;
            }

            // Apply effect of already-used queries
            nums[i] -= past.size();

            // Apply more queries if needed
            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int r = maxHeap.top(); maxHeap.pop();
                past.push(r);
                usedCount++;
                nums[i]--;
            }

            // If we can't reduce nums[i] to 0
            if (nums[i] > 0)
                return -1;

            // Remove expired queries
            while (!past.empty() && past.top() == i) {
                past.pop();
            }
        }

        return queries.size() - usedCount;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> nums = {2, 1, 1};
    vector<vector<int>> queries = {{0, 2}, {0, 0}, {1, 2}, {2, 2}};

    // Call function
    int result = sol.maxRemoval(nums, queries);

    // Output result
    cout << "Maximum number of unused queries: " << result << endl;

    return 0;
}
