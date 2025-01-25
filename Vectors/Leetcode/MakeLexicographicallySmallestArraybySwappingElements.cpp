// You are given a 0-indexed array of positive integers nums and a positive integer limit.

// In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

// Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

// An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j)
             { return nums[i] < nums[j]; });
        vector<int> ans(n);
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit)
            {
                ++j;
            }
            vector<int> t(idx.begin() + i, idx.begin() + j);
            sort(t.begin(), t.end());
            for (int k = i; k < j; ++k)
            {
                ans[t[k - i]] = nums[idx[k]];
            }
            i = j;
        }
        return ans;
    }
};
int main()
{
    Solution solution;

    // Input array and limit
    vector<int> nums = {8, 5, 3, 7, 2};
    int limit = 3;

    // Call the function
    vector<int> result = solution.lexicographicallySmallestArray(nums, limit);

    // Output the result
    cout << "Lexicographically smallest array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
