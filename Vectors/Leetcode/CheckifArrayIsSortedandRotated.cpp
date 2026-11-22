// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Intuition: In a sorted rotated array, numbers can decrease only once when we check them in a circular manner (last element compared with first).
// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int peak = 0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]>nums[(i+1)%n]) peak++;
//         }
//         return (peak==1 || peak==0);
//     }
// };Sol1
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        bool flag = true;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                reverse(nums.begin(), nums.end());
                reverse(nums.begin(), nums.begin() + (nums.size() - (i + 1)));
                reverse(nums.begin() + (nums.size() - (i + 1)), nums.end());
                break;
            }
        }

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> testCases = {
        {3, 4, 5, 1, 2},
        {2, 1, 3, 4},
        {1, 2, 3, 4, 5},
        {5, 6, 7, 8, 9, 1, 2, 3},
        {1, 1, 1, 1}};

    for (auto &testCase : testCases)
    {
        cout << "Array: ";
        for (int num : testCase)
            cout << num << " ";
        cout << "=> " << (solution.check(testCase) ? "True" : "False") << endl;
    }

    return 0;
}
