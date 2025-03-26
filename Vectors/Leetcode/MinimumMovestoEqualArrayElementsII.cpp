// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment or decrement an element of the array by 1.

// Test cases are designed so that the answer will fit in a 32-bit integer.

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};

    int result = sol.minMoves2(nums);
    cout << "Minimum moves: " << result << endl;

    return 0;
}
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int target = nums[nums.size() / 2];
        int r = 0;
        for (int i : nums)
        {
            if (i != target)
                r += abs(target - i);
        }

        return r;
    }
};