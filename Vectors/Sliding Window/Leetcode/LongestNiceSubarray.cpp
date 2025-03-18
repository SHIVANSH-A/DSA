// You are given an array nums consisting of positive integers.

// We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

// Return the length of the longest nice subarray.

// A subarray is a contiguous part of an array.

// Note that subarrays of length 1 are always considered nice.

// NOTE - 1) Shrinking in this type of questions(AND/OR) Take XOR
//    2) If pairs for AND has to be formed use OR so that all the ones can be aggregated
#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 8, 48, 10}; // Sample test case
    cout << "Longest Nice Subarray Length: " << sol.longestNiceSubarray(nums) << endl;
    return 0;
}

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int length = 1;
        int i = 0;
        int j = 0;
        int curr = 0;

        while (j < nums.size())
        {
            while ((curr & nums[j]) != 0)
            {
                curr = (curr ^ nums[i]); // It will take out nums[i] from curr
                i++;
            }
            length = max(length, j - i + 1);
            curr |= nums[j];
            j++;
        }
        return length;
        int length = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if ((curr & nums[j]) != 0)
                    break;
                length = max(length, j - i + 1);
                curr |= nums[j];
            }
        }
        return length;
    }
};
