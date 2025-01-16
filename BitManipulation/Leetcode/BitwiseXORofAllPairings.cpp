// You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

// Return the bitwise XOR of all integers in nums3.
// brute force
// class Solution {
// public:
//     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> c;
//         for(int i=0;i<nums1.size();i++){
//             for(int j=0;j<nums2.size();j++){
//                 c.push_back(nums1[i]^nums2[j]);
//             }
//         }
//         int r=0;
//         for(int i=0;i<c.size();i++){
//           r^=c[i];
//         }
//         return r;
//     }
// };
// IF a number appears odd number of time then it can be xor but it even then it will cancel out with its pair
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, long> mpp;
        for (int i = 0; i < nums1.size(); i++)
        {
            mpp[nums1[i]] += m;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            mpp[nums2[i]] += n;
        }
        int r = 0;
        for (auto i : mpp)
        {
            if (i.second % 2 != 0)
            {
                r ^= i.first;
            }
        }
        return r;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {6, 5};

    int result = sol.xorAllNums(nums1, nums2);
    cout << "Result: " << result << endl;

    return 0;
}
