// You are given an array nums consisting of positive integers.

// We call a subarray of an array complete if the following condition is satisfied:

// The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
// Return the number of complete subarrays.

// A subarray is a contiguous non-empty part of an array.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        set<int> freq;
        unordered_map<int, int> mpp;

        // Count distinct elements
        for (int i = 0; i < n; i++)
        {
            freq.insert(nums[i]);
        }

        int c = freq.size(); // total unique elements
        int i = 0, j = 0, res = 0;

        while (j < n)
        {
            mpp[nums[j]]++;

            while (mpp.size() == c)
            {
                res += n - j;
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0)
                    mpp.erase(nums[i]);
                i++;
            }

            j++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 1, 3};

    int result = sol.countCompleteSubarrays(nums);
    cout << "Number of complete subarrays: " << result << endl;

    return 0;
}
